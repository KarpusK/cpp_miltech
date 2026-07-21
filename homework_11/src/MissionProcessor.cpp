#include "mission/MissionProcessor.h"
#include "json.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <thread>

using json = nlohmann::json;

MissionProcessor::MissionProcessor(
    TelemetryParser& parser,
    DroneControl& control,
    std::unique_ptr<IBallisticSolver> solver)
    : parser_(parser),
      control_(control),
      solver_(std::move(solver))
{
}

bool MissionProcessor::init()
{
    if (!solver_)
    {
        return false;
    }

    simSteps_.clear();
    targets_.clear();
    telemetry_.reset();
    ammoConfig_.reset();
    droneConfig_.reset();
    result_.reset();
    ballisticsReady_ = false;
    finished_ = false;
    dropSent_ = false;

    if (!parser_.openPort())
    {
        std::cerr << "Telemetry parser could not open UART device\n";
        return false;
    }

    if (!control_.init())
    {
        std::cerr << "Drone control could not initialize GPIO lines\n";
        return false;
    }

    if (!control_.signalReady())
    {
        std::cerr << "Could not assert START GPIO line\n";
        return false;
    }

    ready_.store(true);
    return true;
}

void MissionProcessor::run()
{
    if (!ready_.load())
    {
        return;
    }

    while (!finished_ && simSteps_.size() < MAX_STEPS)
    {
        const bool newTelemetry = updateFromUart();

        if (!ballisticsReady_)
        {
            prepareBallistics();
        }

        if (newTelemetry && ballisticsReady_ && !targets_.empty())
        {
            step();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    writeResult("out/simulation.json");
}

bool MissionProcessor::isThreadReady() const
{
    return ready_.load();
}

DroneTelemetry MissionProcessor::toTelemetry(
    const dlink::Telemetry& telemetry) const
{
    DroneTelemetry converted{};
    converted.pos = {telemetry.x, telemetry.y};
    converted.speed = {telemetry.vx, telemetry.vy};
    converted.direction = telemetry.dir;
    converted.state = static_cast<DroneMode>(telemetry.state % 5);
    converted.timeSecSinceStart = static_cast<float>(telemetry.t_ms) / 1000.0f;
    return converted;
}

DroneConfig MissionProcessor::makeConfig() const
{
    DroneConfig config{};

    if (telemetry_)
    {
        config.startPos = {telemetry_->x, telemetry_->y};
        config.altitude = telemetry_->z;
        config.initialDir = telemetry_->dir;
    }

    if (droneConfig_)
    {
        config.attackSpeed = droneConfig_->attackSpeed;
        config.accelPath = droneConfig_->accelerationPath;
        config.angularSpeed = droneConfig_->angularSpeed;
        config.turnThreshold = droneConfig_->turnThreshold;
        config.simTimeStep = droneConfig_->timeStep;
        config.timeScale = droneConfig_->timeScale;
    }

    if (ammoConfig_)
    {
        config.hitRadius = ammoConfig_->hitRadius;
        std::strncpy(config.ammoName,
                     ammoConfig_->name,
                     sizeof(config.ammoName) - 1);
    }

    return config;
}

AmmoParams MissionProcessor::makeAmmo() const
{
    AmmoParams ammo{};
    if (!ammoConfig_)
    {
        return ammo;
    }

    std::strncpy(ammo.name,
                 ammoConfig_->name,
                 sizeof(ammo.name) - 1);
    ammo.mass = ammoConfig_->mass;
    ammo.drag = ammoConfig_->drag;
    ammo.lift = ammoConfig_->lift;
    return ammo;
}

bool MissionProcessor::prepareBallistics()
{
    // No JSON/data files are used. All mission input comes from UART packets.
    if (!telemetry_ || !ammoConfig_ || !droneConfig_)
    {
        return false;
    }

    const DroneConfig config = makeConfig();
    const AmmoParams ammo = makeAmmo();
    ballistic_ = solver_->solve({config, ammo});
    ballisticsReady_ = true;
    return true;
}

bool MissionProcessor::updateFromUart()
{
    if (!parser_.poll())
    {
        return false;
    }

    bool newTelemetry = false;

    if (parser_.hasTelemetry())
    {
        telemetry_ = parser_.telemetry();
        newTelemetry = true;
    }

    if (parser_.hasAmmo())
    {
        ammoConfig_ = parser_.ammo();
        ballisticsReady_ = false;
    }

    if (parser_.hasConfig())
    {
        droneConfig_ = parser_.config();
        ballisticsReady_ = false;
    }

    if (parser_.hasTarget())
    {
        const dlink::TargetPos target = parser_.target();
        const auto existing = std::find_if(
            targets_.begin(), targets_.end(),
            [target](const dlink::TargetPos& candidate)
            {
                return candidate.id == target.id;
            });

        if (existing == targets_.end())
        {
            targets_.push_back(target);
        }
        else
        {
            *existing = target;
        }
    }

    if (parser_.hasResult())
    {
        result_ = parser_.result();
        finished_ = true;
    }

    return newTelemetry;
}

DroneMode MissionProcessor::chooseMode(
    const DroneTelemetry& telemetry,
    float desiredDirection,
    float distance,
    const DroneConfig& config) const
{
    const float angleError = std::fabs(
        normalizeAngle(desiredDirection - telemetry.direction));
    const float scalarSpeed = telemetry.speed.length();

    if (distance <= config.hitRadius) return DroneMode::Stopped;
    if (angleError > config.turnThreshold) return DroneMode::Turning;
    if (scalarSpeed < config.attackSpeed * 0.99f) return DroneMode::Accelerating;
    return DroneMode::Moving;
}

bool MissionProcessor::step()
{
    if (!telemetry_ || targets_.empty() || !ballisticsReady_)
    {
        return false;
    }

    const DroneTelemetry telemetry = toTelemetry(*telemetry_);
    const DroneConfig config = makeConfig();

    float bestTime = std::numeric_limits<float>::max();
    int bestTarget = -1;
    Coord bestPredicted{};
    Coord bestFirePoint{};

    for (std::size_t i = 0; i < targets_.size(); ++i)
    {
        const dlink::TargetPos& target = targets_[i];
        float travelTime = 0.0f;
        Coord predicted{target.x, target.y};
        Coord firePoint{};

        for (int iteration = 0;
             iteration < NUM_TIME_APPROXIMATION_STEPS;
             ++iteration)
        {
            predicted = {target.x, target.y};
            Coord intermediate{};
            bool hasIntermediate = false;

            getIntermediateAndDropPoint(
                telemetry.pos,
                predicted,
                ballistic_.hDistance,
                config.accelPath,
                intermediate,
                firePoint,
                hasIntermediate);

            Coord mutablePosition = telemetry.pos;
            travelTime = calcTimeOfFlight(
                mutablePosition,
                hasIntermediate ? intermediate : firePoint,
                telemetry.direction,
                config.turnThreshold,
                config.angularSpeed,
                telemetry.speed.length(),
                config.attackSpeed,
                config.accelPath,
                hasIntermediate);
        }

        if (travelTime < bestTime)
        {
            bestTime = travelTime;
            bestTarget = static_cast<int>(i);
            bestPredicted = predicted;
            bestFirePoint = firePoint;
        }
    }

    if (bestTarget < 0)
    {
        return false;
    }

    const float desiredDirection = std::atan2(
        bestFirePoint.y - telemetry.pos.y,
        bestFirePoint.x - telemetry.pos.x);
    const float distance = (bestFirePoint - telemetry.pos).length();
    const float angleError = normalizeAngle(
        desiredDirection - telemetry.direction);
    const DroneMode mode = chooseMode(
        telemetry, desiredDirection, distance, config);

    dlink::Control command{};
    switch (mode)
    {
        case DroneMode::Stopped:      command.accel = 0.0f; break;
        case DroneMode::Accelerating: command.accel = 1.0f; break;
        case DroneMode::Decelerating: command.accel = -1.0f; break;
        case DroneMode::Turning:      command.accel = 0.5f; break;
        case DroneMode::Moving:       command.accel = 0.75f; break;
    }

    command.turnRate = std::clamp(
        angleError / std::max(config.turnThreshold, 1.0e-4f),
        -1.0f,
        1.0f);

    if (!control_.sendControl(parser_.fileDescriptor(), command))
    {
        std::cerr << "Could not send CONTROL packet\n";
        return false;
    }

    simSteps_.push_back({
        telemetry.pos,
        telemetry.direction,
        static_cast<int>(telemetry.state),
        bestTarget,
        bestFirePoint,
        calcAimPoint(telemetry.pos,
                     telemetry.direction,
                     ballistic_.hDistance),
        bestPredicted,
        telemetry.timeSecSinceStart
    });

    if (!dropSent_ && distance <= config.hitRadius)
    {
        if (control_.dropPayload())
        {
            dropSent_ = true;
        }
    }

    return true;
}

bool MissionProcessor::writeResult(const std::string& outputPath) const
{
    std::filesystem::create_directories(
        std::filesystem::path(outputPath).parent_path());

    json out;
    out["totalSteps"] = simSteps_.size();
    out["steps"] = json::array();

    for (const SimStep& step : simSteps_)
    {
        out["steps"].push_back({
            {"position", {{"x", step.pos.x}, {"y", step.pos.y}}},
            {"direction", step.direction},
            {"state", step.state},
            {"targetIndex", step.targetIdx},
            {"dropPoint", {{"x", step.dropPoint.x}, {"y", step.dropPoint.y}}},
            {"aimPoint", {{"x", step.aimPoint.x}, {"y", step.aimPoint.y}}},
            {"predictedTarget", {{"x", step.predictedTarget.x}, {"y", step.predictedTarget.y}}},
            {"timeSecSinceStart", step.timeSecSinceStart}
        });
    }

    std::ofstream file(outputPath);
    if (!file)
    {
        return false;
    }

    file << out.dump(2);
    return true;
}
