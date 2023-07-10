cmake_minimum_required(VERSION 3.22.1)
project(lab_7)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_7 main.cpp domain/Subject.cpp repository/SubjectsRepo.cpp service/SubjectsService.cpp tests/Tests.cpp ui/SubjectsUi.cpp validator/ValidatorSubject.cpp DynamicVector.h)
