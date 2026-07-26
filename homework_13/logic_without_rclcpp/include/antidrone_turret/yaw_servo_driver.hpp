#pragma once

#include <algorithm>
#include <cmath>

namespace antidrone_turret {

class YawServoDriver {
public:
  explicit YawServoDriver(float max_step_per_tick = 5.0F, float neutral_angle = 90.0F)
    : max_step_per_tick_(max_step_per_tick)
    , neutral_angle_(neutral_angle)
    , target_angle_(neutral_angle)
  {}

  void update_from_error(float error_x)
  {
    const auto clamped_error = std::clamp(error_x, -max_step_per_tick_, max_step_per_tick_);
    target_angle_ = neutral_angle_ + clamped_error;
  }

  [[nodiscard]] float target_angle() const
  {
    return target_angle_;
  }

  [[nodiscard]] float neutral_angle() const
  {
    return neutral_angle_;
  }

private:
  float max_step_per_tick_;
  float neutral_angle_;
  float target_angle_;
};

}  // namespace antidrone_turret
