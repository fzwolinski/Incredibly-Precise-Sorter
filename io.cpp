#include <fstream>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "io.hpp"

std::vector<int> IO::load_data(std::filesystem::path const& path) {
  /* 
   * Loads and returns data (integer numbers) from file
   *
   * :param path: Path to the data file
   * :return: data as vector of integers
  */
  auto data = std::vector<int>{};

  auto file = std::ifstream{path};

  std::copy(
    std::istream_iterator<int>{file},
    std::istream_iterator<int>{},
    std::back_inserter(data)
  );

  if (data.empty() == 1) {
    throw std::invalid_argument("Error reading file");
  }

  return data;
}

void IO::save_data_to_file(std::filesystem::path const& path, std::vector<int> const& data) {
  /* 
   * Saves data (integer numbers) to the file
   *
   * :param path: The path to the file for saving the data
   * :param data: Data (int nums) to be saved in file
  */
  std::ofstream out (path);

  auto first = true;
  for (auto&& number : data) {
    if (not first)
      out << ", ";

    first = false;

    out << number;
  }
}

void IO::output_data(std::vector<int> const& data, std::ostream& out) {
  /* 
   * Outputs data (integer numbers) to the defined output stream
   *
   * :param data: Data to output
   * :param out: output stream
  */
  auto first = true;
  for (auto&& number : data) {
    if (not first)
      out << ", ";

    first = false;

    out << number;
  }
}

void IO::output_result(std::string const& alg_name, double const& duration, std::size_t num_qty) {
  double miliseconds = duration * 0.001;
  int seconds = miliseconds * 0.001;
  
  std::cout.width(16);
  std::cout << "[" + alg_name + "]";

  std::cout.width(7);
  std::cout << " Took:";

  auto duration_os = std::ostringstream{};
  duration_os.precision(0);
  duration_os << std::fixed << duration;

  std::cout.width(10);
  std::cout << duration_os.str();

  std::cout.width(2);
  std::cout << " \xE6s"; // microseconds symbol

  auto ms_os = std::ostringstream{};
  ms_os.precision(0);
  ms_os << " (" << std::fixed << miliseconds << " ms)";

  std::cout.width(13);
  std::cout << ms_os.str();

  std::cout.width(6);
  std::cout << " (" + std::to_string(seconds) + "s)";

  std::cout.width(20);
  std::cout << " to sort " + std::to_string(num_qty) + " numbers\n";
}