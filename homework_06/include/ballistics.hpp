#pragma once

struct Input {
  float xd;
  float yd;
  float zd;
  float targetX;
  float targetY;
  float attackSpeed;
  float accelerationPath;
  char ammo_name[15];  // NOLINT(cppcoreguidelines-avoid-c-arrays) fixed-size C buffer required by assignment
};

struct DropSolution {
  double fireX;
  double fireY;
};

// Input input;

bool Reading_Input_file(Input& input);
DropSolution ballistics_logic(const Input& input);