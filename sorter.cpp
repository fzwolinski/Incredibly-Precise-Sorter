#include <fstream>
#include <iostream>

#include "sorter.h"

void Sorter::read_numbers_from_file(std::string filename) {
  /* 
   * Reads numbers from file and saves them to _numbers vector
   * 
   * :param filename: filename to read numbers from
  */

  std::cout << "Reading file...\n";

  std::ifstream nums_file (filename);
  int curr_num;

  while (nums_file >> curr_num) {
    std::cout << curr_num << "\n";
    _numbers.push_back(curr_num);
  }
}

void Sorter::run_bubble_sort(std::string output_filename) {
  // Check if numbers were loaded from file
  if (_numbers.empty() == true) {
    _die("Error: No numbers loaded.");
  }

  std::cout << "Running bubble sort...\n";
  std::cout << "Writing numbers to: " << output_filename << std::endl;
}









void Sorter::_die(const std::string& err_msg)
{
   /* 
   * Outputs error message on standard error output stream
   * and exits program
   * 
   * :param err_msg: error message to be displayed
  */
    std::cerr << err_msg << std::endl;
    exit(1);
}