#include <vector>

class SortingAlg {
public:
  
  static std::vector<int> bubble_sort(std::vector<int> const& data) {
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



};