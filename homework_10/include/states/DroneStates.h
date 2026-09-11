#pragma once

#include <memory>

#include "ammo.hpp"
#include "config.hpp"
#include "interfaces/IDroneState.h"

class BaseDroneState : public IDroneState
{
public:
    BaseDroneState(const DroneConfig& config, const AmmoParams& ammo)
        : config_(config), ammo_(ammo) {}

    const DroneConfig& getConfig() const override;
    const AmmoParams& getAmmoParams() const override;

protected:
    const DroneConfig& config_;
    const AmmoParams& ammo_;
};

class StateStopped : public BaseDroneState
{
public:
    StateStopped(const DroneConfig& config, const AmmoParams& ammo);

    std::unique_ptr<IDroneState> update(DroneStateContext& ctx) override;
    int getStateId() const override;
};

class StateAccelerating : public BaseDroneState
{
public:
    StateAccelerating(const DroneConfig& config, const AmmoParams& ammo);

    std::unique_ptr<IDroneState> update(DroneStateContext& ctx) override;
    int getStateId() const override;
};

class StateDecelerating : public BaseDroneState
{
public:
    StateDecelerating(const DroneConfig& config, const AmmoParams& ammo);

    std::unique_ptr<IDroneState> update(DroneStateContext& ctx) override;
    int getStateId() const override;
};

class StateTurning : public BaseDroneState
{
public:
    StateTurning(const DroneConfig& config, const AmmoParams& ammo);

    std::unique_ptr<IDroneState> update(DroneStateContext& ctx) override;
    int getStateId() const override;
};

class StateMoving : public BaseDroneState
{
public:
    StateMoving(const DroneConfig& config, const AmmoParams& ammo);

    std::unique_ptr<IDroneState> update(DroneStateContext& ctx) override;
    int getStateId() const override;
};
