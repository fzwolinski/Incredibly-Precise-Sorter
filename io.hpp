#ifndef IO_H
#define IO_H

#include <vector>
#include <filesystem>

namespace IO {
  std::vector<int> load_data(std::filesystem::path const& path);
  void save_data_to_file(std::filesystem::path const& path, std::vector<int> const& data);
  void output_data(std::vector<int> const& data, std::ostream& out);
  void output_result(std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg = false);
  void save_result_to_file(std::filesystem::path const& path, std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg = false);
}

#endif