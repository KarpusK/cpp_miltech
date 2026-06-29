#include "ballistics.hpp"

#include <gtest/gtest.h>

TEST(Ballistics, ComputesKnownDropPoint)
{
  const Input input{

    .xd = 100.0,

    .yd = 100.0,

    .zd = 100.0,

    .targetX = 200.0,

    .targetY = 200.0,

    .attackSpeed = 10.0,

    .accelerationPath = 10.0,

    .ammo_name = "VOG-17",

  };

  const DropSolution solution = ballistics_logic(input);
  ;

  EXPECT_NEAR(solution.fireX, 173.759, 0.01);

  EXPECT_NEAR(solution.fireY, 173.759, 0.01);
}
