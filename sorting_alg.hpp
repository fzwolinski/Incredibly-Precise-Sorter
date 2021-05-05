#ifndef SORTINGALG_HPP
#define SORTINGALG_HPP

#include <vector>

class SortingAlg {
public:
  static std::vector<int> bubble_sort(std::vector<int> const& data);
  static std::vector<int> insertion_sort(std::vector<int> const& data);
  static std::vector<int> std_sort(std::vector<int> const& data);
  static std::vector<int> selection_sort(std::vector<int> const& data);
  static std::vector<int> merge_sort(std::vector<int> const& data);
  static std::vector<int> quicksort(std::vector<int> const& data);

private:
  // For Merge Sort
  static std::vector<int> _merge(std::vector<int> L, std::vector<int> R);
  static std::vector<int> _mergeSort(std::vector<int> to_sort);

  // For Quicksort
  static int _partition(std::vector<int> &arr, int from, int to);
  static void _quicksort(std::vector<int> &arr, int from, int to);
};

#endif