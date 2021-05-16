#include "../io.hpp"

#include <gtest/gtest.h>

class IOSaveDataToFileTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    // Save test data  
    IO::save_data_to_file(filename_0, test_data_0);
    IO::save_data_to_file(filename_1, test_data_1);
  }

  virtual void TearDown() {
    // Remove test file
    std::remove(filename_0.c_str());
    std::remove(filename_1.c_str());
  }

  // Normal data
  const std::vector<int> test_data_0{1, 0, -5, 22, -1, 99};
  const std::string correct_0 = "1,0,-5,22,-1,99";
  const std::string filename_0 = "test_saved_data.txt";

  // Empty data
  const std::vector<int> test_data_1{};
  const std::string correct_1 = "";
  const std::string filename_1 = "test_saved_empty_data.txt";
};


TEST_F(IOSaveDataToFileTest, SavesCorrectDataToFile) {
  std::ifstream test_file(filename_0);
  
  std::string f_content((std::istreambuf_iterator<char>(test_file)),
                         std::istreambuf_iterator<char>());

  f_content.erase(std::remove_if(f_content.begin(), f_content.end(), isspace), f_content.end());
  f_content.erase(std::remove(f_content.begin(), f_content.end(), '\n'), f_content.end());

  EXPECT_EQ(correct_0, f_content);
}

TEST_F(IOSaveDataToFileTest, SavesEmptyDataToFile) {
  std::ifstream test_file(filename_1);
  
  std::string f_content((std::istreambuf_iterator<char>(test_file)),
                         std::istreambuf_iterator<char>());

  f_content.erase(std::remove_if(f_content.begin(), f_content.end(), isspace), f_content.end());
  f_content.erase(std::remove(f_content.begin(), f_content.end(), '\n'), f_content.end());

  EXPECT_EQ(correct_1, f_content);
}