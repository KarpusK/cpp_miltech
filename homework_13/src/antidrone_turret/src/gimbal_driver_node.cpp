#include <memory>

#include <rclcpp/rclcpp.hpp>

#include "antidrone_turret/msg/gimbal_command.hpp"

namespace {

constexpr auto kGimbalCmdTopic = "/gimbal/cmd";

}  // namespace

class GimbalDriverNode final : public rclcpp::Node {
public:
  GimbalDriverNode()
    : Node("gimbal_driver_node")
  {
    subscription_ = create_subscription<antidrone_turret::msg::GimbalCommand>(
      kGimbalCmdTopic, 10, [this](const antidrone_turret::msg::GimbalCommand& cmd) {
        on_gimbal_command(cmd);
      });

    RCLCPP_INFO(get_logger(), "GimbalDriverNode initialized, waiting for commands");
  }

private:
  void on_gimbal_command(const antidrone_turret::msg::GimbalCommand& cmd)
  {
    const char* direction_str = "UNKNOWN";
    if (cmd.direction == antidrone_turret::msg::GimbalCommand::UP) {
      direction_str = "UP";
    } else if (cmd.direction == antidrone_turret::msg::GimbalCommand::DOWN) {
      direction_str = "DOWN";
    } else if (cmd.direction == antidrone_turret::msg::GimbalCommand::CENTER) {
      direction_str = "CENTER";
    }

    RCLCPP_INFO(
      get_logger(),
      "gimbal_driver_node received: direction=%s target_y=%.1f error_y=%.1f",
      direction_str,
      cmd.target_y,
      cmd.error_y);
  }

  rclcpp::Subscription<antidrone_turret::msg::GimbalCommand>::SharedPtr subscription_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GimbalDriverNode>());
  rclcpp::shutdown();
  return 0;
}
