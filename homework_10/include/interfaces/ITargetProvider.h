#pragma once

#include "target.hpp"

class ITargetProvider
{
public:
    virtual ~ITargetProvider() = default;
    virtual bool load() = 0;
    virtual void run() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual bool isThreadReady() const = 0;
    virtual int getTargetCount() const = 0;
    virtual Target getTarget(int index) const = 0;
};
