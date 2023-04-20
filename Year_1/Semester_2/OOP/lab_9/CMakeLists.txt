cmake_minimum_required(VERSION 3.22.1)
project(lab_9)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_9 main.cpp ContractRepository/ContractRepo.cpp domain/Subject.cpp repository/SubjectsRepo.cpp service/SubjectsService.cpp tests/Tests.cpp ui/SubjectsUi.cpp validator/ValidatorSubject.cpp repository/FileRepositorySubjects.cpp repository/FileRepositorySubjects.h Undo/Undo.cpp Undo/Undo.h)
