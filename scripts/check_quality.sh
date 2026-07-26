#!/bin/bash

set -e

echo "Formatting code..."
clang-format -i homework_06/include/ballistics.hpp

clang-format -i homework_06/src/ballistics.cpp
  
clang-format -i homework_06/src/Read_Input.cpp

clang-format -i homework_06/src/main.cpp

clang-format -i homework_06/tests/ballistics_tests.cpp


echo "Running clang-tidy..."
run-clang-tidy -p build/debug homework_06

echo "Build project..."
cmake --build --preset debug

echo "Run tests..."
ctest --test-dir build/debug/homework_06 --output-on-failure

echo "Quality check passed."