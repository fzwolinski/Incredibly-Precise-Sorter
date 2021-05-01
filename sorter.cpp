#include <fstream>
#include <iostream>
#include <algorithm>

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

void Sorter::run_std_sort(std::string output_filename) {
   /* 
   * Sorts an array with sort() function from
   * C++ Standard Library - from <algorithm> header
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
    Timer t("STD Sort", numbers_count);

    std::sort(_sorted.begin(), _sorted.end());
  }

  _save_numbers_to_file(output_filename);
}

void Sorter::run_selection_sort(std::string output_filename) {
  /* 
   * Sorts an array with Selection Sort algorithm
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

  int min;
  int min_index;

  {
    Timer t("Selection Sort", numbers_count);

    for (int i = 0; i < numbers_count; i++) {
      min = _sorted[i];
      min_index = i;
      for(int j = i; j < numbers_count; j++) {
        if (_sorted[j] < min) {
          // we have new min
          min = _sorted[j];
          min_index = j;
        }
      }
      _swap(&_sorted[i], &_sorted[min_index]);
    }
  }
  
  _save_numbers_to_file(output_filename);
}

void Sorter::run_merge_sort(std::string output_filename) {
  /* 
   * Runs Merge Sort algorithm
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
    Timer t("Merge Sort", numbers_count);
    
    _sorted = _mergeSort(_sorted);
  }
  
  _save_numbers_to_file(output_filename);
}

std::vector<int> Sorter::_merge(std::vector<int> L, std::vector<int> R) {
  /* 
   * [Helper function for _mergeSort]
   * Merges two sorted arrays into one sorted array
   * 
   * :param L: first (half) array
   * :param R: second (half) array
   * :return: merged array as vector
  */
  std::vector<int> merged;
  
  int L_i = 0; // Index of smallest unpicked num in L
  int R_i = 0; // Index of smallest unpicked num in R

  // Fill merged array with elements from L and R
  while(L_i < L.size() && R_i < R.size()) {
      if (L[L_i] <= R[R_i]) {
          // Get val from Left arr and insert into merged
          merged.push_back(L[L_i]);
          L_i++;
      } else {
          // Get val from right arr and insert into merged
          merged.push_back(R[R_i]);
          R_i++;
      }
  }
  
  // If all values from right arr were inserted (into merged),
  // Take left arr and insert it's values to merged
  while(L_i < L.size()) {
      merged.push_back(L[L_i]);
      L_i++;
  }
  
  // If all values from left arr were inserted (into merged),
  // Take right arr and insert it's values to merged
  while(R_i < R.size()) {
      merged.push_back(R[R_i]);
      R_i++;
  }
  return merged;
}

std::vector<int> Sorter::_mergeSort(std::vector<int> to_sort) {
  /* 
  * Sorts an array with Merge Sort algorithm 
  * 
  * :param to_sort: array to be sorted
  * :return: sorted array as vector
  */
  if (to_sort.size() <= 1) {
      return to_sort;
  }
  
  std::vector<int> left;
  std::vector<int> right;
  
  // Divide to_sort into 2 halfs
  // Fill left array with first half and
  // right array with second half
  for (int i = 0; i < to_sort.size(); i++) {
      if (i < to_sort.size() / 2) {
          left.push_back(to_sort[i]);
      } else {
          right.push_back(to_sort[i]);
      }
  }
  
  // Recursion
  left = _mergeSort(left);
  right = _mergeSort(right);
  
  // Return final, sorted array
  return _merge(left, right);
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