cmake_minimum_required(VERSION 3.14)
project(CourseServer VERSION 1.0 LANGUAGES CXX)

# 1. Встановлюємо стандарт C++11 або вище (httplib вимагає мінімум C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Шукаємо встановлену в системі cpp-httplib
find_package(httplib CONFIG REQUIRED)

# 3. Створюємо наш виконуваний файл із main.cpp
add_executable(server_app main.cpp)

# 4. Лінкуємо httplib до нашого сервера
# Це автоматично підключить правильні шляхи (include) та мережеві залежності
target_link_libraries(server_app PRIVATE httplib::httplib)
