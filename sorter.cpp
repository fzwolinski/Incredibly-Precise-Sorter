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
    // Add numbers from file to an array
    _numbers.push_back(curr_num);
  }

  nums_file.close();
}

void Sorter::run_bubble_sort(std::string output_filename) {
  /* 
   * Sorts an array with Bubble Sort algorythm
   * 
   * :param output_filename: file name with sorted numbers
  */

  // Check if numbers were loaded from file
  if (_numbers.empty() == true) {
    _die("Error: No numbers loaded.");
  }

  const int numbers_count = _numbers.size();
  bool swapped = false;

  for (int i = 0; i < numbers_count; i++) {
    swapped = false;
    for (int j = 0; j < numbers_count; j++) {
      if (_numbers[j] > _numbers[j+1]) {
        // Swap places
        _swap(&_numbers[j], &_numbers[j+1]);
        swapped = true;
      }
    }
    if (swapped == false) {
        // Array sorted
        break;
    }
  }

  _save_numbers_to_file(output_filename);
}

void Sorter::_save_numbers_to_file(std::string output_filename) {
  /* 
   * Saves sorted array into a file
   * 
   * :param output_filename: file name with sorted numbers
  */
  std::ofstream output_file (output_filename);
  for (int i = 0; i < _numbers.size(); i++) {
    output_file << _numbers[i] << ", ";
  }
  output_file.close();
}

void Sorter::_swap(int *left, int *right) {
  /* 
   * Swaps two number in an array
   * 
   * :param *left: pointer to first number location
   * :param *right: pointer to second number location
  */
  int temp = *left;
  *left = *right;
  *right = temp;
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