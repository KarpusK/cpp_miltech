#include "solvers/AnalyticalSolver.h"

BallisticSolution AnalyticalSolver::solve(const BallisticInput& input) const
{
    BallisticSolution solution;
    solution.flightTime = calcTimeOfFall(input.config.altitude,
                                         input.config.attackSpeed,
                                         input.ammo.mass,
                                         input.ammo.drag,
                                         input.ammo.lift);

    solution.hDistance = calcHDistance(solution.flightTime,
                                       input.config.attackSpeed,
                                       input.ammo.mass,
                                       input.ammo.drag,
                                       input.ammo.lift);

    return solution;
}
