#include "providers/JsonTargetProvider.h"

#include "ballistics.hpp"
#include "json.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

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

JsonTargetProvider::JsonTargetProvider()
    : targetsPath_("data/targets.json")
{
}

JsonTargetProvider::JsonTargetProvider(const std::string& targetsPath)
    : targetsPath_(targetsPath)
{
}

bool JsonTargetProvider::load()
{
    json jt;
    std::string err;
    if (!loadJsonFileLocal(targetsPath_, jt, err))
    {
        std::cerr << err << std::endl;
        return false;
    }

    int tgtCount = jt["targetCount"];
    int timeSteps = jt["timeSteps"];

    if (tgtCount != TARGET_COUNT || timeSteps != TARGET_ARRAY_SIZE)
    {
        std::cerr << "Wrong targets.json size" << std::endl;
        return false;
    }

    for (int targetId = 0; targetId < TARGET_COUNT; ++targetId)
    {
        std::vector<int> timeSteps(TARGET_ARRAY_SIZE);
        for (int timeStep = 0; timeStep < TARGET_ARRAY_SIZE; ++timeStep)
        {
            targets_[targetId].positions[timeStep].x = jt["targets"][targetId]["positions"][timeStep]["x"];
            targets_[targetId].positions[timeStep].y = jt["targets"][targetId]["positions"][timeStep]["y"];
        }
    }

    return true;
}

int JsonTargetProvider::getTargetCount() const
{
    return TARGET_COUNT;
}

Target JsonTargetProvider::getTarget(int index) const
{
    return targets_[index];
}

Coord JsonTargetProvider::getTargetPosition(int targetIndex, int timeIndex) const
{
    return targets_[targetIndex].positions[timeIndex];
}
