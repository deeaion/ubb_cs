package org.convolutionMatrix.LexicalAnalyzer;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.convolutionMatrix.FiniteAutomata.FileManager;
import org.convolutionMatrix.FiniteAutomata.FiniteAutomata;
import org.convolutionMatrix.LexicalAnalyzer.ImplementationOfResources.FIPItem;
import org.convolutionMatrix.LexicalAnalyzer.ImplementationOfResources.TSOrderedList;
import org.convolutionMatrix.LexicalAnalyzer.ImplementationOfResources.TSValue;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LexicalAnalyzer {
    private Map<String, Integer> reservedWords;
    private Map<String, Integer> atomCodes;
    private final List<FIPItem> FIP = new ArrayList<>();
    private final TSOrderedList ts = new TSOrderedList();
    private final List<AnalyzerError> errorList = new ArrayList<>();
    private FiniteAutomata finiteAutomataIntegers;
    private FiniteAutomata finiteAutomataRealNumbers;
    private FiniteAutomata finiteAutomataIdentifiers;

    private void loadJson(String jsonFile) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(new File(jsonFile));
        atomCodes = new HashMap<>();
        reservedWords = new HashMap<>();

        JsonNode atomCodesNode = node.get("atomCodes");
        atomCodesNode.fields().forEachRemaining(entry -> atomCodes.put(entry.getKey(), entry.getValue().asInt()));

        JsonNode reservedWordsNode = node.get("reservedWords");
        reservedWordsNode.fields().forEachRemaining(entry -> reservedWords.put(entry.getKey(), entry.getValue().asInt()));
    }

    private String getLongestToken(String intToken, String floatToken, String idToken) {
        String longestToken = "";
        if (intToken.length() > longestToken.length()) longestToken = intToken;
        if (floatToken.length() > longestToken.length()) longestToken = floatToken;
        if (idToken.length() > longestToken.length()) longestToken = idToken;
        return longestToken;
    }

    private boolean isInteger(String token) {
        return finiteAutomataIntegers.acceptsSequence(token);
    }

    private boolean isFloat(String token) {
        return finiteAutomataRealNumbers.acceptsSequence(token);
    }

    private boolean isIdentifier(String token) {
        return finiteAutomataIdentifiers.acceptsSequence(token);
    }

    private void addTokenToFIPAndTS(String token, String tokenType) {
        int atomCode = atomCodes.getOrDefault(tokenType, -1);
        TSValue tsValue = new TSValue(token, -1, atomCode, tokenType);
        int pos = ts.insert(tsValue);
        tsValue.setPosition(pos);
        FIP.add(new FIPItem(token, pos, atomCode, tokenType));
    }

    private boolean processLine(String line, int lineNumber) {
        boolean success = true;
        int pos = 0;
        String operators = "+-*/<>=!&|;.,(){}[]";
        if (line.startsWith("#include")) {
            FIP.add(new FIPItem("#include", -1, atomCodes.get("#include"), "#include"));

            int startIndex = line.indexOf('<');
            int endIndex = line.indexOf('>');

            if (startIndex != -1 && endIndex != -1 && endIndex > startIndex) {
                String library = line.substring(startIndex, endIndex + 1);
                FIP.add(new FIPItem(library, -1, atomCodes.get("LIBRARY"), library));
            } else {
                String errorMessage = "Lexical error at line " + lineNumber + ": Invalid #include directive";
                System.err.println(errorMessage);
                errorList.add(new AnalyzerError(lineNumber, "Lexical", errorMessage));
                success = false;
            }
            return success;
        }
        while (pos < line.length()) {
            while (pos < line.length() && Character.isWhitespace(line.charAt(pos))) {
                pos++;
            }

            if (pos >= line.length()) {
                break;
            }

            String reservedToken = matchOperator(line.substring(pos));
            if (reservedToken != null) {
                FIP.add(new FIPItem(reservedToken, -1, atomCodes.get(reservedToken), reservedToken));
                pos += reservedToken.length();
                continue;
            }
            String intToken = finiteAutomataIntegers.longestPrefixAccepted(line.substring(pos));
            String floatToken = finiteAutomataRealNumbers.longestPrefixAccepted(line.substring(pos));
            String idToken = finiteAutomataIdentifiers.longestPrefixAccepted(line.substring(pos));

            String token = getLongestToken(intToken, floatToken, idToken);

            if (!token.isEmpty()) {
                if (isInteger(token)) {
                    addTokenToFIPAndTS(token, "CONST_INT");
                } else if (isFloat(token)) {
                    addTokenToFIPAndTS(token, "CONST_FLOAT");
                    int nextPos = pos + token.length();
                    if (nextPos < line.length()) {
                        char nextChar = line.charAt(nextPos);
//                        if (Character.isDigit(nextChar) || nextChar == '.') {
//                            String errorMessage = "Lexical error at line " + lineNumber + ": Invalid token continuation '" + line.substring(pos, nextPos + 1) + "'";
//                            System.err.println(errorMessage);
//                            errorList.add(new AnalyzerError(lineNumber, "Lexical", errorMessage));
//                            success = false;
//                            pos++;
//                            continue;
//                        }
                    }
                } else if (isIdentifier(token)) {
                    if (reservedWords.containsKey(token)) {
                        // Token is a keyword, not an ID
                        FIP.add(new FIPItem(token, -1, atomCodes.get(token), token));
                    } else {

                        addTokenToFIPAndTS(token, "ID");
                    }
                }
                pos += token.length();

                if (pos < line.length() && operators.indexOf(line.charAt(pos)) >= 0) {
                    String operatorToken = String.valueOf(line.charAt(pos));
                    if (atomCodes.containsKey(operatorToken)) {
                        FIP.add(new FIPItem(operatorToken, -1, atomCodes.get(operatorToken), operatorToken));
                    }
                    pos++;
                }
                continue;
            }

            reservedToken = matchOperator(line.substring(pos));
            if (reservedToken != null) {
                FIP.add(new FIPItem(reservedToken, -1, atomCodes.get(reservedToken), reservedToken));
                pos += reservedToken.length();
                continue;
            }

            // Unrecognized token case
            String errorMessage = "Lexical error at line " + lineNumber + ": Invalid token starting with '" + line.charAt(pos) + "'";
            System.err.println(errorMessage);
            errorList.add(new AnalyzerError(lineNumber, "Lexical", errorMessage));
            pos++;
            success = false;
        }

        return success;
    }


    // Match reserved words or operators
    private String matchOperator(String input) {
        for (String symbol : atomCodes.keySet()) {
            if (input.startsWith(symbol)) return symbol;
        }
        return null;
    }

    private void writeTSToFile(TSOrderedList table) {
        try (PrintWriter writer = new PrintWriter(new FileWriter("TS.csv"))) {
            writer.println("Index,Value,CodAtom,Atom");
            List<TSValue> values = table.getValues();
            for (Object value : values) {
                if (value != null) {
                    writer.println(value);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeFIPToFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("FIP.csv"))) {
            writer.println("Atom,Code,Name,PositionInTS");
            for (FIPItem item : FIP) {
                writer.println(item);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeErrorsToFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("lexical_errors.txt"))) {
            for (AnalyzerError error : errorList) {
                writer.println(error);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void readAutomatas() throws IOException {
        finiteAutomataIntegers = FileManager.readFA("src/main/resources/automata_integers.txt");
        finiteAutomataRealNumbers = FileManager.readFA("src/main/resources/automata_floats.txt");
        finiteAutomataIdentifiers = FileManager.readFA("src/main/resources/automata_ids.txt");
    }

    private void recalibrateFIPPositions() {
        for (FIPItem item : FIP) {
            if (item.getCodTS() != -1) {
                TSValue tsValue = ts.find(item.getItem());
                item.setCodTS(tsValue.getPosition());
            }
        }
    }

    public void lexicalAnalysis(String filename, String jsonFile) {
        try {
            loadJson(jsonFile);
            readAutomatas();

            try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
                String line = reader.readLine();
                int lineNumber = 0;
                while (line != null) {
                    lineNumber++;
                    line = line.trim();
                    if (!processLine(line, lineNumber)) {
                        System.out.println("Error in line " + lineNumber);
                    }
                    line = reader.readLine();
                }
                recalibrateFIPPositions();
                writeTSToFile(ts);
                writeFIPToFile();
                writeErrorsToFile();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static class AnalyzerError {
        private final int lineNumber;
        private final String type;
        private final String message;

        public AnalyzerError(int lineNumber, String type, String message) {
            this.lineNumber = lineNumber;
            this.type = type;
            this.message = message;
        }

        @Override
        public String toString() {
            return "Line " + lineNumber + " [" + type + "]: " + message;
        }
    }
}
