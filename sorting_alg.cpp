#include <vector>

#include "sorting_alg.hpp"

std::vector<int> SortingAlg::bubble_sort(std::vector<int> const& data) {
  /* 
  * Sorts an array with Bubble Sort algorithm
  * 
  * :param data: data (int numbers) to be sorted
  * :return: sorted data as vector<int>
  */
  const auto numbers_count = data.size();
  auto sorted = data;

  for (int i = 0; i < numbers_count - 1; i++) {
    auto swapped = false;
    for (int j = 0; j < numbers_count - i - 1; j++) {
      if (sorted[j] > sorted[j+1]) {
        // Swap places
        std::swap(sorted[j], sorted[j+1]);
        swapped = true;
      }
    }
    if (swapped == false) {
        // Array sorted
        break;
    }
  }
  
  return sorted;
}

std::vector<int> SortingAlg::insertion_sort(std::vector<int> const& data) {
  /* 
   * Sorts an array with Insertion Sort algorithm
   * 
   * :param data: data (int numbers) to be sorted
   * :return: sorted data as vector<int>
  */
  const int numbers_count = data.size();
  auto sorted = data;

  for (int i = 1; i < numbers_count; i++) {
    int curr = sorted[i];

    int j = i - 1;
    // Shift each element to the right
    while(j >= 0 && sorted[j] > curr) {
      sorted[j+1] = sorted[j];
      j--;
    }
    sorted[j+1] = curr;
  }
  
  return sorted;
}

std::vector<int> SortingAlg::std_sort(std::vector<int> const& data) {
  /* 
   * Sorts an array with sort() function from
   * C++ Standard Library - from <algorithm> header
   *
   * :param data: data (int numbers) to be sorted
   * :return: sorted data as vector<int>
  */
  auto sorted = data;

  std::sort(sorted.begin(), sorted.end());

  return sorted;
}

std::vector<int> SortingAlg::selection_sort(std::vector<int> const& data) {
  /* 
   * Sorts an array with Selection Sort algorithm
   * 
   * :param data: data (int numbers) to be sorted
   * :return: sorted data as vector<int>
  */
  const int numbers_count = data.size();
  auto sorted = data;

  int min;
  int min_index;

  for (int i = 0; i < numbers_count; i++) {
    min = sorted[i];
    min_index = i;
    for(int j = i; j < numbers_count; j++) {
      if (sorted[j] < min) {
        // we have new min
        min = sorted[j];
        min_index = j;
      }
    }
    std::swap(sorted[i], sorted[min_index]);
  }
    
  return sorted;
}

std::vector<int> SortingAlg::merge_sort(std::vector<int> const& data) {
  /* 
   * Runs Merge Sort algorithm
   * 
   * :param data: data (int numbers) to be sorted
   * :return: sorted data as vector<int>
  */
  const int numbers_count = data.size();
  auto sorted = data;
  
  sorted = _mergeSort(sorted);
  
  return sorted;
}

std::vector<int> SortingAlg::_merge(std::vector<int> L, std::vector<int> R) {
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

std::vector<int> SortingAlg::_mergeSort(std::vector<int> to_sort) {
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

std::vector<int> SortingAlg::quicksort(std::vector<int> const& data) {
  /* 
   * Runs Quicksort algorithm
   * 
   * :param data: data (int numbers) to be sorted
   * :return: sorted data as vector<int>
  */
  auto sorted = data;

  _quicksort(sorted, 0, sorted.size() - 1);
  
  return sorted;
}

int SortingAlg::_partition(std::vector<int> &arr, int from, int to) {
  /* 
   * Helper function for quicksort algorithm
   * Sets pivot to last element of array
   * Places pivot at its correct position so that
   * all smaller values are on the left side
   * and greater values are on the right side 
   * (of the pivot)
   *
   * :param arr: array to be sorted
   * :param from: lowest index of array
   * :param to: highest index of array
  */
  int pivot = arr[to]; // Set the last element as pivot
  int i = from - 1;

  for (int j = from; j <= to - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  // The final postition of pivot as (i + 1)
  std::swap(arr[i + 1], arr[to]);
  
  // Return position of pivot
  return (i + 1);
}

void SortingAlg::_quicksort(std::vector<int> &arr, int from, int to) {
  /* 
   * Sorts an array with Quicksort algorithm 
   * 
   * :param arr: array to be sorted
   * :param from: lowest index of array
   * :param to: highest index of array
  */
  if (from < to) {
    int p_i = _partition(arr, from , to); // Partitioning index
    
    _quicksort(arr, from, p_i - 1); // Left side
    _quicksort(arr, p_i + 1, to); // Right side
  }
}