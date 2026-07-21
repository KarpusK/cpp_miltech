#include "TelemetryParser.h"

#include <cerrno>
#include <cstdint>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <utility>

TelemetryParser::TelemetryParser(std::string device)
    : device_(std::move(device))
{
}

TelemetryParser::~TelemetryParser()
{
    closePort();
}

bool TelemetryParser::openPort()
{
    if (fd_ >= 0)
    {
        return true;
    }

    fd_ = ::open(
        device_.c_str(),
        O_RDWR | O_NOCTTY | O_NONBLOCK
    );

    if (fd_ < 0)
    {
        std::cerr
            << "Cannot open UART device "
            << device_
            << ": "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    termios tty{};

    if (::tcgetattr(fd_, &tty) != 0)
    {
        std::cerr
            << "tcgetattr failed for "
            << device_
            << ": "
            << std::strerror(errno)
            << '\n';

        closePort();
        return false;
    }

    ::cfmakeraw(&tty);

    if (::cfsetispeed(&tty, B115200) != 0)
    {
        std::cerr
            << "Failed to set UART input speed: "
            << std::strerror(errno)
            << '\n';

        closePort();
        return false;
    }

    if (::cfsetospeed(&tty, B115200) != 0)
    {
        std::cerr
            << "Failed to set UART output speed: "
            << std::strerror(errno)
            << '\n';

        closePort();
        return false;
    }

    tty.c_cflag |= CLOCAL;
    tty.c_cflag |= CREAD;

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    if (::tcsetattr(fd_, TCSANOW, &tty) != 0)
    {
        std::cerr
            << "tcsetattr failed for "
            << device_
            << ": "
            << std::strerror(errno)
            << '\n';

        closePort();
        return false;
    }

    return true;
}

void TelemetryParser::closePort()
{
    if (fd_ >= 0)
    {
        ::close(fd_);
        fd_ = -1;
    }
}

bool TelemetryParser::poll()
{
    // These flags describe packets received during this poll() call only.
    // The decoded structures themselves remain stored in the object.
    telemetryReceived_ = false;
    targetReceived_ = false;
    ammoReceived_ = false;
    configReceived_ = false;
    resultReceived_ = false;

    if (fd_ < 0)
    {
        return false;
    }

    std::uint8_t readBuffer[256]{};

    const ssize_t bytesRead =
        ::read(fd_, readBuffer, sizeof(readBuffer));

    if (bytesRead < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            return false;
        }

        std::cerr
            << "UART read failed: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    if (bytesRead == 0)
    {
        return false;
    }

    bool packetReceived = false;

    for (ssize_t i = 0; i < bytesRead; ++i)
    {
        std::uint8_t packetType = 0;
        std::uint8_t payloadLength = 0;
        std::uint8_t payload[260]{};

        const bool packetReady =
            parser_.feed(
                readBuffer[i],
                packetType,
                payload,
                payloadLength
            );

        if (!packetReady)
        {
            continue;
        }

        if (processPacket(
                packetType,
                payload,
                payloadLength))
        {
            packetReceived = true;
        }
    }

    return packetReceived;
}

bool TelemetryParser::processPacket(
    std::uint8_t type,
    const std::uint8_t* payload,
    std::uint8_t payloadLength)
{
    switch (type)
    {
    case dlink::PKT_TELEMETRY:
    {
        if (payloadLength != sizeof(dlink::Telemetry))
        {
            std::cerr
                << "Invalid TELEMETRY packet length: "
                << static_cast<int>(payloadLength)
                << ", expected "
                << sizeof(dlink::Telemetry)
                << '\n';

            return false;
        }

        std::memcpy(
            &telemetry_,
            payload,
            sizeof(telemetry_)
        );

        telemetryReceived_ = true;
        return true;
    }

    case dlink::PKT_TARGET:
    {
        if (payloadLength != sizeof(dlink::TargetPos))
        {
            std::cerr
                << "Invalid TARGET packet length: "
                << static_cast<int>(payloadLength)
                << ", expected "
                << sizeof(dlink::TargetPos)
                << '\n';

            return false;
        }

        std::memcpy(
            &target_,
            payload,
            sizeof(target_)
        );

        targetReceived_ = true;
        return true;
    }

    case dlink::PKT_AMMO:
    {
        if (payloadLength != sizeof(dlink::AmmoCfg))
        {
            std::cerr
                << "Invalid AMMO packet length: "
                << static_cast<int>(payloadLength)
                << ", expected "
                << sizeof(dlink::AmmoCfg)
                << '\n';

            return false;
        }

        std::memcpy(
            &ammo_,
            payload,
            sizeof(ammo_)
        );

        ammoReceived_ = true;
        return true;
    }

    case dlink::PKT_CONFIG:
    {
        if (payloadLength != sizeof(dlink::DroneCfg))
        {
            std::cerr
                << "Invalid CONFIG packet length: "
                << static_cast<int>(payloadLength)
                << ", expected "
                << sizeof(dlink::DroneCfg)
                << '\n';

            return false;
        }

        std::memcpy(
            &config_,
            payload,
            sizeof(config_)
        );

        configReceived_ = true;
        return true;
    }

    case dlink::PKT_RESULT:
    {
        if (payloadLength != sizeof(dlink::Result))
        {
            std::cerr
                << "Invalid RESULT packet length: "
                << static_cast<int>(payloadLength)
                << ", expected "
                << sizeof(dlink::Result)
                << '\n';

            return false;
        }

        std::memcpy(
            &result_,
            payload,
            sizeof(result_)
        );

        resultReceived_ = true;
        return true;
    }

    case dlink::PKT_CONTROL:
    {
        std::cerr
            << "Unexpected CONTROL packet received by student program\n";

        return false;
    }

    default:
    {
        std::cerr
            << "Unknown packet type: "
            << static_cast<int>(type)
            << '\n';

        return false;
    }
    }
}

bool TelemetryParser::hasTelemetry() const
{
    return telemetryReceived_;
}

bool TelemetryParser::hasTarget() const
{
    return targetReceived_;
}

bool TelemetryParser::hasAmmo() const
{
    return ammoReceived_;
}

bool TelemetryParser::hasConfig() const
{
    return configReceived_;
}

bool TelemetryParser::hasResult() const
{
    return resultReceived_;
}

const dlink::Telemetry& TelemetryParser::telemetry() const
{
    return telemetry_;
}

const dlink::TargetPos& TelemetryParser::target() const
{
    return target_;
}

const dlink::AmmoCfg& TelemetryParser::ammo() const
{
    return ammo_;
}

const dlink::DroneCfg& TelemetryParser::config() const
{
    return config_;
}

const dlink::Result& TelemetryParser::result() const
{
    return result_;
}

int TelemetryParser::fileDescriptor() const
{
    return fd_;
}