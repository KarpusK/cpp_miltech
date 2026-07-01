#pragma once

#include "interfaces/IBallisticSolver.h"

class AnalyticalSolver : public IBallisticSolver
{
public:
    BallisticSolution solve(const BallisticInput& input) const override;
};
