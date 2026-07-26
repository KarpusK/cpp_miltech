#include "loaders/FileConfigLoader.h"

#include "json.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using json = nlohmann::json;

static bool loadJsonFileLocal(const std::string& path, json& out, std::string& err)
{
    std::ifstream f(path);
    if (!f.is_open())
    {
        std::ostringstream ss;
        ss << "Cannot open file: " << path;
        err = ss.str();
        return false;
    }

    try
    {
        f >> out;
    }
    catch (const std::exception& e)
    {
        std::ostringstream ss;
        ss << "Parse error in " << path << ": " << e.what();
        err = ss.str();
        return false;
    }

    return true;
}

FileConfigLoader::FileConfigLoader()
    : configPath_("data/config.json"), ammoPath_("data/ammo.json")
{
}

FileConfigLoader::FileConfigLoader(const std::string& configPath, const std::string& ammoPath)
    : configPath_(configPath), ammoPath_(ammoPath)
{
}

bool FileConfigLoader::load()
{
    json jc;
    std::string err;
    if (!loadJsonFileLocal(configPath_, jc, err))
    {
        std::cerr << err << std::endl;
        return false;
    }

    config_.startPos.x = jc["Drone"]["startPos"]["x"];
    config_.startPos.y = jc["Drone"]["startPos"]["y"];
    config_.altitude = jc["Drone"]["altitude"];
    config_.initialDir = jc["Drone"]["initialDirection"];
    config_.attackSpeed = jc["Drone"]["attackSpeed"];
    config_.accelPath = jc["Drone"]["accelerationPath"];
    std::strncpy(config_.ammoName, jc["Drone"]["ammoName"].get<std::string>().c_str(), sizeof(config_.ammoName) - 1);
    config_.ammoName[sizeof(config_.ammoName) - 1] = '\0';
    config_.arrayTimeStep = jc["Drone"]["targetArrayTimeStep"];
    config_.simTimeStep = jc["Drone"]["simulation"]["timeStep"];
    config_.hitRadius = jc["Drone"]["simulation"]["hitRadius"];
    config_.angularSpeed = jc["Drone"]["angularSpeed"];
    config_.turnThreshold = jc["Drone"]["turnThreshold"];

    json ja;
    if (!loadJsonFileLocal(ammoPath_, ja, err))
    {
        std::cerr << err << std::endl;
        return false;
    }

    int ammoCount = static_cast<int>(ja.size());
    if (ammoCount <= 0)
    {
        std::cerr << "ammo.json: no entries" << std::endl;
        return false;
    }

    std::vector<AmmoParams> ammoList(ammoCount);
    int bombIdx = -1;

    for (int i = 0; i < ammoCount; ++i)
    {
        std::strncpy(ammoList[i].name, ja[i]["name"].get<std::string>().c_str(), sizeof(ammoList[i].name) - 1);
        ammoList[i].name[sizeof(ammoList[i].name) - 1] = '\0';
        ammoList[i].mass = ja[i]["mass"];
        ammoList[i].drag = ja[i]["drag"];
        ammoList[i].lift = ja[i]["lift"];

        if (std::string(config_.ammoName) == std::string(ammoList[i].name))
        {
            bombIdx = i;
            break;
        }
    }

    if (bombIdx == -1)
    {
        bombIdx = 0;
        std::cout << "[LOG] ammo.json: requested ammo not found, falling back to first entry" << std::endl;
    }

    ammo_ = ammoList[bombIdx];
    return true;
}

const DroneConfig& FileConfigLoader::getConfig() const
{
    return config_;
}

const AmmoParams& FileConfigLoader::getAmmoParams() const
{
    return ammo_;
}
