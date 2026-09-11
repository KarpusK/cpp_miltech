#pragma once

#include "target.hpp"
#include "config.hpp"
#include "ammo.hpp"

const int TARGET_COUNT = 5;
const int TARGET_ARRAY_SIZE = 120;
const int MAX_STEPS = 10000;
const int NUM_TIME_APPROXIMATION_STEPS = 10;
const float g_gravity = 9.81f;

struct BallisticInput
{
    DroneConfig config;
    AmmoParams ammo;
};

struct BallisticSolution
{
    float flightTime = 0.0f;
    float hDistance = 0.0f;
};

float normalizeAngle(float a);
float calcTimeOfFall(float z0, float v0, float m, float d, float l);
float calcHDistance(float t, float V0, float m, float d, float l);
float accel(float speed, float accelPath);
float accelTime(float speed, float acc);
float accelTimeFromDist(float dist, float acc);
float accelPathFromSpeed(float speed, float acc);
float calcTimeOfFlight(Coord& currentPos, Coord targetPos, float currentDir, float angleThreshold,
                       float angularSpeed, float currentSpeed, float maxSpeed, float accelPath,
                       bool needToStopAtTarget);
Coord calcAimPoint(Coord currentPos, float direction, float hDist);
void getIntermediateAndDropPoint(Coord currentPos, Coord targetPos, float hDistance, float accelerationPath,
                                 Coord& intermediatePos, Coord& firePos, bool& outHasIntermediate);
