#include "../io.hpp"

#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <cstdio>

class InputOutputTest : public ::testing::Test {
protected:
  virtual void SetUp() { 
    test_numbers = {5, 0, 2, 5, 6, -99, 3};
    
    // Create file with numbers
    std::ofstream f ("test_file_with_numbers.txt");
    for(auto num : test_numbers) {
      f << num << "\n";
    }
    f.close();

    // Empty file [For checking exception]
    std::ofstream empty_f ("empty_test_file.txt");
    empty_f << "";
    empty_f.close();
   }

  virtual void TearDown() {
    // Remove test files
    std::remove("test_file_with_numbers.txt");
    std::remove("empty_test_file.txt");
  }

  std::vector<int> test_numbers;
};

TEST_F(InputOutputTest, LoadDataShouldProperlyLoadNumbersFromFile) {
  auto data = IO::load_data("test_file_with_numbers.txt");

  EXPECT_EQ(test_numbers, data);  
}

TEST_F(InputOutputTest, ShouldThrowExceptionWhileLoadingEmptyFile) {
  try {
    auto data = IO::load_data("empty_test_file.txt");
  }
  catch(std::invalid_argument const& e) {
    EXPECT_STREQ("Error reading file", e.what());
  }
}