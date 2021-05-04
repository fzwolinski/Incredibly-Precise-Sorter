#include <fstream>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <vector>

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