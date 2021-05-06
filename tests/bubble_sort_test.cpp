#include "../sorting_alg.hpp"
#include <gtest/gtest.h>
#include <vector>

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
