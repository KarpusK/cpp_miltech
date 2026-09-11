#pragma once

#include <memory>
#include "interfaces/IConfigLoader.h"
#include "interfaces/IBallisticSolver.h"
#include "interfaces/IDroneState.h"

enum class SolverType { ANALYTICAL, TABLE };
enum class LoaderType { FILE };
enum class StateType { StateStopped, StateAccelerating, StateDecelerating, StateTurning, StateMoving };

std::unique_ptr<IBallisticSolver> createSolver(SolverType type);
std::unique_ptr<IConfigLoader> createLoader(LoaderType type, const char* configPath, const char* ammoPath);
std::unique_ptr<IDroneState> createState(StateType type, const DroneConfig& config, const AmmoParams& ammo);
