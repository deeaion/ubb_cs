package org.example;

import java.io.*;
import java.util.*;
import java.util.regex.*;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.example.Implementations.HashTable.MyHashTable;
import org.example.Implementations.HashTable.TSHashTable;

public class LexicalAnalyzer {
    private Map<String, String> regexPatterns;
    private Map<String, Integer> reservedWords;
    private Map<String, Integer> atomCodes;
    private String tokenizerPattern;
    private List<FIPItem> FIP = new ArrayList<>();
    private List<String> atoms = new ArrayList<>();
    private TSHashTable ts = new TSHashTable(20);
    private List<AnalyzerError> errorList = new ArrayList<AnalyzerError>();
    private void loadJson(String jsonFile) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        JsonNode node = mapper.readTree(new File(jsonFile));
        regexPatterns = new HashMap<>();
        JsonNode regexNode = node.get("regexPatterns");
        regexNode.fields().forEachRemaining(entry -> {
            regexPatterns.put(entry.getKey(), entry.getValue().asText());
        });
        //atom codes
        atomCodes = new HashMap<>();
        JsonNode atomCodesNode = node.get("atomCodes");
        atomCodesNode.fields().forEachRemaining(entry -> {
            atomCodes.put(entry.getKey(), entry.getValue().asInt());
        });
        //reserved words
        reservedWords = new HashMap<>();
        JsonNode reservedWordsNode = node.get("reservedWords");
        reservedWordsNode.fields().forEachRemaining(entry -> {
            reservedWords.put(entry.getKey(), entry.getValue().asInt());
        });
        //delimeters
        tokenizerPattern = regexPatterns.get("DELIMITERS");
    }

    private boolean processLine(String line, int lineNumber) {
        boolean success = true;


        Pattern tokenPattern = Pattern.compile(
                "\"([^\"]*)\"|" +               // strings
                        "\\d+\\.\\d+|" +                // floats
                        "\\d+|" +                       // ints
                        "<<|>>|<=|>=|==|!=|" +          // operators
                        "[{}()=+\\-*/<>!;,]|" +         // delimiters and one char operators
                        "[a-zA-Z_][a-zA-Z_0-9\\-\\+\\!\\@\\$\\%\\^\\&\\*]*"
        );

        Matcher matcher = tokenPattern.matcher(line);

        // Handle #include separately
        if (Pattern.matches("#include\\s+<[^>]+>", line)) {
            atoms.add(line);
            FIP.add(new FIPItem(line, -1, atomCodes.get("#include"), "#include"));
            return success;
        }

        while (matcher.find()) {
            String token = matcher.group();

            if (token.isBlank()) continue;

            // Match string literals
            if (token.startsWith("\"") && token.endsWith("\"")) {
                token = token.substring(1, token.length() - 1); // Remove surrounding quotes
                atoms.add("CONST:" + token);
                TSValue tsValue = new TSValue(token, -1, atomCodes.get("CONST"), "CONST");
                int pos = ts.insert(tsValue);
                tsValue.setPosition(pos);
                FIP.add(new FIPItem(token, pos, atomCodes.get("CONST"), "CONST"));
            }

            // Match identifiers (IDs) including struct members like c.r
            else if (Pattern.matches(regexPatterns.get("ID"), token) && !reservedWords.containsKey(token)) {
               TSValue tsValue = new TSValue(token, -1, atomCodes.get("ID"), "ID");
                int pos = ts.insert(tsValue);
                tsValue.setPosition(pos);
                atoms.add("ID:" + token);
                FIP.add(new FIPItem(token, pos, atomCodes.get("ID"), "ID"));
            }

            // Match keywords or operators
            else if (atomCodes.containsKey(token)) {
                atoms.add(token);
                FIP.add(new FIPItem(token, -1, atomCodes.get(token), token));
            }

            // Match constants (float or int)
            else if (Pattern.matches(regexPatterns.get("FLOAT"), token) || Pattern.matches(regexPatterns.get("INT"), token)) {
                TSValue tsValue = new TSValue(token, -1, atomCodes.get("CONST"), "CONST");
                int pos = ts.insert(tsValue);
                tsValue.setPosition(pos);
                atoms.add("CONST:" + token);
                FIP.add(new FIPItem(token, pos, atomCodes.get("CONST"), "CONST"));
            }

            // Handle lexical errors
            else {
                String errorMessage = "Lexical error at line " + lineNumber + ": Invalid token '" + token + "'";
                System.err.println(errorMessage);
                errorList.add(new AnalyzerError(lineNumber, "Lexical", errorMessage));
                success = false;
            }
        }

        return success;
    }


    private void checkStructDeclaration(String line, String nextLine, int lineNumber) {
        if (line.matches(".*\\bstruct\\b.*") && !line.matches(".*struct [a-zA-Z_][a-zA-Z_0-9]*\\s*(\\{.*|;|\\s+[a-zA-Z_][a-zA-Z_0-9]*\\s*;).*")) {
            if (nextLine == null || (!nextLine.trim().startsWith("{") && !line.trim().endsWith("{"))) {
                String errorMessage = "Syntax error at line " + lineNumber + ": Invalid struct declaration.";
                System.err.println(errorMessage);
                errorList.add(new AnalyzerError(lineNumber, "Syntax", errorMessage));
            }
        }
    }

    private void checkSemicolon(String line, int lineNumber) {
        if (!line.trim().matches(".*[{}]$|.*;$|.*\\b(if|while|for|else|#include\\s+<[^>]+>|struct)\\b.*|.*\\s*\\).*\\s*\\{.*")) {
            if (!line.trim().isEmpty() && !line.matches(".*\\b[a-zA-Z_][a-zA-Z_0-9]*\\s*\\(.*\\)\\s*\\{.*")) { // Avoid blank lines and function headers
                String errorMessage = "Syntax error at line " + lineNumber + ": Missing semicolon.";
                System.err.println(errorMessage);
                errorList.add(new AnalyzerError(lineNumber, "Syntax", errorMessage));
            }
        }
    }

    private void checkWhileLoop(String line, int lineNumber) {
        if (line.matches(".*\\bwhile\\b.*") && !line.matches(".*while\\s*\\(.*\\)\\s*\\{.*")) {
            String errorMessage = "Syntax error at line " + lineNumber + ": Invalid while loop structure.";
            System.err.println(errorMessage);
            errorList.add(new AnalyzerError(lineNumber, "Syntax", errorMessage));
        }
    }

    private String determineLineType(String line) {
        if (line.matches(".*\\bstruct\\b.*")) {
            return "StructDeclaration";
        } else if (line.matches(".*\\bwhile\\b.*")) {
            return "WhileLoop";
        } else if (line.matches(".*\\bif\\b.*")) {
            return "IfStatement";
        } else if (line.matches(".*\\bfor\\b.*")) {
            return "ForLoop";
        } else if (line.matches(".*\\s*\\(.*\\)\\s*\\{.*")) {
            return "FunctionDeclaration";
        } else if (line.matches(".*\\b(int|float|char|string|double)\\b\\s+[a-zA-Z_][a-zA-Z_0-9]*\\s*;")) {
            return "TypeDeclaration";
        } else if (line.matches(".*=.*")) {
            return "Assignment";
        } else if (line.matches(".*\\bcout\\b.*")) {
            return "OutputStatement";
        } else if (line.matches(".*\\bcin\\b.*")) {
            return "InputStatement";
        } else {
            return "Unknown";

        }
    }

    // Write TS to files
    // Write TS to files
    private void writeTSToFile(String filename, TSHashTable table, String type) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            //sending the header
            writer.println("Index,Value,CodAtom,Atom");
            List values = table.getValues();
                for (Object value : values) {
                    if (value != null ) {
                        writer.println(value);
                    }
                }

        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    private void writeFIPToFile(String filename) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            writer.println("Atom,Code,Name,PositionInTS");
            for (FIPItem item : FIP) {
                writer.println(item);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeErrorsToFile(String filename) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            for (AnalyzerError error : errorList) {
                writer.println(error);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void lexicalAnalysis(String filename, String jsonFile) {
        try {
            // Load regex patterns and atom codes from JSON
            loadJson(jsonFile);

            // Read the source code file
            try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
                String line = reader.readLine();
                String nextLine = null;
                int lineNumber = 1;

                while ((nextLine = reader.readLine()) != null || line != null) {
                    boolean success = processLine(line, lineNumber);
                    assert line != null;
                    String lineType = determineLineType(line.trim());
                    switch (lineType) {
                        case "StructDeclaration":
                            checkStructDeclaration(line, nextLine, lineNumber);
                            break;
                        case "WhileLoop":
                            checkWhileLoop(line, lineNumber);
                            break;
                        case "Assignment", "TypeDeclaration", "OutputStatement", "InputStatement":
                            checkSemicolon(line, lineNumber);
                            break;
                        // Add more case checks as needed for line types
                        default:
                            break;
                    }
                    if (!success) {
                        System.err.println("Errors found in line " + lineNumber);
                    }
                    lineNumber++;
                    line = nextLine;
                }


                // Output results
                writeTSToFile("TS_identifiers.csv", ts,"ID");  // Save identifier table
                writeTSToFile("TS_constants.csv", ts,"CONST");      // Save constant table
                writeFIPToFile("FIP.csv");                            // Save FIP with names and positions
                writeErrorsToFile("lexical_errors.txt");              // Save errors to file
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Error class to encapsulate error information
    class AnalyzerError {
        private int lineNumber;
        private String type;
        private String message;

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
