#pragma once

#include <atomic>
#include <mutex>

#include "config.hpp"
#include "threading/ThreadSafeQueue.h"

enum class DroneMode
{
    Stopped = 0,
    Accelerating = 1,
    Decelerating = 2,
    Turning = 3,
    Moving = 4
};

struct DroneCommand
{
    DroneMode state = DroneMode::Stopped;
    float angleSpeed = 0.0f;
};

struct DroneTelemetry
{
    Coord pos;
    Coord speed;
    float direction = 0.0f;
    DroneMode state = DroneMode::Stopped;
    float timeSecSinceStart = 0.0f;
};

class DronePhysics
{
public:
    explicit DronePhysics(const DroneConfig& config);

    void run();
    void start();
    void stop();
    bool isThreadReady() const;
    void sendCommand(const DroneCommand& command);
    DroneTelemetry getTelemetry() const;

private:
    void integrate(float dt);

    DroneConfig config_;
    ThreadSafeQueue<DroneCommand> commands_;
    mutable std::mutex telemetryMutex_;
    DroneTelemetry telemetry_;
    DroneCommand activeCommand_;
    std::atomic<bool> ready_{false};
    std::atomic<bool> started_{false};
    std::atomic<bool> stopRequested_{false};
};
