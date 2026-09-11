#include "physics/DronePhysics.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <thread>

DronePhysics::DronePhysics(const DroneConfig& config) : config_(config)
{
    telemetry_.pos = config_.startPos;
    telemetry_.direction = config_.initialDir;
}

void DronePhysics::run()
{
    ready_.store(true);
    while (!started_.load() && !stopRequested_.load())
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    while (!stopRequested_.load())
    {
        while (auto command = commands_.tryPop()) activeCommand_ = *command;
        integrate(config_.physicsTimeStep);
        std::this_thread::sleep_for(std::chrono::duration<float>(config_.physicsTimeStep / config_.timeScale));
    }
}

void DronePhysics::integrate(float dt)
{
    std::lock_guard<std::mutex> lock(telemetryMutex_);
    const float acceleration = config_.attackSpeed * config_.attackSpeed /
        std::max(0.001f, 2.0f * config_.accelPath);
    float scalarSpeed = telemetry_.speed.length();

    telemetry_.state = activeCommand_.state;
    if (activeCommand_.state == DroneMode::Turning)
        telemetry_.direction = std::remainder(telemetry_.direction + activeCommand_.angleSpeed * dt, 2.0f * 3.14159265358979323846f);
    else if (activeCommand_.state == DroneMode::Accelerating)
        scalarSpeed = std::min(config_.attackSpeed, scalarSpeed + acceleration * dt);
    else if (activeCommand_.state == DroneMode::Decelerating)
        scalarSpeed = std::max(0.0f, scalarSpeed - acceleration * dt);
    else if (activeCommand_.state == DroneMode::Stopped)
        scalarSpeed = 0.0f;

    telemetry_.speed = {std::cos(telemetry_.direction) * scalarSpeed,
                        std::sin(telemetry_.direction) * scalarSpeed};
    if (activeCommand_.state != DroneMode::Stopped && activeCommand_.state != DroneMode::Turning)
        telemetry_.pos = telemetry_.pos + telemetry_.speed * dt;

    telemetry_.timeSecSinceStart += dt;
}

void DronePhysics::start() { started_.store(true); }
void DronePhysics::stop() { stopRequested_.store(true); }
bool DronePhysics::isThreadReady() const { return ready_.load(); }
void DronePhysics::sendCommand(const DroneCommand& command) { commands_.push(command); }
DroneTelemetry DronePhysics::getTelemetry() const
{
    std::lock_guard<std::mutex> lock(telemetryMutex_);
    return telemetry_;
}
