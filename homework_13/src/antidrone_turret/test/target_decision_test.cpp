#include <gtest/gtest.h>

#include <string_view>

#include "antidrone_turret/target_decision.hpp"

namespace {

using logic_split::Decision;
using logic_split::DecisionConfig;
using logic_split::TargetInput;

TEST(TargetDecisionTest, InvisibleTargetKeepsSystemIdle)
{
  const auto decision = logic_split::decide(
    TargetInput{false, 1.0F, 1.0F},
    DecisionConfig{});

  EXPECT_EQ(decision, Decision::kIdle);
}

TEST(TargetDecisionTest, LowConfidenceTargetKeepsSystemIdle)
{
  const auto decision = logic_split::decide(
    TargetInput{true, 0.79F, 10.0F},
    DecisionConfig{0.80F, 30.0F});

  EXPECT_EQ(decision, Decision::kIdle);
}

TEST(TargetDecisionTest, ConfidentDistantTargetIsTracked)
{
  const auto decision = logic_split::decide(
    TargetInput{true, 0.95F, 30.01F},
    DecisionConfig{0.80F, 30.0F});

  EXPECT_EQ(decision, Decision::kTrack);
}

TEST(TargetDecisionTest, TargetOnThresholdRequestsShot)
{
  const auto decision = logic_split::decide(
    TargetInput{true, 0.80F, 30.0F},
    DecisionConfig{0.80F, 30.0F});

  EXPECT_EQ(decision, Decision::kRequestShot);
}

TEST(TargetDecisionTest, DecisionNamesAreStable)
{
  EXPECT_EQ(std::string_view{logic_split::decision_name(Decision::kIdle)}, "IDLE");
  EXPECT_EQ(std::string_view{logic_split::decision_name(Decision::kTrack)}, "TRACK");
  EXPECT_EQ(
    std::string_view{logic_split::decision_name(Decision::kRequestShot)},
    "REQUEST_SHOT");
}

}  // namespace
