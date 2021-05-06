#include "test_cases.cpp"

#include "bubble_sort_test.cpp"
#include "insertion_sort_test.cpp"
#include "std_sort_test.cpp"
#include "selection_sort_test.cpp"
#include "merge_sort_test.cpp"
#include "quicksort_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}