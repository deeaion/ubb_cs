cmake_minimum_required(VERSION 3.22.1)
project(lab_6_7)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(lab_6_7 main.cpp domain/Subject.cpp domain/Subject.h repository/SubjectsRepo.cpp repository/SubjectsRepo.h service/SubjectsService.cpp service/SubjectsService.h ui/SubjectsUi.cpp ui/SubjectsUi.h validator/ValidatorSubject.cpp validator/ValidatorSubject.h Exceptions/Exceptions.cpp Exceptions/Exceptions.h Exceptions/Exceptions.h Exceptions/Exceptions.cpp Exceptions/Exceptions.cpp)
