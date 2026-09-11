#include "mission/MissionProcessor.h"
#include "json.hpp"

#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <thread>

using json = nlohmann::json;

MissionProcessor::MissionProcessor(const DroneConfig& config, const AmmoParams& ammo,
                                   ITargetProvider& provider, DronePhysics& physics,
                                   std::unique_ptr<IBallisticSolver> solver)
    : cfg_(config), ammo_(ammo), provider_(provider), physics_(physics), solver_(std::move(solver)) {}

bool MissionProcessor::init()
{
    if (!solver_ || provider_.getTargetCount() == 0) return false;
    ballistic_ = solver_->solve({cfg_, ammo_});
    state_ = createState(StateType::StateStopped, cfg_, ammo_);
    simSteps_.clear();
    finished_ = false;
    return true;
}

void MissionProcessor::run()
{
    ready_.store(true);
    while (!started_.load()) std::this_thread::sleep_for(std::chrono::milliseconds(1));

    while (!finished_ && simSteps_.size() < MAX_STEPS)
    {
        step();
        std::this_thread::sleep_for(std::chrono::duration<float>(cfg_.simTimeStep / cfg_.timeScale));
    }
    writeResult("out/simulation.json");
}

void MissionProcessor::start() { started_.store(true); }
bool MissionProcessor::isThreadReady() const { return ready_.load(); }

DroneMode MissionProcessor::chooseMode(const DroneTelemetry& telemetry, float desiredDirection, float distance) const
{
    const float angleError = std::fabs(normalizeAngle(desiredDirection - telemetry.direction));
    const float scalarSpeed = telemetry.speed.length();
    if (distance <= cfg_.hitRadius) return DroneMode::Stopped;
    if (angleError > cfg_.turnThreshold) return DroneMode::Turning;
    if (scalarSpeed < cfg_.attackSpeed * 0.99f) return DroneMode::Accelerating;
    return DroneMode::Moving;
}

void MissionProcessor::step()
{
    const DroneTelemetry telemetry = physics_.getTelemetry();
    float bestTime = std::numeric_limits<float>::max();
    int bestTarget = -1;
    Coord bestPredicted{};
    Coord bestFirePoint{};

    for (int i = 0; i < provider_.getTargetCount(); ++i)
    {
        const Target target = provider_.getTarget(i);
        float travelTime = 0.0f;
        Coord predicted = target.pos;
        Coord firePoint{};

        for (int iteration = 0; iteration < NUM_TIME_APPROXIMATION_STEPS; ++iteration)
        {
            predicted = target.pos + target.velocity * (travelTime + ballistic_.flightTime);
            Coord intermediate{};
            bool hasIntermediate = false;
            getIntermediateAndDropPoint(telemetry.pos, predicted, ballistic_.hDistance,
                                        cfg_.accelPath, intermediate, firePoint, hasIntermediate);
            Coord positionCopy = telemetry.pos;
            travelTime = calcTimeOfFlight(positionCopy, hasIntermediate ? intermediate : firePoint,
                                          telemetry.direction, cfg_.turnThreshold, cfg_.angularSpeed,
                                          telemetry.speed.length(), cfg_.attackSpeed, cfg_.accelPath,
                                          hasIntermediate);
        }

        if (travelTime < bestTime)
        {
            bestTime = travelTime;
            bestTarget = i;
            bestPredicted = predicted;
            bestFirePoint = firePoint;
        }
    }

    if (bestTarget < 0) { finished_ = true; return; }

    const float desiredDirection = std::atan2(bestFirePoint.y - telemetry.pos.y,
                                               bestFirePoint.x - telemetry.pos.x);
    const float distance = (bestFirePoint - telemetry.pos).length();
    const DroneMode mode = chooseMode(telemetry, desiredDirection, distance);
    const float angleError = normalizeAngle(desiredDirection - telemetry.direction);
    const float signedAngularSpeed = std::copysign(cfg_.angularSpeed, angleError);

    switch (mode)
    {
        case DroneMode::Stopped: state_ = createState(StateType::StateStopped, cfg_, ammo_); break;
        case DroneMode::Accelerating: state_ = createState(StateType::StateAccelerating, cfg_, ammo_); break;
        case DroneMode::Decelerating: state_ = createState(StateType::StateDecelerating, cfg_, ammo_); break;
        case DroneMode::Turning: state_ = createState(StateType::StateTurning, cfg_, ammo_); break;
        case DroneMode::Moving: state_ = createState(StateType::StateMoving, cfg_, ammo_); break;
    }

    physics_.sendCommand({mode, mode == DroneMode::Turning ? signedAngularSpeed : 0.0f});
    simSteps_.push_back({telemetry.pos, telemetry.direction, static_cast<int>(telemetry.state),
                         bestTarget, bestFirePoint,
                         calcAimPoint(telemetry.pos, telemetry.direction, ballistic_.hDistance),
                         bestPredicted, telemetry.timeSecSinceStart});

    if (distance <= cfg_.hitRadius) finished_ = true;
}

bool MissionProcessor::writeResult(const std::string& outputPath) const
{
    std::filesystem::create_directories(std::filesystem::path(outputPath).parent_path());
    json out;
    out["totalSteps"] = simSteps_.size();
    out["steps"] = json::array();
    for (const SimStep& step : simSteps_)
    {
        out["steps"].push_back({
            {"position", {{"x", step.pos.x}, {"y", step.pos.y}}},
            {"direction", step.direction},
            {"state", step.state},
            {"targetIndex", step.targetIdx},
            {"dropPoint", {{"x", step.dropPoint.x}, {"y", step.dropPoint.y}}},
            {"aimPoint", {{"x", step.aimPoint.x}, {"y", step.aimPoint.y}}},
            {"predictedTarget", {{"x", step.predictedTarget.x}, {"y", step.predictedTarget.y}}},
            {"timeSecSinceStart", step.timeSecSinceStart}
        });
    }
    std::ofstream file(outputPath);
    if (!file) return false;
    file << out.dump(2);
    return true;
}
