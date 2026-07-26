#define _USE_MATH_DEFINES
#include "ballistics.hpp"

#include <algorithm>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define STOP_WHEN_TURNING

float normalizeAngle(float a)
{
    while (a > M_PI) a -= 2.0f * static_cast<float>(M_PI);
    while (a < -M_PI) a += 2.0f * static_cast<float>(M_PI);
    return a;
}

float calcTimeOfFall(float z0, float v0, float m, float d, float l)
{
    float a = d * g_gravity * m - 2 * d * l * v0;
    float b = -3 * g_gravity * m + 3 * d * l * v0;
    float c = 6 * m * z0;

    if (std::fabs(a) < 1e-12f) return std::sqrt(2.0f * z0 / g_gravity);

    float p = -b * b / (3 * a * a);
    float q = (2 * b * b * b) / (27 * a * a * a) + c / a;

    if (p >= 0) return std::sqrt(2.0f * z0 / g_gravity);

    float arg = 3 * q / (2 * p) * std::sqrt(-3 / p);
    if (std::fabs(arg) > 1) return std::sqrt(2.0f * z0 / g_gravity);

    float phi = std::acos(arg);
    float t = 2 * std::sqrt(-p / 3) * std::cos((phi + 4 * static_cast<float>(M_PI)) / 3) - b / (3 * a);
    return t > 0 ? t : std::sqrt(2.0f * z0 / g_gravity);
}

float calcHDistance(float t, float V0, float m, float d, float l)
{
    float l2 = l * l;
    float l4 = l2 * l2;

    return t * V0
        - (d * std::pow(t, 2) * V0) / (2 * m)
        + (std::pow(t, 3) * (6 * d * g_gravity * l * m - 8 * std::pow(d, 2) * (-1 + l2) * V0)) / (36 * std::pow(m, 2))
        + (std::pow(t, 4) * (-6 * std::pow(d, 2) * g_gravity * l * (1 + l2 + l4) * m
            + 3 * std::pow(d, 3) * l2 * (1 + l2) * V0
            + 6 * std::pow(d, 3) * l4 * (1 + l2) * V0))
        / (36 * std::pow(1 + l2, 2) * std::pow(m, 3))
        + (std::pow(t, 5) * (3 * std::pow(d, 3) * g_gravity * std::pow(l, 3) * m
            - 3 * std::pow(d, 4) * l2 * (1 + l2) * V0))
        / (36 * (1 + l2) * std::pow(m, 4));
}

void getIntermediateAndDropPoint(Coord currentPos, Coord targetPos, float hDistance, float accelerationPath,
                                 Coord& intermediatePos, Coord& firePos, bool& outHasIntermediate)
{
    float distanceToTarget = std::hypot(targetPos.x - currentPos.x, targetPos.y - currentPos.y);
    outHasIntermediate = hDistance + accelerationPath > distanceToTarget;

    if (outHasIntermediate)
    {
        if (std::fabs(distanceToTarget) < 1e-6f)
        {
            intermediatePos.x = targetPos.x - (hDistance + accelerationPath);
            intermediatePos.y = targetPos.y;
            distanceToTarget = hDistance + accelerationPath;
        }
        else
        {
            intermediatePos.x = targetPos.x - (targetPos.x - currentPos.x) * (hDistance + accelerationPath) / distanceToTarget;
            intermediatePos.y = targetPos.y - (targetPos.y - currentPos.y) * (hDistance + accelerationPath) / distanceToTarget;
            distanceToTarget = std::hypot(targetPos.x - intermediatePos.x, targetPos.y - intermediatePos.y);
        }
    }

    float ratio = (distanceToTarget - hDistance) / std::max(1e-9f, distanceToTarget);
    firePos.x = currentPos.x + (targetPos.x - currentPos.x) * ratio;
    firePos.y = currentPos.y + (targetPos.y - currentPos.y) * ratio;
}

static bool needStop(float desiredDir, float currentDir, float angleThreshold)
{
#ifdef STOP_WHEN_TURNING
    float deltaAngle = normalizeAngle(desiredDir - currentDir);
    return std::fabs(deltaAngle) > angleThreshold;
#else
    return false;
#endif
}

float accel(float speed, float accelPath)
{
    return speed * speed / (2.0f * accelPath);
}

float accelTime(float speed, float acc)
{
    return speed / acc;
}

float accelTimeFromDist(float dist, float acc)
{
    return std::sqrt(2.0f * dist / acc);
}

float accelPathFromSpeed(float speed, float acc)
{
    return (speed * speed) / (2.0f * acc);
}

float calcTimeOfFlight(Coord& currentPos, Coord targetPos, float currentDir, float angleThreshold,
                       float angularSpeed, float currentSpeed, float maxSpeed, float accelPath,
                       bool needToStopAtTarget)
{
    float totalTimeToPoint = 0.0f;
    float desiredDir = std::atan2(targetPos.y - currentPos.y, targetPos.x - currentPos.x);
    float a = accel(maxSpeed, accelPath);

    if (needStop(desiredDir, currentDir, angleThreshold))
    {
        float pathToStop = (currentSpeed * currentSpeed) / (2.0f * a);
        currentPos.x += std::cos(currentDir) * pathToStop;
        currentPos.y += std::sin(currentDir) * pathToStop;

        totalTimeToPoint += accelTime(currentSpeed, a);
        totalTimeToPoint += std::fabs(normalizeAngle(desiredDir - currentDir)) / angularSpeed;

        currentSpeed = 0;
        currentDir = desiredDir;
    }

    float distanceToTarget = std::hypot(targetPos.x - currentPos.x, targetPos.y - currentPos.y);
    float decceleratePath = std::min(needToStopAtTarget ? accelPathFromSpeed(maxSpeed, a) : 0.0f, distanceToTarget);
    distanceToTarget -= decceleratePath;
    totalTimeToPoint += accelTimeFromDist(decceleratePath, a);

    float accelDist = std::min(accelPathFromSpeed(maxSpeed, a) - accelPathFromSpeed(currentSpeed, a), distanceToTarget);
    totalTimeToPoint += accelTimeFromDist(accelDist, a);
    distanceToTarget -= accelDist;
    totalTimeToPoint += distanceToTarget / maxSpeed;

    return totalTimeToPoint;
}

Coord calcAimPoint(Coord currentPos, float direction, float hDist)
{
    return {currentPos.x + std::cos(direction) * hDist,
            currentPos.y + std::sin(direction) * hDist};
}
