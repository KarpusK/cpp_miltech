cmake_minimum_required(VERSION 3.14)
project(i2c_dev_serv VERSION 1.0 LANGUAGES CXX)

# 1. Встановлюємо стандарт C++11 або вище (httplib вимагає мінімум C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Шукаємо встановлену в системі cpp-httplib
#find_package(... REQUIRED)

# 3. Створюємо наш виконуваний файл із main.cpp
add_executable(i2c_dev main.cpp)

# 4. Лінкуємо httplib до нашого сервера
# Це автоматично підключить правильні шляхи (include) та мережеві залежності
#target_link_libraries(i2c_dev PRIVATE httplib::httplib)