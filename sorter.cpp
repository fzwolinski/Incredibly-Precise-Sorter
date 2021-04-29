#include <fstream>
#include <iostream>

#include "sorter.h"
#include "timer.h"

void Sorter::load_numbers(std::string filename) {
  /* 
   * Reads numbers from file and saves them to _unsorted vector
   * 
   * :param filename: filename to read numbers from
  */
  std::ifstream nums_file (filename);
  int curr_num;
  _unsorted.clear();

  while (nums_file >> curr_num) {
    // Add numbers from file to an array
    //std::cout << curr_num << ", ";
    _unsorted.push_back(curr_num);
  }

  nums_file.close();
}

void Sorter::run_bubble_sort(std::string output_filename) {
  /* 
   * Sorts an array with Bubble Sort algorithm
   * 
   * :param output_filename: file name with sorted numbers
  */

  // Check if numbers were loaded from file
  if (_unsorted.empty() == true) {
    _die("Error: No numbers loaded.");
  }

  const int numbers_count = _unsorted.size();
  _sorted.clear();
  _sorted.insert(_sorted.end(), _unsorted.begin(), _unsorted.end());

  {
    // Start timer
    Timer t("Bubble Sort", numbers_count);
  
    bool swapped = false;

    for (int i = 0; i < numbers_count - 1; i++) {
      swapped = false;
      for (int j = 0; j < numbers_count - i - 1; j++) {
        if (_sorted[j] > _sorted[j+1]) {
          // Swap places
          _swap(&_sorted[j], &_sorted[j+1]);
          swapped = true;
        }
      }
      if (swapped == false) {
          // Array sorted
          break;
      }
    }
  }
  
  _save_numbers_to_file(output_filename);
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

void Sorter::run_insertion_sort(std::string output_filename) {
  /* 
   * Sorts an array with Insertion Sort algorithm
   * 
   * :param output_filename: file name with sorted numbers
  */

  // Check if numbers were loaded from file
  if (_unsorted.empty() == true) {
    _die("Error: No numbers loaded.");
  }

  const int numbers_count = _unsorted.size();
  _sorted.clear();
  _sorted.insert(_sorted.end(), _unsorted.begin(), _unsorted.end());

  {
    // Start timer
    Timer t("Insertion Sort", numbers_count);
    for (int i = 1; i < numbers_count; i++) {
      int curr = _sorted[i];

      int j = i - 1;
      // Shift each element to the right
      while(j >= 0 && _sorted[j] > curr) {
        _sorted[j+1] = _sorted[j];
        j--;
      }
      _sorted[j+1] = curr;
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
  for (int i = 0; i < _sorted.size(); i++) {
    output_file << _sorted[i];
    if (i != _sorted.size() - 1) {
      output_file << ", ";
    }
  }
  output_file.close();
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