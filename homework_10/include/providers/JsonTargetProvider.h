#pragma once

#include "interfaces/ITargetProvider.h"

#include <atomic>
#include <mutex>
#include <string>
#include <vector>

class JsonTargetProvider : public ITargetProvider
{
public:
    JsonTargetProvider(const std::string& targetsPath, float timeStep, float timeScale);
    bool load() override;
    void run() override;
    void start() override;
    void stop() override;
    bool isThreadReady() const override;
    int getTargetCount() const override;
    Target getTarget(int index) const override;

private:
    std::string targetsPath_;
    float timeStep_;
    float timeScale_;
    std::vector<std::vector<Coord>> trajectories_;
    std::vector<Target> targets_;
    std::vector<std::size_t> indices_;
    mutable std::mutex targetsMutex_;
    std::atomic<bool> ready_{false};
    std::atomic<bool> started_{false};
    std::atomic<bool> stopRequested_{false};
};
