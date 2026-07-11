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
    float arrayTimeStep = 1.0f;
    float simTimeStep = 0.1f;
    float physicsTimeStep = 0.01f;
    float timeScale = 10.0f;
    float hitRadius = 2.0f;
    float angularSpeed = 0.5f;
    float turnThreshold = 0.05f;
};
