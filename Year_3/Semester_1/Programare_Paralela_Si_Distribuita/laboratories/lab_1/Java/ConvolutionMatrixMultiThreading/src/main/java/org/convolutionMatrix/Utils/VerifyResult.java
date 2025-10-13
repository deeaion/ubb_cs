package org.convolutionMatrix.Utils;

public class VerifyResult {
    public static boolean verifyResult(String inputFile, String outputFile) {

            String valid_outputFile= "src/main/java/resources/valid_output"+inputFile.substring(inputFile.lastIndexOf("/"));
            return FileManager.checkIfTwoFilesAreEqual(outputFile,valid_outputFile);
    }
}
