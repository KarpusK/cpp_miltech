#pragma once

#include <atomic>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "DroneControl.h"
#include "TelemetryParser.h"
#include "drone_link.h"
#include "interfaces/IBallisticSolver.h"
#include "physics/DronePhysics.h"

struct SimStep
{
    Coord pos;
    float direction = 0.0f;
    int state = 0;
    int targetIdx = -1;
    Coord dropPoint;
    Coord aimPoint;
    Coord predictedTarget;
    float timeSecSinceStart = 0.0f;
};

class MissionProcessor
{
public:
    MissionProcessor(TelemetryParser& parser,
                     DroneControl& control,
                     std::unique_ptr<IBallisticSolver> solver);

    bool init();
    void run();
    bool isThreadReady() const;
    bool writeResult(const std::string& outputPath) const;

private:
    bool updateFromUart();
    bool prepareBallistics();
    bool step();
    DroneConfig makeConfig() const;
    AmmoParams makeAmmo() const;
    DroneTelemetry toTelemetry(const dlink::Telemetry& telemetry) const;
    DroneMode chooseMode(const DroneTelemetry& telemetry,
                         float desiredDirection,
                         float distance,
                         const DroneConfig& config) const;

    TelemetryParser& parser_;
    DroneControl& control_;
    std::unique_ptr<IBallisticSolver> solver_;

    BallisticSolution ballistic_{};
    std::vector<SimStep> simSteps_;
    std::vector<dlink::TargetPos> targets_;
    std::optional<dlink::Telemetry> telemetry_;
    std::optional<dlink::AmmoCfg> ammoConfig_;
    std::optional<dlink::DroneCfg> droneConfig_;
    std::optional<dlink::Result> result_;

    std::atomic<bool> ready_{false};
    bool ballisticsReady_ = false;
    bool finished_ = false;
    bool dropSent_ = false;
};
