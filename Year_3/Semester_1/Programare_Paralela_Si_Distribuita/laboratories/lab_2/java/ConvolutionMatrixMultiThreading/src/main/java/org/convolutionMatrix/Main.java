package org.convolutionMatrix;

import org.convolutionMatrix.GeometricalPartitioning.HorizontalPartitioning;
import org.convolutionMatrix.GeometricalPartitioning.VariantType;
import org.convolutionMatrix.Utils.Generators;

import java.text.DecimalFormat;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //file from resources folder full path
        //generez matrice de 1000x1000
        Generators.generateMatrixAndWriteToFile(100,100,255,"src/main/resources/input/date100x100.txt");
        if(args.length<4)
        {
            System.out.println("Please provide the following arguments: number of threads, input file, partitioning type");
            return;
        }

        int numberOfThreads=Integer.parseInt(args[0]);
        String inputFile = "src/main/resources/input/" + args[1];
        String outputFile = "src/main/resources/output/output_" + args[1];
        String method=args[2];
        VariantType variantType=VariantType.valueOf(args[3]);
        DecimalFormat decimalFormat = new DecimalFormat("#.####");
        if(method.equals("sequential"))
        {
            SequentialMethod sequentialMethod = new SequentialMethod(inputFile,outputFile);
            double time=sequentialMethod.applySequentialConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("horizontal"))
        {
            HorizontalPartitioning horizontalPartitioning = new HorizontalPartitioning(inputFile,outputFile,numberOfThreads,variantType);
            double time=horizontalPartitioning.applyHorizontalPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
//        else if(method.equals("vertical"))
//        {
//            VerticalPartitioning verticalPartitioning = new VerticalPartitioning(inputFile,outputFile,numberOfThreads);
//            double time=verticalPartitioning.applyVerticalPartitioningConvolution();
//            System.out.println(decimalFormat.format(time));
//        }
        else
        {
            System.out.println("Please provide a valid partitioning type");
        }

    }
}