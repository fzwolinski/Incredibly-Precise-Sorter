#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
  Timer(double& duration);
  ~Timer();

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> _startTimepoint;
  double& _duration;
};

#endif