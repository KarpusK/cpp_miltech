#pragma once

#include <memory>

#include "ammo.hpp"
#include "config.hpp"

struct DroneStateContext
{
    Coord currentPos;
    float direction = 0.0f;
    float speed = 0.0f;
    float currentTime = 0.0f;
    Coord targetPos;
    float desiredDirection = 0.0f;
    float desiredSpeed = 0.0f;
    float dt = 0.0f;
    bool targetReached = false;
    bool turnNeeded = false;
};

class IDroneState
{
public:
    virtual ~IDroneState() = default;

    virtual std::unique_ptr<IDroneState> update(DroneStateContext& ctx) = 0;
    virtual int getStateId() const = 0;
    virtual const DroneConfig& getConfig() const = 0;
    virtual const AmmoParams& getAmmoParams() const = 0;
};
