#include <iostream>
#include <string>
#include "timer.h"

Timer::Timer(std::string sorting_alg) {
  startTimepoint = std::chrono::high_resolution_clock::now();
  algorythm = sorting_alg;
}

void Timer::stop_timer() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    auto duration = end - start;
    double miliseconds = duration * 0.001;
    std::cout << "[" << algorythm << "] " << "Took: " << duration << " microsecods ("  << miliseconds << " milisecods)";
}

Timer::~Timer() {
  stop_timer();
}