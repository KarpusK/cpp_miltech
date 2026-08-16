#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

#include "ballistics.hpp"

bool Reading_Input_file(Input& input)
{
  std::ifstream file("homework_06/data/sample_vog17.txt");

  if (!file.is_open()) {
    std::cerr << "Cannot open file: " << "sample_vog17.txt" << '\n';
    return false;
  }

  if (!(file >> input.xd)) {
    std::cerr << "Field xd is not a number\n";
    return false;
  }

  if (!(file >> input.yd)) {
    std::cerr << "Field yd is not a number\n";
    return false;
  }

  if (!(file >> input.zd)) {
    std::cerr << "Field zd is not a number\n";
    return false;
  }

  if (!(file >> input.targetX)) {
    std::cerr << "Field targetX is not a number\n";
    return false;
  }

  if (!(file >> input.targetY)) {
    std::cerr << "Field targetY is not a number\n";
    return false;
  }

  if (!(file >> input.attackSpeed)) {
    std::cerr << "Field attackSpeed is not a number\n";
    return false;
  }

  if (!(file >> input.accelerationPath)) {
    std::cerr << "Field accelerationPath is not a number\n";
    return false;
  }

  if (!(file >> input.ammo_name)) {
    std::cerr << "Field ammo_name is missing\n";
    return false;
  }

  return true;
};
