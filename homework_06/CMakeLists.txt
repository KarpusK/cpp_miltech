cmake_minimum_required(VERSION 3.20)

# Окремий CMake-проєкт для домашньої роботи 04. Його можна збирати як через root CMakeLists.txt, так
# і напряму з цієї директорії.
project(balistics_cli CXX)

# Код домашньої роботи збирається з тим самим стандартом, що й лекційні приклади.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Один executable для задачі з дз номер 1.
add_executable(ballistics_cli src/main.cpp)

add_library(ballistics src/ballistics.cpp src/Read_Input.cpp)

target_include_directories(ballistics PUBLIC include)

target_link_libraries(ballistics_cli PRIVATE ballistics)

# Базові compiler warnings допомагають побачити підозрілі місця до runtime.
target_compile_options(ballistics PRIVATE -Wall -Wextra -pedantic)
target_compile_options(ballistics_cli PRIVATE -Wall -Wextra -pedantic)

if(NOT CMAKE_CROSSCOMPILING)

    include(FetchContent)

    include(GoogleTest)

    FetchContent_Declare(
        googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
                       DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

    FetchContent_MakeAvailable(googletest)

    enable_testing()

    # add_library(ballistics_tests tests/ballistics_tests.cpp)

    add_executable(ballistics_tests tests/ballistics_tests.cpp tests/Correct_values_test.cpp)

    target_link_libraries(ballistics_tests PRIVATE ballistics GTest::gtest_main)

    gtest_discover_tests(ballistics_tests DISCOVERY_MODE PRE_TEST)
endif()
