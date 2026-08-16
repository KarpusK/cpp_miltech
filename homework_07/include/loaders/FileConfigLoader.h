#pragma once

#include "interfaces/IConfigLoader.h"

#include <string>

class FileConfigLoader : public IConfigLoader
{
public:
    FileConfigLoader();
    FileConfigLoader(const std::string& configPath, const std::string& ammoPath);

    bool load() override;
    const DroneConfig& getConfig() const override;
    const AmmoParams& getAmmoParams() const override;

private:
    std::string configPath_;
    std::string ammoPath_;
    DroneConfig config_;
    AmmoParams ammo_;
};
