#pragma once

#include "target.hpp"

class ITargetProvider
{
public:
    virtual ~ITargetProvider() = default;

    virtual bool load() = 0;
    virtual int getTargetCount() const = 0;
    virtual Target getTarget(int index) const = 0;
    virtual Coord getTargetPosition(int targetIndex, int timeIndex) const = 0;
};
