#pragma once

#include "interfaces/IConfigLoader.h"
#include "interfaces/ITargetProvider.h"
#include "interfaces/IBallisticSolver.h"

#include "ballistics.hpp"

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

enum DroneState
{
    STOPPED = 0,
    ACCELERATING = 1,
    DECELERATING = 2,
    TURNING = 3,
    MOVING = 4
};

struct SimStep
{
    Coord pos;
    float direction = 0.0f;
    int state = STOPPED;
    int targetIdx = -1;
    Coord dropPoint;
    Coord aimPoint;
    Coord predictedTarget;
};

class MissionProcessor
{
public:
    MissionProcessor(IConfigLoader* loader, ITargetProvider* provider, IBallisticSolver* solver);

    bool init();
    bool hasNext() const;
    void step();
    void reset();
    void changeSolver(IBallisticSolver* solver);
    bool writeResult(const std::string& outputPath) const;

private:
    Coord interpolateTarget(int targetIdx, float t) const;
    Coord extrapolateTarget(int targetIdx, float currentTime, float dt) const;

    IConfigLoader* loader_ = nullptr;
    ITargetProvider* provider_ = nullptr;
    IBallisticSolver* solver_ = nullptr;

    DroneConfig cfg_;
    AmmoParams ammo_;
    BallisticSolution ballistic_;

    SimStep simSteps_[MAX_STEPS];

    float acceleration_ = 0.0f;
    float direction_ = 0.0f;
    float speed_ = 0.0f;
    float currentTime_ = 0.0f;

    Coord currentPos_;
    DroneState state_ = STOPPED;
    int currentTarget_ = -1;
    int stepIndex_ = 0;
    bool finished_ = false;
};
