#include <fstream>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "io.hpp"

namespace IO {

  std::vector<int> load_data(std::filesystem::path const& path) {
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

  void save_data_to_file(std::filesystem::path const& path, std::vector<int> const& data) {
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

  void output_data(std::vector<int> const& data, std::ostream& out) {
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

  void output_result(std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg) {
    /* 
    * Outputs (to the console) results of sort measurement
    *
    * :param alg_name: name of the algorithm
    * :param duration: sort measurement time (in microseconds)
    * :param num_qty: quantity of numbers to be sorted
    * :param avg: flag, specifying if this is output of single measurement or average time
    */

    double miliseconds = duration * 0.001;
    int seconds = miliseconds * 0.001;
    std::string out_type = " Took:";

    if (avg) {
      out_type = " Avg:";
    }

    std::cout.width(16);
    std::cout << "[" + alg_name + "]";

    std::cout.width(7);
    std::cout << out_type;

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
    if (avg) {
      std::cout << "\n";
    }
  }

  void save_result_to_file(std::filesystem::path const& path, std::string const& alg_name, double const& duration, std::size_t num_qty, bool avg) {
    /* 
    * Saves test results to specified file (path)
    *
    * :param path: path to save the file with res
    * :param alg_name: name of the algorithm
    * :param duration: sort measurement time (in microseconds)
    * :param num_qty: quantity of numbers to be sorted
    * :param avg: flag, specifying if this is output of single measurement or average time
    */

    std::ofstream out;
    out.open(path, std::ios_base::app); // Append do file

    double miliseconds = duration * 0.001;
    int seconds = miliseconds * 0.001;
    std::string out_type = " Took:";

    if (avg) {
      out_type = " Avg:";
    }

    out.width(16);
    out << "[" + alg_name + "]";

    out.width(7);
    out << out_type;

    auto duration_os = std::ostringstream{};
    duration_os.precision(0);
    duration_os << std::fixed << duration;

    out.width(10);
    out << duration_os.str();

    out.width(2);
    out << " mcs"; // microseconds symbol

    auto ms_os = std::ostringstream{};
    ms_os.precision(0);
    ms_os << " (" << std::fixed << miliseconds << " ms)";

    out.width(13);
    out << ms_os.str();

    out.width(6);
    out << " (" + std::to_string(seconds) + "s)";

    out.width(20);
    out << " to sort " + std::to_string(num_qty) + " numbers\n";
    if (avg) {
      out << "\n";
    }
  }
}