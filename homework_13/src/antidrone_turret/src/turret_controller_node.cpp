#include <chrono>
#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "antidrone_turret/msg/target.hpp"
#include "antidrone_turret/msg/servo_command.hpp"
#include "antidrone_turret/msg/gimbal_command.hpp"
#include "antidrone_turret/msg/turret_status.hpp"

namespace {

constexpr auto kTargetTopic = "/perception/target";
constexpr auto kServoCmdTopic = "/servo/cmd";
constexpr auto kGimbalCmdTopic = "/gimbal/cmd";
constexpr auto kTurretStatusTopic = "/turret/status";
constexpr float kFrameCenterX = 320.0F;
constexpr float kFrameCenterY = 240.0F;
constexpr float kConfidenceThreshold = 0.5F;

}  // namespace

class TurretControllerNode final : public rclcpp::Node {
public:
  TurretControllerNode()
    : Node("turret_controller_node")
  {
    servo_cmd_pub_ = create_publisher<antidrone_turret::msg::ServoCommand>(kServoCmdTopic, 10);
    gimbal_cmd_pub_ =
      create_publisher<antidrone_turret::msg::GimbalCommand>(kGimbalCmdTopic, 10);
    status_pub_ = create_publisher<antidrone_turret::msg::TurretStatus>(kTurretStatusTopic, 10);

    target_sub_ = create_subscription<antidrone_turret::msg::Target>(
      kTargetTopic, 10, [this](const antidrone_turret::msg::Target& target) {
        on_target(target);
      });

    RCLCPP_INFO(get_logger(), "TurretControllerNode initialized");
  }

private:
  void on_target(const antidrone_turret::msg::Target& target)
  {
    auto status = antidrone_turret::msg::TurretStatus();
    status.confidence = target.confidence;
    status.distance_m = target.distance_m;

    // Check if target is visible and has sufficient confidence
    if (!target.visible || target.confidence < kConfidenceThreshold) {
      status.target_state = antidrone_turret::msg::TurretStatus::TARGET_NONE;
      status.action = antidrone_turret::msg::TurretStatus::ACTION_IDLE;
      status_pub_->publish(status);

      RCLCPP_DEBUG(
        get_logger(),
        "Target ignored: visible=%d confidence=%.2f",
        target.visible,
        target.confidence);
      return;
    }

    // Create ServoCommand (horizontal control)
    auto servo_cmd = antidrone_turret::msg::ServoCommand();
    servo_cmd.target_x = target.x;
    servo_cmd.error_x = target.x - kFrameCenterX;

    if (servo_cmd.error_x > 0) {
      servo_cmd.direction = antidrone_turret::msg::ServoCommand::RIGHT;
    } else if (servo_cmd.error_x < 0) {
      servo_cmd.direction = antidrone_turret::msg::ServoCommand::LEFT;
    } else {
      servo_cmd.direction = antidrone_turret::msg::ServoCommand::CENTER;
    }

    // Create GimbalCommand (vertical control)
    auto gimbal_cmd = antidrone_turret::msg::GimbalCommand();
    gimbal_cmd.target_y = target.y;
    gimbal_cmd.error_y = kFrameCenterY - target.y;

    if (gimbal_cmd.error_y > 0) {
      gimbal_cmd.direction = antidrone_turret::msg::GimbalCommand::UP;
    } else if (gimbal_cmd.error_y < 0) {
      gimbal_cmd.direction = antidrone_turret::msg::GimbalCommand::DOWN;
    } else {
      gimbal_cmd.direction = antidrone_turret::msg::GimbalCommand::CENTER;
    }

    // Publish commands
    servo_cmd_pub_->publish(servo_cmd);
    gimbal_cmd_pub_->publish(gimbal_cmd);

    // Publish status
    status.target_state = antidrone_turret::msg::TurretStatus::TARGET_LOCKED;
    status.action = antidrone_turret::msg::TurretStatus::ACTION_TRACK;
    status.trigger_state = antidrone_turret::msg::TurretStatus::TRIGGER_SKIP;
    status_pub_->publish(status);

    RCLCPP_DEBUG(
      get_logger(),
      "Published: servo_cmd(x=%.1f error=%.1f dir=%d) gimbal_cmd(y=%.1f error=%.1f dir=%d)",
      servo_cmd.target_x,
      servo_cmd.error_x,
      servo_cmd.direction,
      gimbal_cmd.target_y,
      gimbal_cmd.error_y,
      gimbal_cmd.direction);
  }

  rclcpp::Subscription<antidrone_turret::msg::Target>::SharedPtr target_sub_;
  rclcpp::Publisher<antidrone_turret::msg::ServoCommand>::SharedPtr servo_cmd_pub_;
  rclcpp::Publisher<antidrone_turret::msg::GimbalCommand>::SharedPtr gimbal_cmd_pub_;
  rclcpp::Publisher<antidrone_turret::msg::TurretStatus>::SharedPtr status_pub_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurretControllerNode>());
  rclcpp::shutdown();
  return 0;
}
