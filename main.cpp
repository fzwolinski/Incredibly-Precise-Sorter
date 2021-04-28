#include <iostream>
#include <chrono>
#include "sorter.h"

int main() {
  
  Sorter s;
  s.read_numbers_from_file("nums.txt");

  s.run_bubble_sort();

  return 0;
}