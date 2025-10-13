#include "Utils/FileManager.h"
#include "Utils/MatrixOperations.h"
#include "SequentialMethod.h"
#include "GeometricalPartitioning/HorizontalPartitioning.h"
#include "GeometricalPartitioning/VerticalPartitioning.h"
#include <iostream>
#include <filesystem>
#include <exception>

std::string determineOutPutFile(char *inputFile)
{
    std::string outputFileName = ".\\output\\output_" + std::string(inputFile);
    return outputFileName;
}
VariantType stringToVariantType(const std::string &variantTypeStr) {
    if (variantTypeStr == "VARIANTA_1B") return VariantType::VARIANTA_1B;
    if (variantTypeStr == "VARIANTA_1F") return VariantType::VARIANTA_1F;
    if (variantTypeStr == "VARIANTA_2B") return VariantType::VARIANTA_2B;
    if (variantTypeStr == "VARIANTA_2F") return VariantType::VARIANTA_2F;
    throw std::invalid_argument("Invalid variant type: " + variantTypeStr);
}
int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <num_threads> <method_type>" << std::endl;
        return 1;
    }

    // Get current folder path
    std::string inputFile = ".\\input\\" + std::string(argv[2]);
    std::string outputFile = determineOutPutFile(argv[2]);
    int numThreads = 0;
    try
    {
        numThreads = std::stoi(argv[1]); // Convert number of threads
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument for number of threads: " << argv[1] << std::endl;
        return 1;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Number of threads out of range: " << argv[1] << std::endl;
        return 1;
    }

    std::string methodType = argv[3];
    std::string variantTypestr = argv[4];
//transform to enum
VariantType variantType=stringToVariantType(variantTypestr);
    if (methodType == "sequential")
    {
        SequentialMethod sequentialMethod(inputFile, outputFile);
        long sequentialTime = sequentialMethod.applySequentialConvolution();
        std::cout << sequentialTime << std::endl;
    }
    else if (methodType == "horizontal")
    {
        HorizontalPartitioning horizontalPartitioning(inputFile, outputFile, numThreads, variantType);
        double horizontalTime = horizontalPartitioning.applyHorizontalPartitioningConvolution();
        std::cout << horizontalTime << std::endl;
    }
//    else if (methodType == "vertical")
//    {
//        VerticalPartitioning verticalPartitioning(inputFile, outputFile, numThreads);
//        double verticalTime = verticalPartitioning.applyVerticalPartitioningConvolution();
//        std::cout << verticalTime << std::endl;
//    }
    else
    {
        std::cerr << "Unknown method type: " << methodType << std::endl;
        return 1;
    }

    return 0;
}
