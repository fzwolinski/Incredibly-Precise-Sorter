#ifndef IO_H
#define IO_H

#include <vector>
#include <filesystem>

class IO {
public:
  static std::vector<int> load_data(std::filesystem::path const& path);
  static void save_data_to_file(std::filesystem::path const& path, std::vector<int> const& data);
  static void output_data(std::vector<int> const& data, std::ostream& out);
};

#endif