package org.convolutionMatrix;

import org.convolutionMatrix.LexicalAnalyzer.LexicalAnalyzer;

import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        LexicalAnalyzer analyzer = new LexicalAnalyzer();

        String cppFile = Objects.requireNonNull(Main.class.getClassLoader().getResource("1.cpp")).getFile();
        String jsonFile = Objects.requireNonNull(Main.class.getClassLoader().getResource("token.json")).getFile();

        analyzer.lexicalAnalysis(cppFile, jsonFile);
    }
}