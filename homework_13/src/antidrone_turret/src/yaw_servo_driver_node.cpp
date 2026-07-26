#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "antidrone_turret/msg/servo_command.hpp"

namespace {

constexpr auto kServoCmdTopic = "/servo/cmd";

}  // namespace

class YawServoDriverNode final : public rclcpp::Node {
public:
  YawServoDriverNode()
    : Node("yaw_servo_driver_node")
  {
    subscription_ = create_subscription<antidrone_turret::msg::ServoCommand>(
      kServoCmdTopic, 10, [this](const antidrone_turret::msg::ServoCommand& cmd) {
        on_servo_command(cmd);
      });

    RCLCPP_INFO(get_logger(), "YawServoDriverNode initialized, waiting for commands");
  }

private:
  void on_servo_command(const antidrone_turret::msg::ServoCommand& cmd)
  {
    const char* direction_str = "UNKNOWN";
    if (cmd.direction == antidrone_turret::msg::ServoCommand::RIGHT) {
      direction_str = "RIGHT";
    } else if (cmd.direction == antidrone_turret::msg::ServoCommand::LEFT) {
      direction_str = "LEFT";
    } else if (cmd.direction == antidrone_turret::msg::ServoCommand::CENTER) {
      direction_str = "CENTER";
    }

    RCLCPP_INFO(
      get_logger(),
      "yaw_servo_driver_node received: direction=%s target_x=%.1f error_x=%.1f",
      direction_str,
      cmd.target_x,
      cmd.error_x);
  }

  rclcpp::Subscription<antidrone_turret::msg::ServoCommand>::SharedPtr subscription_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<YawServoDriverNode>());
  rclcpp::shutdown();
  return 0;
}
