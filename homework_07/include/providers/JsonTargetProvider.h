#pragma once

#include "interfaces/ITargetProvider.h"

#include <string>

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
    Target targets_[5];
};
