#include "Factory.h"

#include "loaders/FileConfigLoader.h"
#include "providers/JsonTargetProvider.h"
#include "solvers/AnalyticalSolver.h"

IBallisticSolver* createSolver(SolverType type)
{
    switch (type)
    {
        case SolverType::ANALYTICAL:
            return new AnalyticalSolver();

        default:
            return nullptr;
    }
}

ITargetProvider* createProvider(ProviderType type, const char* targetsPath)
{
    switch (type)
    {
        case ProviderType::JSON:
            return new JsonTargetProvider(targetsPath);

        default:
            return nullptr;
    }
}

IConfigLoader* createLoader(
    LoaderType type,
    const char* configPath,
    const char* ammoPath
)
{
    switch (type)
    {
        case LoaderType::FILE:
            return new FileConfigLoader(configPath, ammoPath);

        default:
            return nullptr;
    }
}