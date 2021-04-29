#pragma once

#include <vector>

class Sorter {
  public:
  void load_numbers(std::string filename);
  void run_bubble_sort(std::string output_filename = "sorted_bubble_sort.txt");
  void run_insertion_sort(std::string output_filename = "sorted_insertion_sort.txt");
  void run_std_sort(std::string output_filename = "sorted_std_sort.txt");

  private:
  std::vector<int> _unsorted;
  std::vector<int> _sorted;

  void _save_numbers_to_file(std::string output_filename);
  void _swap(int *left, int *right);
  void _die(const std::string& err_msg);
};