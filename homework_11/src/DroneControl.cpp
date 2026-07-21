#include "DroneControl.h"

#include <algorithm>
#include <cerrno>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <utility>

DroneControl::DroneControl(
    std::string chipName,
    unsigned int startLine,
    unsigned int dropLine)
    : chipName_(std::move(chipName)),
      startLineNumber_(startLine),
      dropLineNumber_(dropLine)
{
}

DroneControl::~DroneControl()
{
    if (startLine_ != nullptr)
    {
        gpiod_line_set_value(startLine_, 0);
        gpiod_line_release(startLine_);
    }

    if (dropLine_ != nullptr)
    {
        gpiod_line_set_value(dropLine_, 0);
        gpiod_line_release(dropLine_);
    }

    if (chip_ != nullptr)
    {
        gpiod_chip_close(chip_);
    }
}

bool DroneControl::init()
{
    if (initialized_)
    {
        return true;
    }

    chip_ = gpiod_chip_open_by_name(chipName_.c_str());
    if (chip_ == nullptr)
    {
        std::cerr << "Cannot open GPIO chip " << chipName_
                  << ": " << std::strerror(errno) << '\n';
        return false;
    }

    startLine_ = gpiod_chip_get_line(chip_, startLineNumber_);
    dropLine_ = gpiod_chip_get_line(chip_, dropLineNumber_);

    if (startLine_ == nullptr || dropLine_ == nullptr)
    {
        std::cerr << "Cannot get START/DROP GPIO lines: "
                  << std::strerror(errno) << '\n';
        return false;
    }

    if (gpiod_line_request_output(startLine_, "homework-11-start", 0) != 0)
    {
        std::cerr << "Cannot request START GPIO as output: "
                  << std::strerror(errno) << '\n';
        return false;
    }

    if (gpiod_line_request_output(dropLine_, "homework-11-drop", 0) != 0)
    {
        std::cerr << "Cannot request DROP GPIO as output: "
                  << std::strerror(errno) << '\n';
        gpiod_line_release(startLine_);
        startLine_ = nullptr;
        return false;
    }

    initialized_ = true;
    return true;
}

bool DroneControl::signalReady()
{
    return initialized_ && gpiod_line_set_value(startLine_, 1) == 0;
}

bool DroneControl::dropPayload()
{
    if (!initialized_ || dropped_)
    {
        return false;
    }

    if (gpiod_line_set_value(dropLine_, 1) != 0)
    {
        return false;
    }

    usleep(80'000);

    if (gpiod_line_set_value(dropLine_, 0) != 0)
    {
        return false;
    }

    dropped_ = true;
    return true;
}

bool DroneControl::sendControl(
    int uartFd,
    const dlink::Control& control)
{
    if (uartFd < 0 || !initialized_)
    {
        return false;
    }

    const dlink::Control safeControl{
        std::clamp(control.accel, -1.0f, 1.0f),
        std::clamp(control.turnRate, -1.0f, 1.0f)
    };

    std::uint8_t frame[sizeof(dlink::Control) + 6]{};
    const std::size_t frameLength = dlink::encode(
        dlink::PKT_CONTROL,
        &safeControl,
        static_cast<std::uint8_t>(sizeof(safeControl)),
        frame);

    std::size_t totalWritten = 0;
    while (totalWritten < frameLength)
    {
        const ssize_t written = ::write(
            uartFd,
            frame + totalWritten,
            frameLength - totalWritten);

        if (written > 0)
        {
            totalWritten += static_cast<std::size_t>(written);
            continue;
        }

        if (written < 0 && errno == EINTR)
        {
            continue;
        }

        if (written < 0 && (errno == EAGAIN || errno == EWOULDBLOCK))
        {
            usleep(500);
            continue;
        }

        std::cerr << "Failed to send CONTROL packet: "
                  << std::strerror(errno) << '\n';
        return false;
    }

    return true;
}
