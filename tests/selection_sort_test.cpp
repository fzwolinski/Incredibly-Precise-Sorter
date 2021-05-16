#include "../sorting_alg.hpp"
#include <gtest/gtest.h>

TEST(SortAlgorithmTest, SelectionSortSortsCorrectly) {
  EXPECT_EQ(sorted_0, SortingAlg::selection_sort(unsorted_0));
  EXPECT_EQ(sorted_1, SortingAlg::selection_sort(unsorted_1));
  EXPECT_EQ(sorted_2, SortingAlg::selection_sort(unsorted_2));
  EXPECT_EQ(sorted_3, SortingAlg::selection_sort(unsorted_3));
}

TEST(SortAlgorithmTest, SelectionSortReturnsCorrectNumQty) {
  EXPECT_EQ(3, (SortingAlg::selection_sort(qty_vector_0)).size());
  EXPECT_EQ(1, (SortingAlg::selection_sort(qty_vector_1)).size());
}
