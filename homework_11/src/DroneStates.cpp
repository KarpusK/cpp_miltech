#include "states/DroneStates.h"

#include <algorithm>
#include <cmath>

#include "ballistics.hpp"

const DroneConfig& BaseDroneState::getConfig() const { return config_; }
const AmmoParams& BaseDroneState::getAmmoParams() const { return ammo_; }

StateStopped::StateStopped(const DroneConfig& config, const AmmoParams& ammo)
    : BaseDroneState(config, ammo) {}

std::unique_ptr<IDroneState> StateStopped::update(DroneStateContext& ctx)
{
    ctx.speed = 0.0f;
    ctx.targetReached = false;
    ctx.turnNeeded = std::fabs(normalizeAngle(ctx.desiredDirection - ctx.direction)) > config_.turnThreshold;

    if (ctx.turnNeeded)
    {
        return std::make_unique<StateTurning>(config_, ammo_);
    }

    if (ctx.speed < config_.attackSpeed)
    {
        return std::make_unique<StateAccelerating>(config_, ammo_);
    }

    return std::make_unique<StateMoving>(config_, ammo_);
}

int StateStopped::getStateId() const { return 0; }

StateAccelerating::StateAccelerating(const DroneConfig& config, const AmmoParams& ammo)
    : BaseDroneState(config, ammo) {}

std::unique_ptr<IDroneState> StateAccelerating::update(DroneStateContext& ctx)
{
    ctx.speed = std::min(config_.attackSpeed, ctx.speed + config_.accelPath * ctx.dt);
    ctx.turnNeeded = std::fabs(normalizeAngle(ctx.desiredDirection - ctx.direction)) > config_.turnThreshold;

    if (ctx.turnNeeded)
    {
        return std::make_unique<StateTurning>(config_, ammo_);
    }

    if (ctx.speed >= config_.attackSpeed)
    {
        return std::make_unique<StateMoving>(config_, ammo_);
    }

    return std::make_unique<StateAccelerating>(config_, ammo_);
}

int StateAccelerating::getStateId() const { return 1; }

StateDecelerating::StateDecelerating(const DroneConfig& config, const AmmoParams& ammo)
    : BaseDroneState(config, ammo) {}

std::unique_ptr<IDroneState> StateDecelerating::update(DroneStateContext& ctx)
{
    ctx.speed = std::max(0.0f, ctx.speed - config_.accelPath * ctx.dt);
    ctx.turnNeeded = std::fabs(normalizeAngle(ctx.desiredDirection - ctx.direction)) > config_.turnThreshold;

    if (ctx.turnNeeded)
    {
        return std::make_unique<StateTurning>(config_, ammo_);
    }

    if (ctx.speed <= 0.0f)
    {
        return std::make_unique<StateStopped>(config_, ammo_);
    }

    return std::make_unique<StateDecelerating>(config_, ammo_);
}

int StateDecelerating::getStateId() const { return 2; }

StateTurning::StateTurning(const DroneConfig& config, const AmmoParams& ammo)
    : BaseDroneState(config, ammo) {}

std::unique_ptr<IDroneState> StateTurning::update(DroneStateContext& ctx)
{
    float delta = normalizeAngle(ctx.desiredDirection - ctx.direction);
    float step = std::copysign(std::min(config_.angularSpeed * ctx.dt, std::fabs(delta)), delta);
    ctx.direction += step;

    if (std::fabs(normalizeAngle(ctx.desiredDirection - ctx.direction)) <= config_.turnThreshold)
    {
        ctx.direction = ctx.desiredDirection;
        return std::make_unique<StateMoving>(config_, ammo_);
    }

    return std::make_unique<StateTurning>(config_, ammo_);
}

int StateTurning::getStateId() const { return 3; }

StateMoving::StateMoving(const DroneConfig& config, const AmmoParams& ammo)
    : BaseDroneState(config, ammo) {}

std::unique_ptr<IDroneState> StateMoving::update(DroneStateContext& ctx)
{
    ctx.currentPos.x += std::cos(ctx.direction) * ctx.speed * ctx.dt;
    ctx.currentPos.y += std::sin(ctx.direction) * ctx.speed * ctx.dt;
    ctx.targetReached = std::hypot(ctx.currentPos.x - ctx.targetPos.x, ctx.currentPos.y - ctx.targetPos.y) <= config_.hitRadius;

    if (ctx.targetReached)
    {
        return std::make_unique<StateStopped>(config_, ammo_);
    }

    if (std::fabs(normalizeAngle(ctx.desiredDirection - ctx.direction)) > config_.turnThreshold)
    {
        return std::make_unique<StateTurning>(config_, ammo_);
    }

    if (ctx.speed < config_.attackSpeed)
    {
        return std::make_unique<StateAccelerating>(config_, ammo_);
    }

    return std::make_unique<StateMoving>(config_, ammo_);
}

int StateMoving::getStateId() const { return 4; }
