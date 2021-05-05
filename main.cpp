#include <iostream>
#include <vector>

#include "io.hpp"
#include "sorting_alg.hpp"
#include "timer.hpp"

void test_sort_function(std::string alg_name, 
                        std::vector<int> (*sort_func)(std::vector<int> const&), 
                        std::vector<int> const& data, 
                        std::size_t const& run_qty
                       ) {
  double single_test_duration;
  std::vector<int> sorted;

  for(size_t i = 0; i < run_qty; i++) {
    {
      Timer t(single_test_duration);

      sorted = sort_func(data);
    }
    IO::output_result(alg_name, single_test_duration, data.size());
    single_test_duration = 0;
  }
  
  std::replace(alg_name.begin(), alg_name.end(), ' ', '_');
  std::string output_filename = "sorted_" + alg_name + ".txt";
  IO::save_data_to_file(output_filename, sorted);
}

int main() {
  auto data = IO::load_data("nums.txt");
  
  auto const tests = std::vector<std::tuple<std::string, std::vector<int> (*)(std::vector<int> const&), std::vector<int> const&, std::size_t const>> {
    {"Bubble sort", &SortingAlg::bubble_sort, data, 2u}
  };

  for (auto [name, func, data, run_qty] : tests) {
    test_sort_function(name, func, data, run_qty);
  }

  return 0;
}