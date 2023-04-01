cmake_minimum_required(VERSION 3.22.1)
project(lab_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_1 main.cpp Colectie/Colectie.h Colectie/Colectie.cpp Iterator/IteratorColectie.cpp "Teste (cu relatie)/TestExtins.cpp" "Teste (cu relatie)/TestExtins.h" "Teste (cu relatie)/TestScurt.cpp")
