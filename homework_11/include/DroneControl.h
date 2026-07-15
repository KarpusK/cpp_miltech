#pragma once

#include "drone_link.h"

#include <gpiod.h>

#include <string>

class DroneControl
{
public:
    DroneControl(
        std::string chipName,
        unsigned int startLine,
        unsigned int dropLine
    );

    ~DroneControl();

    DroneControl(const DroneControl&) = delete;
    DroneControl& operator=(const DroneControl&) = delete;

    bool init();
    bool signalReady();
    bool dropPayload();

    bool sendControl(
        int uartFd,
        const dlink::Control& control
    );

private:
    std::string chipName_;

    unsigned int startLineNumber_;
    unsigned int dropLineNumber_;

    struct gpiod_chip* chip_ = nullptr;
    struct gpiod_line_request* lineRequest_ = nullptr;
};
