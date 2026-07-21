#pragma once

#include "drone_link.h"

#include <gpiod.h>
#include <string>

class DroneControl
{
public:
    DroneControl(std::string chipName,
                 unsigned int startLine,
                 unsigned int dropLine);
    ~DroneControl();

    DroneControl(const DroneControl&) = delete;
    DroneControl& operator=(const DroneControl&) = delete;
    DroneControl(DroneControl&&) = delete;
    DroneControl& operator=(DroneControl&&) = delete;

    bool init();
    bool signalReady();
    bool dropPayload();
    bool sendControl(int uartFd, const dlink::Control& control);

private:
    std::string chipName_;
    unsigned int startLineNumber_;
    unsigned int dropLineNumber_;

    gpiod_chip* chip_ = nullptr;
    gpiod_line* startLine_ = nullptr;
    gpiod_line* dropLine_ = nullptr;
    bool initialized_ = false;
    bool dropped_ = false;
};
