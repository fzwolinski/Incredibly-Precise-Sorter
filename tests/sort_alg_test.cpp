#include "../sorting_alg.hpp"
#include <gtest/gtest.h>
#include <vector>

// // For correct sort
std::vector<int> unsorted_0{1, 0, -5, 99, -5};
std::vector<int> sorted_0{-5, -5, 0, 1, 99};

std::vector<int> unsorted_1{0, 0, 0, 0};
std::vector<int> sorted_1{0, 0, 0, 0};

std::vector<int> unsorted_2{1, 2, 3, 4};
std::vector<int> sorted_2{1, 2, 3, 4};

std::vector<int> unsorted_3{1};
std::vector<int> sorted_3{1};

// // For correct sorted vector size
std::vector<int> qty_vector_0{-5, 2, 0};
std::vector<int> qty_vector_1{0};

TEST(SortAlgorithmTest, BubbleSortSortsCorrectly) {
  EXPECT_EQ(sorted_0, SortingAlg::bubble_sort(unsorted_0));
  EXPECT_EQ(sorted_1, SortingAlg::bubble_sort(unsorted_1));
  EXPECT_EQ(sorted_2, SortingAlg::bubble_sort(unsorted_2));
  EXPECT_EQ(sorted_3, SortingAlg::bubble_sort(unsorted_3));
}

TEST(SortAlgorithmTest, BubbleSortReturnsCorrectNumQty) {
  EXPECT_EQ(3, (SortingAlg::bubble_sort(qty_vector_0)).size());
  EXPECT_EQ(1, (SortingAlg::bubble_sort(qty_vector_1)).size());
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}