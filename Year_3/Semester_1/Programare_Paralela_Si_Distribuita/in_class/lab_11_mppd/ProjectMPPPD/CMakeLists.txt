cmake_minimum_required(VERSION 3.6)
project(projectmpppd)
# added -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set(SOURCE_FILES main.cpp)
add_executable(openmp_test_clion ${SOURCE_FILES})