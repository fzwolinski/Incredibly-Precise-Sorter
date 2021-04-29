#include <iostream>
#include <string>
#include "timer.h"

Timer::Timer(std::string sorting_alg, int num_quantity) {
  _startTimepoint = std::chrono::high_resolution_clock::now();
  _algorythm = sorting_alg;
  _quantity = num_quantity;
}

void Timer::_stop_timer() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    auto duration = end - start;
    double miliseconds = duration * 0.001;
    
    std::string in_miliseconds = " (" + std::to_string(miliseconds) + " ms)";

    std::cout.width(16);
    std::cout << "[" + _algorythm + "]";

    std::cout.width(7);
    std::cout << " Took:";

    std::cout.width(10);
    std::cout << duration;

    std::cout.width(2);
    std::cout << " \xE6s";

    std::cout.width(15);
    std::cout << in_miliseconds;

    std::cout.width(20);
    std::cout << " to sort " + std::to_string(_quantity) + " numbers\n";
}

Timer::~Timer() {
  _stop_timer();
}