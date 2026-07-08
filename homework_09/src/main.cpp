#include <iostream>
#include <memory>

#include "Factory.h"
#include "mission/MissionProcessor.h"

int main()
{
    std::unique_ptr<IConfigLoader> loader = createLoader(
        LoaderType::FILE,
        "data/config.json",
        "data/ammo.json"
    );

    std::unique_ptr<ITargetProvider> provider = createProvider(
        ProviderType::JSON,
        "data/targets.json"
    );

    std::unique_ptr<IBallisticSolver> solver = createSolver(
        SolverType::TABLE
    );

    if (loader == nullptr || provider == nullptr || solver == nullptr)
    {
        std::cerr << "Error: failed to create mission components\n";

        loader.reset();
        provider.reset();
        solver.reset();

        return 1;
    }

    MissionProcessor mission(std::move(loader), std::move(provider), std::move(solver));

    if (!mission.init())
    {
        std::cerr << "Error: mission initialization failed\n";

        loader.reset();
        provider.reset();
        solver.reset();

        return 1;
    }

    while (mission.hasNext())
    {
        mission.step();
    }

    solver.reset();
    provider.reset();
    loader.reset();

    return 0;
}