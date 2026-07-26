#pragma once

#include "interfaces/IConfigLoader.h"
#include "interfaces/ITargetProvider.h"
#include "interfaces/IBallisticSolver.h"

enum class SolverType
{
    ANALYTICAL
};

enum class ProviderType
{
    JSON
};

enum class LoaderType
{
    FILE
};

IBallisticSolver* createSolver(SolverType type);

ITargetProvider* createProvider(
    ProviderType type,
    const char* targetsPath
);

IConfigLoader* createLoader(
    LoaderType type,
    const char* configPath,
    const char* ammoPath
);
