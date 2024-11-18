package org.convolutionMatrix;

import org.convolutionMatrix.FiniteAutomata.*;

import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static FiniteAutomata finiteAutomata = new FiniteAutomata();
    public static void printMenu(){
        System.out.println("Enter the option: ");
        System.out.println("1. Read the automata from file!");
        System.out.println("2. Read the automata from keyboard!");
        System.out.println("3. Show the BNF for the file format of automata!");
        System.out.println("4. Verify if a sequence is accepted by the automata - AFD!");
        System.out.println("5. Show the longest prefix of a sequence that is accepted by the automata-AFD!");
        System.out.println("6. Show the set of states of the automata!");
        System.out.println("7. Show the set of alphabet symbols of the automata!");
        System.out.println("8. Show the set of final states of the automata!");
        System.out.println("9. Show the set of transitions of the automata!");
        System.out.println("10. Show the initial state of the automata!");
        System.out.println("11. Show the entire automata!");
        System.out.println("12. Exit!");

    }
    public static FiniteAutomata readAutomataFromConsole(){
        FiniteAutomata finiteAutomata = new FiniteAutomata();
        Scanner scanner = new Scanner(System.in);
        int numberOfStates, numberOfAlphabetSymbols, numberOfFinalStates, numberOfTransitions;
        while(true) {
            try {
                State initialState;
                System.out.println("Enter the number of states: ");
                numberOfStates = Integer.parseInt(scanner.nextLine());
                List<State> states = new ArrayList<>();
                for (int i = 0; i < numberOfStates; i++) {
                    System.out.println("Enter the state: ");
                    states.add(new State(scanner.nextLine(), StateType.NORMAL));
                }
                finiteAutomata.setAllStates(states);
                System.out.println("Enter the number of alphabet symbols: ");
                numberOfAlphabetSymbols = Integer.parseInt(scanner.nextLine());
                List<Alphabet> alphabetList = new ArrayList<>();
                for (int i = 0; i < numberOfAlphabetSymbols; i++) {
                    System.out.println("Enter the alphabet symbol: ");
                    alphabetList.add(new Alphabet(scanner.nextLine()));
                }
                System.out.println("Enter the number of final states: ");
                numberOfFinalStates = Integer.parseInt(scanner.nextLine());
                List<State> finalStates = new ArrayList<>();
                for (int i = 0; i < numberOfFinalStates; i++) {
                    System.out.println("Enter the final state: ");
                    finalStates.add(new State(scanner.nextLine(), StateType.FINAL));
                }
                System.out.println("Enter the initial state: ");
                initialState = new State(scanner.nextLine(), StateType.INITIAL);

                System.out.println("Enter the number of transitions: ");
                numberOfTransitions = Integer.parseInt(scanner.nextLine());
                List<Transition> transitions = new ArrayList<>();
                for (int i = 0; i < numberOfTransitions; i++) {
                    System.out.println("Enter the transition: ");
                    transitions.add(Transition.stringToTransition(scanner.nextLine()));
                }
                finiteAutomata.setInitialState(initialState);
                finiteAutomata.setFinalStates(finalStates);
                finiteAutomata.setTransitions(transitions);
                finiteAutomata.setAlphabet(alphabetList);
                break;
            } catch (Exception e) {
                System.out.println("Invalid input! Do you want to try again? (yes/no)");
                String option = scanner.nextLine();
                if(option.equals("no")) {
                    break;
                }

            }
        }
        return finiteAutomata;
    }
    public static void doAction(String option)
    {

        switch (option){
            case "1":
            {
                // read the automata from file
                Scanner scanner = new Scanner(System.in);
                System.out.println("Enter the path to the file: ");
                String path = scanner.nextLine();
                try {
                     finiteAutomata = FileManager.readFA("src/main/resources/"+path);
                    System.out.println("The automata was read successfully!");
                } catch (Exception e) {
                    System.out.println("An error occurred while reading the automata from file!");
                }
                System.out.println(finiteAutomata);

                break;

            }
            case "2":
            {
                // read the automata from keyboard
                finiteAutomata = readAutomataFromConsole();
                break;
            }
            case "3":
            {
                // show the BNF for the file format of automata
                System.out.println(finiteAutomata.getBNF());
                break;
            }

            case "4":
            {
                // verify if a sequence is accepted by the automata - AFD
                Scanner scanner = new Scanner(System.in);
                System.out.println("Enter the sequence: ");
                String sequence = scanner.nextLine();
                if(finiteAutomata.acceptsSequence(sequence)) {
                    System.out.println("The sequence is accepted by the automata!");
                }
                else {
                    System.out.println("The sequence is not accepted by the automata!");
                }
                break;
            }
            case "5":
            {
                // show the longest prefix of a sequence that is accepted by the automata-AFD
                Scanner scanner = new Scanner(System.in);
                System.out.println("Enter the sequence: ");
                String sequence = scanner.nextLine();
                String longestPrefix = finiteAutomata.longestPrefixAccepted(sequence);
                PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out, StandardCharsets.UTF_8), true);
                out.println("The longest prefix of the sequence that is accepted by the automata is: " + longestPrefix);
                break;
            }
            case "6":
            {
                // show the set of states of the automata
                System.out.println("The set of states of the automata is: ");
                for(State state: finiteAutomata.getAllStates()) {
                    System.out.println(state);
                }
                break;
            }
            case "7":
            {
                // show the set of alphabet symbols of the automata
                System.out.println("The set of alphabet symbols of the automata is: ");
                for(Alphabet alphabet: finiteAutomata.getAlphabet()) {
                    System.out.println(alphabet);
                }
                break;
            }
            case "8":
            {
                // show the set of final states of the automata
                System.out.println("The set of final states of the automata is: ");
                for(State state: finiteAutomata.getFinalStates()) {
                    System.out.println(state);
                }
                break;
            }
            case "9":
            {
                // show the set of transitions of the automata
                System.out.println("The set of transitions of the automata is: ");
                for(Transition transition: finiteAutomata.getTransitions()) {
                    System.out.println(transition);
                }
                break;
            }
            case "10":
            {
                // show the initial state of the automata
                System.out.println("The initial state of the automata is: ");
                System.out.println(finiteAutomata.getInitialState());
                break;
            }
            case "11":
            {
                // show the entire automata
                System.out.println(finiteAutomata);
                break;
            }
            case "12":
            {
                // exit
                break;
            }
            default:
            {
                System.out.println("Invalid option!");
                break;
            }


        }
    }

    public static void main(String[] args) {
        String option="";
        Scanner scanner = new Scanner(System.in);
        while(true)
        {
            printMenu();

            option = scanner.nextLine();
            if(option.equals("11"))
            {
                break;
            }
            doAction(option);
        }
    }
}