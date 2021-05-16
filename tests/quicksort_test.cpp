#include "../sorting_alg.hpp"
#include <gtest/gtest.h>

TEST(SortAlgorithmTest, QuicksortSortsCorrectly) {
  EXPECT_EQ(sorted_0, SortingAlg::quicksort(unsorted_0));
  EXPECT_EQ(sorted_1, SortingAlg::quicksort(unsorted_1));
  EXPECT_EQ(sorted_2, SortingAlg::quicksort(unsorted_2));
  EXPECT_EQ(sorted_3, SortingAlg::quicksort(unsorted_3));
}

TEST(SortAlgorithmTest, QuicksortReturnsCorrectNumQty) {
  EXPECT_EQ(3, (SortingAlg::quicksort(qty_vector_0)).size());
  EXPECT_EQ(1, (SortingAlg::quicksort(qty_vector_1)).size());
}
