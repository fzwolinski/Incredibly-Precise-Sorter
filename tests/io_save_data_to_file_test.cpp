#include "../io.hpp"

#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

class IOSaveDataToFileTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    // Save test data  
    IO::save_data_to_file(filename, test_data);
  }

  virtual void TearDown() {
    // Remove test file
    std::remove(filename.c_str());
  }

  std::vector<int> test_data{1, 0, -5, 22, -1, 99};
  const std::string filename = "test_saved_data.txt";
};


TEST_F(IOSaveDataToFileTest, SavesCorrectDataToFile) {
  // Read file and save data as string
  std::string line, cur_line, nums;
  std::ifstream test_file(filename);
  
  while(getline(test_file, line)) {
    std::stringstream ss(line);
    getline(ss, cur_line);
    nums += cur_line;
  }
  test_file.close();

  // Parse string -> vector of ints
  std::vector<int> read_data;
  std::stringstream ss(nums);

  for (int i; ss >> i;) {
    read_data.push_back(i);    
    if (ss.peek() == ',') {
      ss.ignore();
    }
  }

  EXPECT_EQ(test_data, read_data);
}