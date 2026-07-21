#pragma once

#include "drone_link.h"

#include <cstdint>
#include <string>

class TelemetryParser
{
public:
    explicit TelemetryParser(std::string device);

    ~TelemetryParser();

    TelemetryParser(const TelemetryParser&) = delete;
    TelemetryParser& operator=(const TelemetryParser&) = delete;

    TelemetryParser(TelemetryParser&&) = delete;
    TelemetryParser& operator=(TelemetryParser&&) = delete;

    bool openPort();

    void closePort();

    bool poll();

    bool hasTelemetry() const;

    bool hasTarget() const;

    bool hasAmmo() const;

    bool hasConfig() const;

    bool hasResult() const;

    const dlink::Telemetry& telemetry() const;

    const dlink::TargetPos& target() const;

    const dlink::AmmoCfg& ammo() const;

    const dlink::DroneCfg& config() const;

    const dlink::Result& result() const;

    int fileDescriptor() const;

private:
    bool processPacket(
        std::uint8_t type,
        const std::uint8_t* payload,
        std::uint8_t payloadLength
    );

    std::string device_;

    int fd_ = -1;

    dlink::Parser parser_;

    dlink::Telemetry telemetry_{};

    dlink::TargetPos target_{};

    dlink::AmmoCfg ammo_{};

    dlink::DroneCfg config_{};

    dlink::Result result_{};

    bool telemetryReceived_ = false;

    bool targetReceived_ = false;

    bool ammoReceived_ = false;

    bool configReceived_ = false;

    bool resultReceived_ = false;
};