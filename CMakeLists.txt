cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(executeTests tests/tests.cpp sorting_alg.cpp io.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)