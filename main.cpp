#include <iostream>
#include "sorter.h"

int main() {
  Sorter s;
  s.load_numbers("nums.txt");

  s.run_bubble_sort();
  s.run_insertion_sort();
  s.run_std_sort();
  s.run_selection_sort();

  return 0;
}