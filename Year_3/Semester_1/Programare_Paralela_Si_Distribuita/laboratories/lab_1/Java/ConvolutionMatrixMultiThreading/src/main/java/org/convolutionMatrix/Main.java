package org.convolutionMatrix;

import org.convolutionMatrix.GeometricalPartitioning.HorizontalPartitioning;
import org.convolutionMatrix.GeometricalPartitioning.VerticalPartitioning;
import org.convolutionMatrix.OtherWaysOfPartitioning.BlockPartitioning;
import org.convolutionMatrix.OtherWaysOfPartitioning.DeltaPartitioning;
import org.convolutionMatrix.OtherWaysOfPartitioning.DistributionType;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.Generators;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        //file from resources folder full path
        //generez matrice de 1000x1000
//        System.out.println(Arrays.toString(args));
        if(args.length<3)
        {
            System.out.println("Please provide the following arguments: number of threads, input file, partitioning type");
            return;
        }

        int numberOfThreads=Integer.parseInt(args[0]);
        String inputFile = "src/main/resources/input/" + args[1];
        String outputFile = "src/main/resources/output/output_" + args[1];
        String method=args[2];
        DecimalFormat decimalFormat = new DecimalFormat("#.####");
        if(method.equals("sequential"))
        {
            SequentialMethod sequentialMethod = new SequentialMethod(inputFile,outputFile);
            double time=sequentialMethod.applySequentialConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("horizontal"))
        {
            HorizontalPartitioning horizontalPartitioning = new HorizontalPartitioning(inputFile,outputFile,numberOfThreads);
            double time=horizontalPartitioning.applyHorizontalPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("vertical"))
        {
            VerticalPartitioning verticalPartitioning = new VerticalPartitioning(inputFile,outputFile,numberOfThreads);
            double time=verticalPartitioning.applyVerticalPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("block"))
        {
            BlockPartitioning blockPartitioning = new BlockPartitioning(inputFile,outputFile,numberOfThreads);
            double time=blockPartitioning.applyBlockPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("cyclic"))
        {
            DeltaPartitioning deltaPartitioning = new DeltaPartitioning(inputFile,outputFile,numberOfThreads, DistributionType.CYCLIC);
            double time=deltaPartitioning.applyDeltaPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else if(method.equals("linear"))
        {
            DeltaPartitioning deltaPartitioning = new DeltaPartitioning(inputFile,outputFile,numberOfThreads, DistributionType.LINEAR);
            double time=deltaPartitioning.applyDeltaPartitioningConvolution();
            System.out.println(decimalFormat.format(time));
        }
        else
        {
            System.out.println("Please provide a valid partitioning type");
        }

    }
}