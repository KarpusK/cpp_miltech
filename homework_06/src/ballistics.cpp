#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <numbers>

#include "ballistics.hpp"

DropSolution ballistics_logic(const Input& input)
{
  const float& xd = input.xd;
  const float& yd = input.yd;
  const float& zd = input.zd;
  const float& targetX = input.targetX;
  const float& targetY = input.targetY;
  const float& attackSpeed = input.attackSpeed;
  const float& accelerationPath = input.accelerationPath;
  const char(&ammo_name)[15] = input.ammo_name;  // NOLINT(cppcoreguidelines-avoid-c-arrays) fixed-size C buffer required by assignment

  double g = 9.81;
  double distx = targetX - xd;
  double disty = targetY - yd;

  double m, d, l;

  double pi = std::numbers::pi;

  if (strcmp(ammo_name, "VOG-17") == 0) {
    m = 0.35;
    d = 0.07;
    l = 0.0;
  }

  else if (strcmp(ammo_name, "M67") == 0) {
    m = 0.6;
    d = 0.1;
    l = 0.0;
  }

  else if (strcmp(ammo_name, "RKG-3") == 0) {
    m = 1.2;
    d = 0.1;
    l = 0.0;
  }

  else if (strcmp(ammo_name, "GLIDING-VOG") == 0) {
    m = 0.45;
    d = 0.07;
    l = 1.0;
  }

  else if (strcmp(ammo_name, "GLIDING-RKG") == 0) {
    m = 1.4;
    d = 0.07;
    l = 1.0;
  }

  else {
    std::cerr << "Unknown ammo type: " << ammo_name << '\n';
  }

  double a = d * g * m - 2 * d * d * l * attackSpeed;
  double b = -3 * g * m * m + 3 * d * l * m * attackSpeed;
  double c = 6 * m * m * zd;

  double dist2d = sqrt(distx * distx + disty * disty);

  if (dist2d < 0) {
    std::cerr << "Negative distance to target: " << dist2d << '\n';
  }

  double p = -b * b / (3 * a * a);
  double q = 2 * b * b * b / (27 * a * a * a) + c / a;

  if (p > 0) {
    std::cerr << "Warning. P > 0: " << p << '\n';
  }

  // std::cout << "P value: " << p << std::endl;
  // std::cout << "Q value: " << q << std::endl;

  double val = ((3 * q) / (2 * p)) * sqrt(-3 / p);  // аргумент арккосинуса
  double phi = std::acos(val);

  if (val < -1 || val > 1) {
    std::cout << "Argument out of range: " << val << '\n';
  }

  // std::cout << "Argument: " << val << std::endl;

  double t = 2 * sqrt(-p / 3) * std::cos((phi + 4 * pi) / 3) - (b / (3 * a));

  if (t < 0) {
    std::cerr << "Negative flight time: " << t << '\n';
  }

  double term1 = attackSpeed * t;
  double term2 = -1 * (t * t * d * attackSpeed / (2 * m));
  double term3 = t * t * t * (6 * d * g * l * m - 6 * d * d * (l * l - 1) * attackSpeed) / (36 * m * m);
  double term4 = std::pow(t, 4) *
                 (-6 * d * d * g * l * (1 + l * l + std::pow(l, 4)) * m + 3 * d * d * d * l * l * (1 + l * l) * attackSpeed +
                  6 * d * d * d * std::pow(l, 4) * (1 + l * l) * attackSpeed) /
                 (36 * std::pow(1 + l * l, 2) * m * m * m);
  double term5 = std::pow(t, 5) * (3 * d * d * d * g * l * l * l * m - 3 * d * d * d * d * l * l * (1 + l * l) * attackSpeed) /
                 (36 * (1 + l * l) * m * m * m * m);

  double h = term1 + term2 + term3 + term4 + term5;

  if (h < 0) {
    std::cerr << "Negative horizontal distance: " << h << '\n';
  }

  double ratio = (dist2d - h) / dist2d;

  DropSolution result;

  if (h + accelerationPath > dist2d) {
    double xd2 = targetX - (targetX - xd) * (h + accelerationPath) / dist2d;
    double yd2 = targetY - (targetY - yd) * (h + accelerationPath) / dist2d;

    result.fireX = xd2 + (targetX - xd2) * ratio;
    result.fireY = yd2 + (targetY - yd2) * ratio;

    std::cout << "Arm launch coordinates: " << result.fireX << " " << result.fireY << '\n';
    std::cout << "Man.coordinates: " << xd2 << " " << yd2 << '\n';

    std::ofstream fout("output.txt");
    fout << xd2 << " " << yd2 << " " << result.fireX << " " << result.fireY;
  }
  else {
    result.fireX = xd + (targetX - xd) * ratio;
    result.fireY = yd + (targetY - yd) * ratio;

    std::cout << "Arm launch coordinates: " << result.fireX << " " << result.fireY << '\n';

    std::ofstream fout("homework_06/out/output.txt");
    fout << result.fireX << " " << result.fireY;
  }

  return result;
}