#pragma once

#include <atomic>
#include <memory>
#include <string>
#include <vector>

#include "Factory.h"
#include "interfaces/IBallisticSolver.h"
#include "interfaces/ITargetProvider.h"
#include "physics/DronePhysics.h"

struct SimStep
{
    Coord pos;
    float direction = 0.0f;
    int state = 0;
    int targetIdx = -1;
    Coord dropPoint;
    Coord aimPoint;
    Coord predictedTarget;
    float timeSecSinceStart = 0.0f;
};

class MissionProcessor
{
public:
    MissionProcessor(const DroneConfig& config, const AmmoParams& ammo,
                     ITargetProvider& provider, DronePhysics& physics,
                     std::unique_ptr<IBallisticSolver> solver);

    bool init();
    void run();
    void start();
    bool isThreadReady() const;
    bool writeResult(const std::string& outputPath) const;

private:
    void step();
    DroneMode chooseMode(const DroneTelemetry& telemetry, float desiredDirection, float distance) const;

    DroneConfig cfg_;
    AmmoParams ammo_;
    ITargetProvider& provider_;
    DronePhysics& physics_;
    std::unique_ptr<IBallisticSolver> solver_;
    std::unique_ptr<IDroneState> state_;
    BallisticSolution ballistic_;
    std::vector<SimStep> simSteps_;
    std::atomic<bool> ready_{false};
    std::atomic<bool> started_{false};
    bool finished_ = false;
};
