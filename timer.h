#include <chrono>
#include <string>

class Timer {
public:
  Timer(std::string sorting_alg);
  ~Timer();

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
  std::string algorythm;
  void stop_timer();
};