#pragma once

#include <string_view>

#include "antidrone_turret/target_sequence.hpp"

namespace antidrone_turret {

struct ServoCommand {
  enum class Direction {
    kCenter,
    kLeft,
    kRight,
  };

  float target_x{0.0F};
  float error_x{0.0F};
  Direction direction{Direction::kCenter};
};

struct GimbalCommand {
  enum class Direction {
    kCenter,
    kUp,
    kDown,
  };

  float target_y{0.0F};
  float error_y{0.0F};
  Direction direction{Direction::kCenter};
};

struct TurretStatus {
  enum class TargetState {
    kNone,
    kLocked,
  };

  enum class Action {
    kIdle,
    kTrack,
  };

  enum class TriggerState {
    kSkip,
    kReady,
  };

  float confidence{0.0F};
  float distance_m{0.0F};
  TargetState target_state{TargetState::kNone};
  Action action{Action::kIdle};
  TriggerState trigger_state{TriggerState::kSkip};
};

struct TurretControlCommand {
  ServoCommand servo;
  GimbalCommand gimbal;
  TurretStatus status;
};

class TurretController {
public:
  explicit TurretController(
    float frame_center_x = 320.0F,
    float frame_center_y = 240.0F,
    float confidence_threshold = 0.5F)
    : frame_center_x_(frame_center_x)
    , frame_center_y_(frame_center_y)
    , confidence_threshold_(confidence_threshold)
  {}

  [[nodiscard]] TurretControlCommand process_target(const TargetSample& target) const
  {
    TurretControlCommand command{};

    command.status.confidence = target.confidence;
    command.status.distance_m = target.distance_m;

    if (!target.visible || target.confidence < confidence_threshold_) {
      command.status.target_state = TurretStatus::TargetState::kNone;
      command.status.action = TurretStatus::Action::kIdle;
      command.status.trigger_state = TurretStatus::TriggerState::kSkip;
      return command;
    }

    command.servo.target_x = target.x;
    command.servo.error_x = target.x - frame_center_x_;
    if (command.servo.error_x > 0.0F) {
      command.servo.direction = ServoCommand::Direction::kRight;
    } else if (command.servo.error_x < 0.0F) {
      command.servo.direction = ServoCommand::Direction::kLeft;
    } else {
      command.servo.direction = ServoCommand::Direction::kCenter;
    }

    command.gimbal.target_y = target.y;
    command.gimbal.error_y = frame_center_y_ - target.y;
    if (command.gimbal.error_y > 0.0F) {
      command.gimbal.direction = GimbalCommand::Direction::kUp;
    } else if (command.gimbal.error_y < 0.0F) {
      command.gimbal.direction = GimbalCommand::Direction::kDown;
    } else {
      command.gimbal.direction = GimbalCommand::Direction::kCenter;
    }

    command.status.target_state = TurretStatus::TargetState::kLocked;
    command.status.action = TurretStatus::Action::kTrack;
    command.status.trigger_state = TurretStatus::TriggerState::kSkip;
    return command;
  }

  [[nodiscard]] bool should_fire(const TargetSample& target) const
  {
    return target.visible && target.confidence >= confidence_threshold_;
  }

private:
  float frame_center_x_;
  float frame_center_y_;
  float confidence_threshold_;
};

inline std::string_view to_string(ServoCommand::Direction direction)
{
  switch (direction) {
    case ServoCommand::Direction::kLeft:
      return "left";
    case ServoCommand::Direction::kRight:
      return "right";
    case ServoCommand::Direction::kCenter:
    default:
      return "center";
  }
}

inline std::string_view to_string(GimbalCommand::Direction direction)
{
  switch (direction) {
    case GimbalCommand::Direction::kUp:
      return "up";
    case GimbalCommand::Direction::kDown:
      return "down";
    case GimbalCommand::Direction::kCenter:
    default:
      return "center";
  }
}

inline std::string_view to_string(TurretStatus::TargetState state)
{
  switch (state) {
    case TurretStatus::TargetState::kLocked:
      return "locked";
    case TurretStatus::TargetState::kNone:
    default:
      return "none";
  }
}

inline std::string_view to_string(TurretStatus::Action action)
{
  switch (action) {
    case TurretStatus::Action::kTrack:
      return "track";
    case TurretStatus::Action::kIdle:
    default:
      return "idle";
  }
}

}  // namespace antidrone_turret
