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
    int seconds = miliseconds * 0.001;
    
    // Just remove three 0's from ms number
    std::string in_miliseconds = " (" + std::to_string(miliseconds).substr(0,(std::to_string(miliseconds).length() - 3)) + " ms)";

    std::cout.width(16);
    std::cout << "[" + _algorythm + "]";

    std::cout.width(7);
    std::cout << " Took:";

    std::cout.width(10);
    std::cout << duration;

    std::cout.width(2);
    std::cout << " \xE6s";

    std::cout.width(17);
    std::cout << in_miliseconds;

    std::cout.width(6);
    std::cout << " (" + std::to_string(seconds) + "s)";

    std::cout.width(20);
    std::cout << " to sort " + std::to_string(_quantity) + " numbers\n";
}

Timer::~Timer() {
  _stop_timer();
}