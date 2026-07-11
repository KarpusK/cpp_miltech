cmake_minimum_required(VERSION 3.20)

# Окремий CMake-проєкт для домашньої роботи 04. Його можна збирати як через root CMakeLists.txt, так
# і напряму з цієї директорії.
project(drone_fsm CXX)

# Код домашньої роботи збирається з тим самим стандартом, що й лекційні приклади.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Один executable для задачі з дз номер 1.
add_executable(drone_fsm_cli
    src/main.cpp
    src/ballistics.cpp
    src/Factory.cpp
    src/FileConfigLoader.cpp
    src/JsonTargetProvider.cpp
    src/AnalyticalSolver.cpp
    src/MissionProcessor.cpp
)

target_include_directories(drone_fsm_cli PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_custom_command(TARGET drone_fsm_cli POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:drone_fsm_cli>/data
)

# Базові compiler warnings допомагають побачити підозрілі місця до runtime.
target_compile_options(drone_fsm_cli PRIVATE -Wall -Wextra -pedantic)
