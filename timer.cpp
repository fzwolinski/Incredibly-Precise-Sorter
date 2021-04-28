#include <iostream>
#include <string>
#include "timer.h"

Timer::Timer(std::string sorting_alg) {
  _startTimepoint = std::chrono::high_resolution_clock::now();
  _algorythm = sorting_alg;
}

void Timer::_stop_timer() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    auto duration = end - start;
    double miliseconds = duration * 0.001;
    
    std::string in_miliseconds = " (" + std::to_string(miliseconds) + " milliseconds)\n";

    std::cout.width(16);
    std::cout << "[" + _algorythm + "]";

    std::cout.width(11);
    std::cout << " Duration:";

    std::cout.width(10);
    std::cout << duration;

    std::cout.width(13);
    std::cout << " microseconds";

    std::cout.width(25);
    std::cout << in_miliseconds;
}

Timer::~Timer() {
  _stop_timer();
}