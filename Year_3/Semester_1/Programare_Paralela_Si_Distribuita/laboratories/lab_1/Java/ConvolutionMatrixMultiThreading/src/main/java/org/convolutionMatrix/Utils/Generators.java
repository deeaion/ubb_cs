package org.convolutionMatrix.Utils;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Generators {
    public static void generateMatrixAndWriteToFile(int rows, int cols, int upperLimit, String filePath) {
        Random random = new Random();
        int[][] matrix = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(upperLimit);
            }
        }


        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (int i = 0; i < rows; i++) {
                StringBuilder line = new StringBuilder();
                for (int j = 0; j < cols; j++) {
                    line.append(matrix[i][j]);
                    if (j < cols - 1) {
                        line.append(" ");
                    }
                }
                writer.write(line.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Matrix has been successfully written to " + filePath);
    }
}
