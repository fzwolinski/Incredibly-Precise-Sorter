#ifndef IO_H
#define IO_H

#include <vector>
#include <filesystem>

class IO {
public:
  static std::vector<int> load_data(std::filesystem::path const& path);
  static void save_data_to_file(std::filesystem::path const& path, std::vector<int> const& data);
  static void output_data(std::vector<int> const& data, std::ostream& out);
  static void output_result(std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg = false);
  static void save_result_to_file(std::filesystem::path const& path, std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg = false);
};

#endif