#include <chrono>
#include <string>

class Timer {
public:
  Timer(std::string sorting_alg);
  ~Timer();

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> _startTimepoint;
  std::string _algorythm;
  void _stop_timer();
};