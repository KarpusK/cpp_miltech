#include <memory>
#include "Factory.h"

#include "loaders/FileConfigLoader.h"
#include "solvers/AnalyticalSolver.h"
#include "solvers/TableSolver.h"
    #include "states/DroneStates.h"

std::unique_ptr<IBallisticSolver> createSolver(SolverType type) {
    switch (type) {
        case SolverType::ANALYTICAL:
            return std::make_unique<AnalyticalSolver>();
        case SolverType::TABLE:
            return std::make_unique<TableSolver>();
    }
    return nullptr;
}


std::unique_ptr<IConfigLoader> createLoader(
    LoaderType type,
    const char* configPath,
    const char* ammoPath
)
{
    switch (type)
    {
        case LoaderType::FILE:
            return std::make_unique<FileConfigLoader>(configPath, ammoPath);

        default:
            return nullptr;
    }
}

std::unique_ptr<IDroneState> createState(StateType type, const DroneConfig& config, const AmmoParams& ammo)
{
    switch (type)
    {
        case StateType::StateStopped:
            return std::make_unique<StateStopped>(config, ammo);
        case StateType::StateAccelerating:
            return std::make_unique<StateAccelerating>(config, ammo);
        case StateType::StateDecelerating:
            return std::make_unique<StateDecelerating>(config, ammo);
        case StateType::StateTurning:
            return std::make_unique<StateTurning>(config, ammo);
        case StateType::StateMoving:
            return std::make_unique<StateMoving>(config, ammo);
    }

    return nullptr;
}