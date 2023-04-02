cmake_minimum_required(VERSION 3.22.1)
project(lab_6)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(lab_6 main.cpp domain/Subject.cpp repository/SubjectsRepo.cpp service/SubjectsService.cpp ui/SubjectsUi.cpp validator/ValidatorSubject.cpp tests/Tests.cpp tests/Tests.h tests/Tests.h tests/Tests.cpp tests/Tests.h tests/Tests.cpp)
