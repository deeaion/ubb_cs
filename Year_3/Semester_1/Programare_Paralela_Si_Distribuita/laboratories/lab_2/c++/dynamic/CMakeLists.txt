cmake_minimum_required(VERSION 3.25)
project(SolutionDynamic)

set(CMAKE_CXX_STANDARD 17)

add_executable(SolutionDynamic main.cpp SequentialMethod.cpp SequentialMethod.h MyThread.cpp MyThread.h MyDistributionThread.cpp MyDistributionThread.h GeometricalPartitioning/HorizontalPartitioning.cpp GeometricalPartitioning/HorizontalPartitioning.h GeometricalPartitioning/VerticalPartitioning.cpp GeometricalPartitioning/VerticalPartitioning.h OtherWaysOfPartitioning/BlockPartitioning.cpp OtherWaysOfPartitioning/BlockPartitioning.h OtherWaysOfPartitioning/DeltaPartitioning.cpp OtherWaysOfPartitioning/DeltaPartitioning.h Utils/ConvolutionItems.cpp Utils/ConvolutionItems.h Utils/FileManager.cpp Utils/FileManager.h Utils/Generators.cpp Utils/Generators.h Utils/MatrixOperations.cpp Utils/MatrixOperations.h
        Utils/VerifyResult.cpp
        Utils/VerifyResult.h
        constants.h)