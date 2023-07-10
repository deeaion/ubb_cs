cmake_minimum_required(VERSION 3.25)
project(lab_8)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_8 main.cpp domain/Subject.cpp repository/SubjectsRepo.cpp service/SubjectsService.cpp tests/Tests.cpp ui/SubjectsUi.cpp validator/ValidatorSubject.cpp ContractRepository/ContractRepo.cpp ContractRepository/ContractRepo.h)
