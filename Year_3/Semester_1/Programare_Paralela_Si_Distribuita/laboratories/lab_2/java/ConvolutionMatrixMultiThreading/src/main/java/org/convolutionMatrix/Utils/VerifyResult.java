package org.convolutionMatrix.Utils;

import java.io.File;

public class VerifyResult {
    public static boolean verifyResult(String inputFile, String outputFile) {

        String valid_outputFile= "src/main/resources/valid_output/"+outputFile.substring(outputFile.lastIndexOf("/")+1);

        return FileManager.checkIfTwoFilesAreEqual(outputFile,valid_outputFile);
    }
}
