#pragma once

#include "ballistics.hpp"

class IBallisticSolver
{
public:
    virtual ~IBallisticSolver() = default;

    virtual BallisticSolution solve(const BallisticInput& input) const = 0;
};
