#pragma once

#include <vector>

class Sorter {
  public:
  void load_numbers(std::string filename);
  void run_bubble_sort(std::string output_filename = "sorted_bubble_sort.txt");
  void run_insertion_sort(std::string output_filename = "sorted_insertion_sort.txt");
  void run_std_sort(std::string output_filename = "sorted_std_sort.txt");
  void run_selection_sort(std::string output_filename = "sorted_selection_sort.txt");
  void run_merge_sort(std::string output_filename = "sorted_merge_sort.txt");
  void run_quicksort(std::string output_filename = "sorted_quicksort_sort.txt");
  

  private:
  std::vector<int> _unsorted;
  std::vector<int> _sorted;

  // For Merge Sort
  std::vector<int> _merge(std::vector<int> L, std::vector<int> R);
  std::vector<int> _mergeSort(std::vector<int> to_sort);

  // For Quicksort
  int _partition(std::vector<int> &arr, int from, int to);
  void _quicksort(std::vector<int> &arr, int from, int to);

  void _save_numbers_to_file(std::string output_filename);
  void _swap(int *left, int *right);
  void _die(const std::string& err_msg);
};