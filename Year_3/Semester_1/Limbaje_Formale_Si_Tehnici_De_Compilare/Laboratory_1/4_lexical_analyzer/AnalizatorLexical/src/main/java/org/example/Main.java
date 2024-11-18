package org.example;

import java.util.Objects;

public class Main {
    public static void main(String[] args) {

        LexicalAnalyzer analyzer = new LexicalAnalyzer();

        String cppFile = Objects.requireNonNull(Main.class.getClassLoader().getResource("1.cpp")).getFile();
        String jsonFile = Objects.requireNonNull(Main.class.getClassLoader().getResource("token.json")).getFile();

        analyzer.lexicalAnalysis(cppFile, jsonFile);

        // bst
        LexicalAnalyzerBST analyzerBST = new LexicalAnalyzerBST();
        analyzerBST.lexicalAnalysis(cppFile, jsonFile);

        // ordered list
        LexicalAnalyzerTable analyzerOrderedList = new LexicalAnalyzerTable();

        analyzerOrderedList.lexicalAnalysis(cppFile, jsonFile);
    }
}
