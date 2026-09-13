cmake_minimum_required(VERSION 3.14)
project(server_app VERSION 1.0 LANGUAGES CXX)

# 1. Встановлюємо стандарт C++11 або вище (httplib вимагає мінімум C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server_app main.cpp)

target_include_directories(server_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
