#include <iostream>
#include <vector>

#include "io.hpp"
#include "sorting_alg.hpp"
#include "timer.hpp"

void test_sort_function(std::string alg_name, 
                        std::vector<int> (*sort_func)(std::vector<int> const&), 
                        std::vector<int> const& data, 
                        std::size_t const& run_qty,
                        bool save_res_to_file
                       ) {
  double single_test_duration;
  std::vector<int> sorted;
  double avg_time_mcs = 0; // In microseconds
  const std::string RESULT_FILENAME = "times_summary.txt";

  for(size_t i = 0; i < run_qty; i++) {
    {
      Timer t(single_test_duration);

      sorted = sort_func(data);
    }
    IO::output_result(alg_name, single_test_duration, data.size());
    
    // Save time results to file
    if (save_res_to_file) {
      IO::save_result_to_file(RESULT_FILENAME, alg_name, single_test_duration, data.size());
    }
    
    avg_time_mcs += single_test_duration;
    single_test_duration = 0;
  }
  
  // Display average sort time for the algorithm
  if (run_qty > 1) {
    avg_time_mcs = avg_time_mcs / (run_qty);

    IO::output_result(alg_name, avg_time_mcs, data.size(), true);
  }

  // Save sorted data to file
  std::replace(alg_name.begin(), alg_name.end(), ' ', '_');
  std::string output_filename = "sorted_" + alg_name + ".txt";
  IO::save_data_to_file(output_filename, sorted);
  
  // Save time results (average time) to file
  if (save_res_to_file) {
    IO::save_result_to_file(RESULT_FILENAME, alg_name, single_test_duration, data.size(), true);
  }
}

int main() {
  auto data = IO::load_data("nums.txt");
  
  auto const tests = std::vector<std::tuple<
                                            std::string, 
                                            std::vector<int> (*)(std::vector<int> const&), 
                                            std::vector<int> const&, 
                                            std::size_t const,
                                            bool>> {
    {"Bubble sort", &SortingAlg::bubble_sort, data, 3u, true},
    {"Insertion sort", &SortingAlg::insertion_sort, data, 3u, true},
    {"STD sort", &SortingAlg::std_sort, data, 3u, true},
    {"Selection sort", &SortingAlg::selection_sort, data, 3u, true},
    {"Merge sort", &SortingAlg::merge_sort, data, 3u, true},
    {"Quicksort", &SortingAlg::quicksort, data, 3u, true}
  };

  for (auto&& [name, func, data, run_qty, save_res_to_file] : tests) {
    test_sort_function(name, func, data, run_qty, save_res_to_file);
  }

  return 0;
}