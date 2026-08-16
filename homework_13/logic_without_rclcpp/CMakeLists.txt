cmake_minimum_required(VERSION 3.20)

# Окремий CMake-проєкт для домашньої роботи 04. Його можна збирати як через root CMakeLists.txt, так
# і напряму з цієї директорії.
project(standalone_turret CXX)

# Код домашньої роботи збирається з тим самим стандартом, що й лекційні приклади.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Один executable для задачі з дз номер 1.
add_executable(standalone_turret
    src/main.cpp
)

target_include_directories(standalone_turret PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Базові compiler warnings допомагають побачити підозрілі місця до runtime.
target_compile_options(standalone_turret PRIVATE -Wall -Wextra -pedantic)