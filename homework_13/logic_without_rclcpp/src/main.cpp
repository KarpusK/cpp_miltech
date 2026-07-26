#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "antidrone_turret/gimbal_driver.hpp"
#include "antidrone_turret/target_sequence.hpp"
#include "antidrone_turret/target_track_loader.hpp"
#include "antidrone_turret/turret_controller.hpp"
#include "antidrone_turret/yaw_servo_driver.hpp"

namespace {

using antidrone_turret::GimbalCommand;
using antidrone_turret::GimbalDriver;
using antidrone_turret::ServoCommand;
using antidrone_turret::TargetSample;
using antidrone_turret::TurretControlCommand;
using antidrone_turret::TurretController;
using antidrone_turret::YawServoDriver;

void print_usage(const char* argv0)
{
  std::cout << "Usage: " << argv0 << " [track_file.csv]" << std::endl;
}

void print_command(const TurretControlCommand& command)
{
  std::cout << "servo=" << antidrone_turret::to_string(command.servo.direction)
            << " target_x=" << command.servo.target_x
            << " error_x=" << command.servo.error_x << '\n';
  std::cout << "gimbal=" << antidrone_turret::to_string(command.gimbal.direction)
            << " target_y=" << command.gimbal.target_y
            << " error_y=" << command.gimbal.error_y << '\n';
  std::cout << "status=" << antidrone_turret::to_string(command.status.target_state)
            << " action=" << antidrone_turret::to_string(command.status.action)
            << " confidence=" << command.status.confidence << '\n';
}

}  // namespace

int main(int argc, char** argv)
{
  if (argc > 2) {
    print_usage(argv[0]);
    return EXIT_FAILURE;
  }

  const auto tracks_dir = std::filesystem::path(__FILE__).parent_path().parent_path() / "tracks";
  std::vector<TargetSample> samples;

  if (argc == 2) {
    const auto load_result = antidrone_turret::load_target_track_csv(tracks_dir / argv[1]);
    if (!load_result.error.empty()) {
      std::cerr << load_result.error << std::endl;
      return EXIT_FAILURE;
    }
    samples = load_result.samples;
  } else {
    const auto load_result = antidrone_turret::load_target_track_csv_files(
      tracks_dir,
      antidrone_turret::default_target_track_files());
    if (!load_result.error.empty()) {
      std::cerr << load_result.error << std::endl;
      return EXIT_FAILURE;
    }
    samples = load_result.samples;
  }

  TurretController controller;
  YawServoDriver servo_driver;
  GimbalDriver gimbal_driver;

  std::cout << "Standalone turret controller" << std::endl;
  for (const auto& sample : samples) {
    const auto command = controller.process_target(sample);
    servo_driver.update_from_error(command.servo.error_x);
    gimbal_driver.update_from_error(command.gimbal.error_y);
    print_command(command);
    std::cout << "yaw_angle=" << servo_driver.target_angle() << std::endl;
    std::cout << "gimbal_angle=" << gimbal_driver.target_angle() << std::endl;
    std::cout << "---" << std::endl;
  }

  return EXIT_SUCCESS;
}
