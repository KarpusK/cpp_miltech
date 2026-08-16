cmake_minimum_required(VERSION 3.20)
project(mission_solution)

# C++20 - базовий стандарт курсу.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ament_auto бере залежності з package.xml і тримає CMake коротшим.
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(mission_explorer
  src/mission_explorer.cpp
)

ament_target_dependencies(
  mission_explorer
  rclcpp
  underground_world
)

ament_auto_add_executable(payload_action
  src/payload_action.cpp
)

ament_target_dependencies(
  payload_action
  rclcpp
  underground_world
)

install(
  TARGETS
    mission_explorer
    payload_action
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()