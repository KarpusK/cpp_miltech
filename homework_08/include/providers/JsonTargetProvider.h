#pragma once

#include "interfaces/ITargetProvider.h"

#include <string>
#include <array>


class JsonTargetProvider : public ITargetProvider
{
public:
    JsonTargetProvider();
    explicit JsonTargetProvider(const std::string& targetsPath);

    bool load() override;
    int getTargetCount() const override;
    Target getTarget(int index) const override;
    Coord getTargetPosition(int targetIndex, int timeIndex) const override;

private:
    std::string targetsPath_;
    std::array<Target, 5> targets_;
};
