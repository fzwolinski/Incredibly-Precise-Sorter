#include "../sorting_alg.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(SortAlgorithmTest, MergeSortSortsCorrectly) {
  EXPECT_EQ(sorted_0, SortingAlg::merge_sort(unsorted_0));
  EXPECT_EQ(sorted_1, SortingAlg::merge_sort(unsorted_1));
  EXPECT_EQ(sorted_2, SortingAlg::merge_sort(unsorted_2));
  EXPECT_EQ(sorted_3, SortingAlg::merge_sort(unsorted_3));
}

TEST(SortAlgorithmTest, MergeSortReturnsCorrectNumQty) {
  EXPECT_EQ(3, (SortingAlg::merge_sort(qty_vector_0)).size());
  EXPECT_EQ(1, (SortingAlg::merge_sort(qty_vector_1)).size());
}
