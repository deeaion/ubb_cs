//
// Created by Deea on 10/20/2024.
//

#include "VerifyResult.h"
#include "../SequentialMethod.h"
#include "FileManager.h"
#include <iostream>

bool VerifyResult::verify(const std::string &inputFile, const std::string &outputFile)
{
    // tre sa iau numele fisierului output si tre sa parsez cu
    std::string outputFileName = outputFile.substr(outputFile.find_last_of("/\\") + 1);
    std::string verifiedOutputFile = ".\\verified_output\\" + outputFileName;
    FileManager fileManager(inputFile, outputFile);
    if (fileManager.checkIfTwoFilesAreEqual(outputFile, verifiedOutputFile))
    {
        return true;
    }
    else
    {
        std::cerr << "Files are not equal" << std::endl;
    }
    return false;
}