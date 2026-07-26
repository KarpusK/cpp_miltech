#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include "antidrone_turret/target_sequence.hpp"
#include "antidrone_turret/target_track_loader.hpp"
#include "antidrone_turret/target_track_simulation.hpp"

namespace {

class TemporaryCsvFile {
public:
  explicit TemporaryCsvFile(const std::string& name)
    : path_(std::filesystem::temp_directory_path() / name)
  {}

  ~TemporaryCsvFile()
  {
    std::error_code error;
    std::filesystem::remove(path_, error);
  }

  [[nodiscard]] const std::filesystem::path& path() const
  {
    return path_;
  }

private:
  std::filesystem::path path_;
};

TEST(TargetSequenceEdgeTest, EmptySequenceIsFinishedWithoutRepeat)
{
  const auto sequence = antidrone_turret::TargetSequence{};

  EXPECT_TRUE(sequence.empty());
  EXPECT_EQ(sequence.size(), 0U);
  EXPECT_TRUE(sequence.finished(false));
}

TEST(TargetSequenceEdgeTest, SkipOnEmptySequenceIsSafe)
{
  auto sequence = antidrone_turret::TargetSequence{};

  EXPECT_NO_THROW(sequence.skip_to_next_track());
  EXPECT_TRUE(sequence.empty());
}

TEST(TargetTrackLoaderEdgeTest, ParsesWhitespaceAndNumericBooleans)
{
  TemporaryCsvFile file{"antidrone_turret_whitespace_track.csv"};
  {
    std::ofstream output{file.path()};
    output << " visible , x , y , distance_m , confidence \n";
    output << " 1 , 320.5 , 240 , 29.5 , 0.8 \n";
    output << " 0 , 100 , 200 , 50 , 0.4 \n";
  }

  const auto result = antidrone_turret::load_target_track_csv(file.path());

  ASSERT_TRUE(result.error.empty()) << result.error;
  ASSERT_EQ(result.samples.size(), 2U);
  EXPECT_TRUE(result.samples[0].visible);
  EXPECT_FLOAT_EQ(result.samples[0].x, 320.5F);
  EXPECT_FALSE(result.samples[1].visible);
}

TEST(TargetTrackLoaderEdgeTest, ReportsInvalidBooleanWithLineNumber)
{
  TemporaryCsvFile file{"antidrone_turret_invalid_bool.csv"};
  {
    std::ofstream output{file.path()};
    output << "visible,x,y,distance_m,confidence\n";
    output << "yes,320,240,30,0.9\n";
  }

  const auto result = antidrone_turret::load_target_track_csv(file.path());

  EXPECT_TRUE(result.samples.empty());
  EXPECT_NE(result.error.find("line 2"), std::string::npos);
}

TEST(TargetTrackLoaderEdgeTest, CombinedTracksContainSeparatingGap)
{
  const auto directory = std::filesystem::temp_directory_path() /
    "antidrone_turret_combined_tracks";
  std::filesystem::create_directories(directory);

  const auto first_path = directory / "first.csv";
  const auto second_path = directory / "second.csv";
  {
    std::ofstream first{first_path};
    first << "true,10,20,40,0.9\n";
    std::ofstream second{second_path};
    second << "true,30,40,20,0.95\n";
  }

  const auto result = antidrone_turret::load_target_track_csv_files(
    directory,
    std::vector<std::string>{"first.csv", "second.csv"});

  std::error_code error;
  std::filesystem::remove_all(directory, error);

  ASSERT_TRUE(result.error.empty()) << result.error;
  ASSERT_EQ(result.samples.size(), 4U);
  EXPECT_TRUE(result.samples[0].visible);
  EXPECT_FALSE(result.samples[1].visible);
  EXPECT_TRUE(result.samples[2].visible);
  EXPECT_FALSE(result.samples[3].visible);
}

TEST(TargetTrackSimulationEdgeTest, EmptySimulationProducesNoTarget)
{
  auto simulation = antidrone_turret::TargetTrackSimulation{};

  EXPECT_TRUE(simulation.empty());
  EXPECT_FALSE(simulation.next_target().has_value());
  EXPECT_FALSE(simulation.apply_actuator_status(true, 1U));
}

TEST(TargetTrackSimulationEdgeTest, TriggerBeforeHitWindowDoesNotSkipTrack)
{
  auto config = antidrone_turret::TargetTrackSimulationConfig{};
  config.repeat_sequence = false;

  auto simulation = antidrone_turret::TargetTrackSimulation{
    antidrone_turret::TargetSequence{
      std::vector<antidrone_turret::TargetSample>{
        {true, 10.0F, 20.0F, 60.0F, 0.95F},
        {true, 11.0F, 21.0F, 20.0F, 0.95F},
      }},
    config};

  const auto first = simulation.next_target();
  ASSERT_TRUE(first.has_value());
  EXPECT_FALSE(simulation.apply_actuator_status(false, 1U));

  const auto second = simulation.next_target();
  ASSERT_TRUE(second.has_value());
  EXPECT_FLOAT_EQ(second->sample.x, 11.0F);
}


TEST(TargetTrackLoaderEdgeTest, SkipsCommentsAndBlankLines)
{
  TemporaryCsvFile file{"antidrone_turret_comments_track.csv"};
  {
    std::ofstream output{file.path()};
    output << "# generated test track\n";
    output << "\n";
    output << "true,12,24,18,0.91\n";
    output << "   # another comment\n";
    output << "false,0,0,0,0\n";
  }

  const auto result = antidrone_turret::load_target_track_csv(file.path());

  ASSERT_TRUE(result.error.empty()) << result.error;
  ASSERT_EQ(result.samples.size(), 2U);
  EXPECT_TRUE(result.samples.front().visible);
  EXPECT_FALSE(result.samples.back().visible);
}

TEST(TargetTrackLoaderEdgeTest, MissingFileReturnsHelpfulError)
{
  const auto missing_path = std::filesystem::temp_directory_path() /
    "antidrone_turret_file_that_does_not_exist.csv";
  std::error_code error;
  std::filesystem::remove(missing_path, error);

  const auto result = antidrone_turret::load_target_track_csv(missing_path);

  EXPECT_TRUE(result.samples.empty());
  EXPECT_NE(result.error.find("cannot open target track file"), std::string::npos);
  EXPECT_NE(result.error.find(missing_path.filename().string()), std::string::npos);
}

TEST(TargetSequenceEdgeTest, SkipMovesToFirstVisibleSampleAfterGap)
{
  auto sequence = antidrone_turret::TargetSequence{
    std::vector<antidrone_turret::TargetSample>{
      {true, 10.0F, 20.0F, 50.0F, 0.9F},
      {false, 0.0F, 0.0F, 0.0F, 0.0F},
      {false, 0.0F, 0.0F, 0.0F, 0.0F},
      {true, 30.0F, 40.0F, 25.0F, 0.95F},
    }};

  sequence.skip_to_next_track();

  EXPECT_FLOAT_EQ(sequence.current().x, 30.0F);
  EXPECT_FLOAT_EQ(sequence.current().y, 40.0F);
}

TEST(TargetTrackSimulationEdgeTest, RepeatedTriggerCountIsIgnored)
{
  auto config = antidrone_turret::TargetTrackSimulationConfig{};
  config.repeat_sequence = false;

  auto simulation = antidrone_turret::TargetTrackSimulation{
    antidrone_turret::TargetSequence{
      std::vector<antidrone_turret::TargetSample>{
        {true, 10.0F, 20.0F, 20.0F, 0.95F},
        {false, 0.0F, 0.0F, 0.0F, 0.0F},
        {true, 30.0F, 40.0F, 20.0F, 0.95F},
      }},
    config};

  ASSERT_TRUE(simulation.next_target().has_value());
  EXPECT_TRUE(simulation.apply_actuator_status(true, 1U));

  ASSERT_TRUE(simulation.next_target().has_value());
  EXPECT_FALSE(simulation.apply_actuator_status(true, 1U));
}

}  // namespace
