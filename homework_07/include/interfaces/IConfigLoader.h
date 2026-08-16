#pragma once

#include "config.hpp"
#include "ammo.hpp"

class IConfigLoader
{
public:
    virtual ~IConfigLoader() = default;

    virtual bool load() = 0;
    virtual const DroneConfig& getConfig() const = 0;
    virtual const AmmoParams& getAmmoParams() const = 0;
};
