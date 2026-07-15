#include "DroneControl.h"

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>
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
    if (lineRequest_ != nullptr)
    {
        gpiod_line_request_set_value(
            lineRequest_,
            startLineNumber_,
            GPIOD_LINE_VALUE_INACTIVE
        );

        gpiod_line_request_set_value(
            lineRequest_,
            dropLineNumber_,
            GPIOD_LINE_VALUE_INACTIVE
        );

        gpiod_line_request_release(lineRequest_);
        lineRequest_ = nullptr;
    }

    if (chip_ != nullptr)
    {
        gpiod_chip_close(chip_);
        chip_ = nullptr;
    }
}

bool DroneControl::init()
{
    const std::string chipPath =
        "/dev/" + chipName_;

    chip_ = gpiod_chip_open(chipPath.c_str());

    if (chip_ == nullptr)
    {
        std::cerr
            << "Cannot open GPIO chip "
            << chipPath
            << ": "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    gpiod_request_config* requestConfig =
        gpiod_request_config_new();

    gpiod_line_config* lineConfig =
        gpiod_line_config_new();

    gpiod_line_settings* lineSettings =
        gpiod_line_settings_new();

    if (requestConfig == nullptr ||
        lineConfig == nullptr ||
        lineSettings == nullptr)
    {
        std::cerr << "Cannot allocate GPIO configuration\n";

        gpiod_request_config_free(requestConfig);
        gpiod_line_config_free(lineConfig);
        gpiod_line_settings_free(lineSettings);

        return false;
    }

    gpiod_request_config_set_consumer(
        requestConfig,
        "drone-control"
    );

    if (gpiod_line_settings_set_direction(
            lineSettings,
            GPIOD_LINE_DIRECTION_OUTPUT) != 0)
    {
        std::cerr << "Cannot set GPIO direction\n";

        gpiod_request_config_free(requestConfig);
        gpiod_line_config_free(lineConfig);
        gpiod_line_settings_free(lineSettings);

        return false;
    }

    if (gpiod_line_settings_set_output_value(
            lineSettings,
            GPIOD_LINE_VALUE_INACTIVE) != 0)
    {
        std::cerr << "Cannot set initial GPIO value\n";

        gpiod_request_config_free(requestConfig);
        gpiod_line_config_free(lineConfig);
        gpiod_line_settings_free(lineSettings);

        return false;
    }

    const unsigned int offsets[] = {
        startLineNumber_,
        dropLineNumber_
    };

    if (gpiod_line_config_add_line_settings(
            lineConfig,
            offsets,
            2,
            lineSettings) != 0)
    {
        std::cerr
            << "Cannot configure GPIO lines: "
            << std::strerror(errno)
            << '\n';

        gpiod_request_config_free(requestConfig);
        gpiod_line_config_free(lineConfig);
        gpiod_line_settings_free(lineSettings);

        return false;
    }

    lineRequest_ = gpiod_chip_request_lines(
        chip_,
        requestConfig,
        lineConfig
    );

    gpiod_request_config_free(requestConfig);
    gpiod_line_config_free(lineConfig);
    gpiod_line_settings_free(lineSettings);

    if (lineRequest_ == nullptr)
    {
        std::cerr
            << "Cannot request GPIO lines: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    return true;
}

bool DroneControl::signalReady()
{
    if (lineRequest_ == nullptr)
    {
        return false;
    }

    const int result = gpiod_line_request_set_value(
        lineRequest_,
        startLineNumber_,
        GPIOD_LINE_VALUE_ACTIVE
    );

    if (result != 0)
    {
        std::cerr
            << "Cannot set START GPIO: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    return true;
}

bool DroneControl::dropPayload()
{
    if (lineRequest_ == nullptr)
    {
        return false;
    }

    if (gpiod_line_request_set_value(
            lineRequest_,
            dropLineNumber_,
            GPIOD_LINE_VALUE_ACTIVE) != 0)
    {
        std::cerr
            << "Cannot activate DROP GPIO: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    std::this_thread::sleep_for(
        std::chrono::milliseconds(80)
    );

    if (gpiod_line_request_set_value(
            lineRequest_,
            dropLineNumber_,
            GPIOD_LINE_VALUE_INACTIVE) != 0)
    {
        std::cerr
            << "Cannot deactivate DROP GPIO: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    return true;
}

bool DroneControl::sendControl(
    int uartFd,
    const dlink::Control& control)
{
    if (uartFd < 0)
    {
        std::cerr << "Invalid UART descriptor\n";
        return false;
    }

    dlink::Control safeControl{};

    safeControl.accel =
        std::clamp(control.accel, -1.0F, 1.0F);

    safeControl.turnRate =
        std::clamp(control.turnRate, -1.0F, 1.0F);

    std::uint8_t frame[
        sizeof(dlink::Control) + 6
    ]{};

    const std::size_t frameLength =
        dlink::encode(
            dlink::PKT_CONTROL,
            &safeControl,
            static_cast<std::uint8_t>(
                sizeof(safeControl)
            ),
            frame
        );

    std::size_t totalWritten = 0;

    while (totalWritten < frameLength)
    {
        const ssize_t written = ::write(
            uartFd,
            frame + totalWritten,
            frameLength - totalWritten
        );

        if (written > 0)
        {
            totalWritten +=
                static_cast<std::size_t>(written);

            continue;
        }

        if (written < 0 && errno == EINTR)
        {
            continue;
        }

        if (written < 0 &&
            (errno == EAGAIN ||
             errno == EWOULDBLOCK))
        {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(1)
            );

            continue;
        }

        std::cerr
            << "UART write failed: "
            << std::strerror(errno)
            << '\n';

        return false;
    }

    return true;
}