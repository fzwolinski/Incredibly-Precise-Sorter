#include <fstream>
#include <iostream>

#include "sorter.h"

void Sorter::read_numbers_from_file(std::string filename) {
  std::cout << "Reading file...\n";
  std::ifstream nums_file (filename);
  int curr_num;

  while (nums_file >> curr_num) {
    std::cout << curr_num << "\n";
  }
}