#include "providers/JsonTargetProvider.h"
#include "json.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

using json = nlohmann::json;

JsonTargetProvider::JsonTargetProvider(const std::string& path, float timeStep, float timeScale)
    : targetsPath_(path), timeStep_(timeStep), timeScale_(timeScale) {}

bool JsonTargetProvider::load()
{
    std::ifstream file(targetsPath_);
    if (!file) return false;
    json data;
    try { file >> data; } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return false; }

    trajectories_.clear();
    for (const auto& item : data.at("targets"))
    {
        std::vector<Coord> trajectory;
        for (const auto& p : item.at("positions"))
            trajectory.push_back({p.at("x").get<float>(), p.at("y").get<float>()});
        if (trajectory.empty()) return false;
        trajectories_.push_back(std::move(trajectory));
    }

    targets_.resize(trajectories_.size());
    indices_.assign(trajectories_.size(), 0);
    for (std::size_t i = 0; i < trajectories_.size(); ++i)
    {
        const Coord current = trajectories_[i][0];
        const Coord next = trajectories_[i][trajectories_[i].size() > 1 ? 1 : 0];
        targets_[i] = {current, (next - current) / timeStep_};
    }
    return true;
}

void JsonTargetProvider::run()
{
    ready_.store(true);
    while (!started_.load() && !stopRequested_.load())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    while (!stopRequested_.load())
    {
        {
            std::lock_guard<std::mutex> lock(targetsMutex_);
            for (std::size_t i = 0; i < trajectories_.size(); ++i)
            {
                const std::size_t current = indices_[i];
                const std::size_t next = (current + 1) % trajectories_[i].size();
                targets_[i].pos = trajectories_[i][next];
                const std::size_t after = (next + 1) % trajectories_[i].size();
                targets_[i].velocity = (trajectories_[i][after] - trajectories_[i][next]) / timeStep_;
                indices_[i] = next;
            }
        }
        std::this_thread::sleep_for(std::chrono::duration<float>(timeStep_ / timeScale_));
    }
}

void JsonTargetProvider::start() { started_.store(true); }
void JsonTargetProvider::stop() { stopRequested_.store(true); }
bool JsonTargetProvider::isThreadReady() const { return ready_.load(); }
int JsonTargetProvider::getTargetCount() const { return static_cast<int>(targets_.size()); }
Target JsonTargetProvider::getTarget(int index) const
{
    std::lock_guard<std::mutex> lock(targetsMutex_);
    return targets_.at(static_cast<std::size_t>(index));
}
