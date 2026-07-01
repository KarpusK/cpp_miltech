#pragma once

#include "target.hpp"

struct DroneConfig
{
    Coord startPos;
    float altitude = 0.0f;
    float initialDir = 0.0f;
    float attackSpeed = 0.0f;
    float accelPath = 0.0f;
    char ammoName[32] = {};
    float arrayTimeStep = 0.0f;
    float simTimeStep = 0.0f;
    float hitRadius = 0.0f;
    float angularSpeed = 0.0f;
    float turnThreshold = 0.0f;
};
