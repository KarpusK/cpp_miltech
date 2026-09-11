#include "solvers/TableSolver.h"

BallisticSolution TableSolver::solve(const BallisticInput& input) const
{
    // Load table if not already loaded
    if (!isLoaded) {
        isLoaded = table.load(table.tablepath.c_str());
        if (!isLoaded) {
            // Return default solution if table cannot be loaded
            return BallisticSolution();
        }
    }

    // Lookup the result in the table
    auto result = table.lookup(input.config.altitude,
                                input.config.attackSpeed,
                                input.ammo.mass,
                                input.ammo.drag,
                                input.ammo.lift);

    BallisticSolution solution;
    solution.flightTime = result.t;
    solution.hDistance = result.hDist;

    return solution;
}
