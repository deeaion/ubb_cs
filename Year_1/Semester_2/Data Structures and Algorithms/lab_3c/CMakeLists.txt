cmake_minimum_required(VERSION 3.22.1)
project(lab_3c)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_3c main.cpp MDO/MDO.h Iterator/IteratorMDO.cpp Tests/TestExtins.cpp Tests/TestScurt.cpp MDO/MDO.cpp)
