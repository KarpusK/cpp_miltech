#include <iostream>

#include "Factory.h"
#include "mission/MissionProcessor.h"

int main()
{
    IConfigLoader* loader = createLoader(
        LoaderType::FILE,
        "data/config.json",
        "data/ammo.json"
    );

    ITargetProvider* provider = createProvider(
        ProviderType::JSON,
        "data/targets.json"
    );

    IBallisticSolver* solver = createSolver(
        SolverType::ANALYTICAL
    );

    if (loader == nullptr || provider == nullptr || solver == nullptr)
    {
        std::cerr << "Error: failed to create mission components\n";

        delete loader;
        delete provider;
        delete solver;

        return 1;
    }

    MissionProcessor mission(loader, provider, solver);

    if (!mission.init())
    {
        std::cerr << "Error: mission initialization failed\n";

        delete loader;
        delete provider;
        delete solver;

        return 1;
    }

    while (mission.hasNext())
    {
        mission.step();
    }

    delete solver;
    delete provider;
    delete loader;

    return 0;
}