cmake_minimum_required(VERSION 3.25)
project(CudaPPD CUDA)

set(CMAKE_CUDA_STANDARD 23)

add_executable(CudaPPD main.cu)

set_target_properties(CudaPPD PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
