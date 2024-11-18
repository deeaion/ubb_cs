package org.convolutionMatrix.FiniteAutomata;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public class FileManager {

    public static  FiniteAutomata readFA(String path) throws IOException {
        // try to access the file
        // if the file does not exist, throw an exception
        BufferedReader reader = null;
        try {
            reader = Files.newBufferedReader(Path.of(path), StandardCharsets.UTF_8);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        // prima linie sunt stariile
        List<State> stateList = new ArrayList<>();
        String line= reader.readLine();
        String[] states = line.split(",");
        for(String state: states) {
            stateList.add(new State(state));
        }
        // a doua linie este alfabetul
        List<Alphabet> alphabetList = new ArrayList<>();
        line= reader.readLine();
        String[] alphabets = line.split(",");
        for(String alphabet: alphabets) {
            alphabetList.add(new Alphabet(alphabet));
        }
        // a treia linie este starea initiala
        State initialState = new State(reader.readLine().trim(), StateType.INITIAL);
        // a patra linie sunt starile finale
        List<State> finalStates = new ArrayList<>();
        line= reader.readLine();
        String[] finalStatesString = line.split(",");
        for(String finalState: finalStatesString) {
            finalStates.add(new State(finalState, StateType.FINAL));
        }
        // urmatoarele linii sunt tranzitiile
        List<Transition> transitions = new ArrayList<>();
        while ((line=reader.readLine())!=null)
        {
            transitions.add(Transition.stringToTransition(line));
        }
        reader.close();
        return new FiniteAutomata(initialState, finalStates, transitions, stateList, alphabetList);
    }
}
