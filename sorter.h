#ifndef SORTER_H
#define SORTER_H

#include <vector>

class Sorter {
  public:
  void read_numbers_from_file(std::string filename);
  void run_bubble_sort(std::string output_filename = "sorted_bubble_sort.txt");

  private:
  std::vector<int> _numbers;

  void _die(const std::string& err_msg);
};

#endif