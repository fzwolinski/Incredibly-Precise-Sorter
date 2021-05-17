#ifndef SORTINGALG_HPP
#define SORTINGALG_HPP

#include <vector>

namespace SortingAlg {
  std::vector<int> bubble_sort(std::vector<int> const& data);
  std::vector<int> insertion_sort(std::vector<int> const& data);
  std::vector<int> std_sort(std::vector<int> const& data);
  std::vector<int> selection_sort(std::vector<int> const& data);
  std::vector<int> merge_sort(std::vector<int> const& data);
  std::vector<int> quicksort(std::vector<int> const& data);

  // For Merge Sort
  std::vector<int> _merge(std::vector<int> L, std::vector<int> R);
  std::vector<int> _mergeSort(std::vector<int> to_sort);

    // For Quicksort
  int _partition(std::vector<int> &arr, int from, int to);
  void _quicksort(std::vector<int> &arr, int from, int to);
}

#endif