#include <iostream>
#include <string>

#include "timer.hpp"

Timer::Timer(double& duration) : _duration(duration) {
  _startTimepoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
  auto const endTimepoint = std::chrono::high_resolution_clock::now();
  auto const start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint).time_since_epoch().count();
  auto const end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

  _duration = end - start;
}