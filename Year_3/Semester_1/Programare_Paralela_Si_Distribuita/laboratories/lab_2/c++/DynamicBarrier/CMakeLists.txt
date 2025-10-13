cmake_minimum_required(VERSION 3.29)
project(DynamicBarrier)

set(CMAKE_CXX_STANDARD 23)

add_executable(DynamicBarrier main.cpp
        GeometricalPartitioning/VerticalPartitioning.h
        GeometricalPartitioning/HorizontalPartitioning.h
        GeometricalPartitioning/HorizontalPartitioning.cpp
        GeometricalPartitioning/VerticalPartitioning.cpp
        SequentialMethod.cpp
        MyThread.cpp
        Utils/VerifyResult.cpp
        Utils/MatrixOperations.cpp
        Utils/FileManager.cpp
        Utils/ConvolutionItems.cpp
        GeometricalPartitioning/VariantType.h)
