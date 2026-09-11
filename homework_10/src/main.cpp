#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "Factory.h"
#include "mission/MissionProcessor.h"
#include "physics/DronePhysics.h"
#include "providers/JsonTargetProvider.h"

int main()
{
    auto loader = createLoader(LoaderType::FILE, "data/config.json", "data/ammo.json");
    auto solver = createSolver(SolverType::TABLE);
    if (!loader || !solver || !loader->load())
    {
        std::cerr << "Failed to load configuration\n";
        return 1;
    }

    const DroneConfig config = loader->getConfig();
    const AmmoParams ammo = loader->getAmmoParams();
    JsonTargetProvider provider("data/targets.json", config.arrayTimeStep, config.timeScale);
    if (!provider.load())
    {
        std::cerr << "Failed to load targets\n";
        return 1;
    }

    DronePhysics physics(config);
    MissionProcessor mission(config, ammo, provider, physics, std::move(solver));
    if (!mission.init())
    {
        std::cerr << "Failed to initialize mission\n";
        return 1;
    }

    std::thread providerThread(&JsonTargetProvider::run, &provider);
    std::thread physicsThread(&DronePhysics::run, &physics);
    std::thread missionThread(&MissionProcessor::run, &mission);

    while (!provider.isThreadReady() || !physics.isThreadReady() || !mission.isThreadReady())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    provider.start();
    physics.start();
    mission.start();

    missionThread.join();
    physics.stop();
    provider.stop();
    physicsThread.join();
    providerThread.join();
    return 0;
}
