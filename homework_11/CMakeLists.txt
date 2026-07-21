cmake_minimum_required(VERSION 3.20)
project(drone_fsm CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GPIOD REQUIRED libgpiod)

add_executable(homework_11_drone_fsm_cli
    src/main.cpp
    src/ballistics.cpp
    src/AnalyticalSolver.cpp
    src/MissionProcessor.cpp
    src/TelemetryParser.cpp
    src/DroneControl.cpp
)

target_include_directories(homework_11_drone_fsm_cli PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${GPIOD_INCLUDE_DIRS}
)

target_link_directories(homework_11_drone_fsm_cli PRIVATE
    ${GPIOD_LIBRARY_DIRS}
)

target_link_libraries(homework_11_drone_fsm_cli PRIVATE
    Threads::Threads
    ${GPIOD_LIBRARIES}
)

target_compile_options(homework_11_drone_fsm_cli PRIVATE
    -Wall
    -Wextra
    -pedantic
    ${GPIOD_CFLAGS_OTHER}
)
