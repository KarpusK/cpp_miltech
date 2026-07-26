#include "ballistics.hpp"

#include <gtest/gtest.h>

TEST(ReadInput, ReadsAllFields)
{
    Input input{};

    EXPECT_FALSE(Reading_Input_file(input));
}
