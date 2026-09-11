#pragma once

#include "Factory.h"
#include "interfaces/IConfigLoader.h"
#include "interfaces/ITargetProvider.h"
#include "interfaces/IBallisticSolver.h"

#include "ballistics.hpp"

#include <memory>
#include <string>

#define ENABLE_LOG 1
#define ENABLE_DEBUG 1

#if ENABLE_LOG
#include <iostream>
#define LOG(msg) std::cout << "[LOG] " << msg << std::endl
#else
#define LOG(msg)
#endif

#if ENABLE_DEBUG
#include <iostream>
#define DEBUG(msg) std::cout << "[DEBUG] " << msg << std::endl
#else
#define DEBUG(msg)
#endif


struct SimStep
{
    Coord pos;
    float direction = 0.0f;         
    int state = 0;
    int targetIdx = -1;
    Coord dropPoint;
    Coord aimPoint;
    Coord predictedTarget;
};

class MissionProcessor
{
public:
    MissionProcessor(std::unique_ptr<IConfigLoader> loader, std::unique_ptr<ITargetProvider> provider, std::unique_ptr<IBallisticSolver> solver);

    bool init();
    bool hasNext() const;
    void step();
    void reset();
    void changeSolver(std::unique_ptr<IBallisticSolver> solver);
    bool writeResult(const std::string& outputPath) const;

private:
    Coord interpolateTarget(int targetIdx, float t) const;
    Coord extrapolateTarget(int targetIdx, float currentTime, float dt) const;

    std::unique_ptr<IConfigLoader> loader_;
    std::unique_ptr<ITargetProvider> provider_;
    std::unique_ptr<IBallisticSolver> solver_;
    std::unique_ptr<IDroneState> state_;

    DroneConfig cfg_;
    AmmoParams ammo_;
    BallisticSolution ballistic_;

    SimStep simSteps_[MAX_STEPS];

    float acceleration_ = 0.0f;
    float direction_ = 0.0f;
    float speed_ = 0.0f;
    float currentTime_ = 0.0f;

    Coord currentPos_;
    int currentTarget_ = -1;
    int stepIndex_ = 0;
    bool finished_ = false;
};
