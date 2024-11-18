package org.convolutionMatrix.FiniteAutomata;

import java.util.List;

public class FiniteAutomata {
    private State initialState;
    private List<State> finalStates;
    private List<Transition> transitions;
    private List<State> allStates;
    private List<Alphabet> alphabet;
    private String BNF = "<automat> ::= <states_line> <alphabet_lines> <initial_state_line> <final_states_line> <transitions>\n" +
            "<states_lines> ::= <state> | <state> <other_state>\n" +
            "<other_state> ::= \",\" <state> | <state> <other_state>\n" +
            "<alphabet_lines> ::= <symbol> {\",\" <symbol>}*\n" +
            "<initial_state_line> ::= <state>\n" +
            "<final_states_lines> ::= <state> | <state> <other_state>\n" +
            "<transitions> ::= <state> \"->\" <state> \",\" <symbol>\n" +
            "<state> ::= <string>\n" +
            "<symbol> ::= <character>\n" +
            "<string> ::= <character> {<character>}*\n" +
            "<character> ::= \"a\" | \"b\" | \"c\" | ... | \"z\" | \"0\" | \"1\" | ... | \"9\"\"-\"";

    public FiniteAutomata(State initialState, List<State> finalStates, List<Transition> transitions, List<State> allStates,List<Alphabet> alphabet) {
        this.initialState = initialState;
        this.finalStates = finalStates;
        this.transitions = transitions;
        this.allStates = allStates;
        this.alphabet = alphabet;
    }
    public FiniteAutomata() {

    }

    public List<Alphabet> getAlphabet() {
        return alphabet;
    }

    public void setAlphabet(List<Alphabet> alphabet) {
        this.alphabet = alphabet;
    }

    public void setBNF(String BNF) {
        this.BNF = BNF;
    }

    public State getInitialState() {
        return initialState;
    }

    public void setInitialState(State initialState) {
        this.initialState = initialState;
    }

    public List<State> getFinalStates() {
        return finalStates;
    }

    public void setFinalStates(List<State> finalStates) {
        this.finalStates = finalStates;
    }

    public List<Transition> getTransitions() {
        return transitions;
    }

    public void setTransitions(List<Transition> transitions) {
        this.transitions = transitions;
    }

    public List<State> getAllStates() {
        return allStates;
    }

    public void setAllStates(List<State> allStates) {
        this.allStates = allStates;
    }

    public String getBNF() {
        return BNF;
    }
    public boolean isInitialized() {
        return initialState != null && finalStates != null && transitions != null && allStates != null;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Initial state: ").append(initialState != null ? initialState.getValue() : "null").append("\n");
        sb.append("Final states: ");
        if (finalStates != null) {
            for (State state : finalStates) {
                sb.append(state.getValue()).append(" ");
            }
        }
        sb.append("\n");
        sb.append("Transitions: \n");
        if (transitions != null) {
            for (Transition transition : transitions) {
                sb.append(transition.getSource().getValue()).append(" -> ").append(transition.getDestination().getValue()).append(", ").append(transition.getAlphabet().getValue()).append("\n");
            }
        }
        return sb.toString();
    }
    private boolean isDeterminist()
    {
        for(State state: allStates)
        {
            for(Alphabet alphabet: alphabet)
            {
                int count = 0;
                for(Transition transition: transitions)
                {
                    if(transition.getSource().equals(state) && transition.getAlphabet().equals(alphabet))
                    {
                        count++;
                    }
                }
                if(count > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean acceptsSequence(String sequence) {
        if (!isDeterminist()) {
            throw new IllegalArgumentException("The automaton is not deterministic, so the sequence cannot be verified");
        }
        if (sequence.isEmpty() && finalStates.contains(initialState)) {
            return true;
        }
        State currentState = initialState;
        for (char symbol : sequence.toCharArray()) {
            boolean transitionFound = false;

            for (Transition transition : transitions) {

                if (transition.getSource().equals(currentState) &&
                        transition.getAlphabet().getValue().equals(String.valueOf(symbol))) {

                    currentState = transition.getDestination();
                    transitionFound = true;
                    break;
                }
            }

            if (!transitionFound) {
                return false;
            }
        }

        if (finalStates.contains(currentState)) {
            return true;
        } else {
            return false;
        }
    }



    public String longestPrefixAccepted(String sequence) {
        if (!isDeterminist()) {
            throw new IllegalArgumentException("The automaton is not deterministic, so the sequence cannot be verified");
        }
        if (sequence.isEmpty() && finalStates.contains(initialState)) {
            return "ε";
        }

        String longestPrefix = "";
        State currentState = initialState;
        StringBuilder currentPrefix = new StringBuilder();

        for (char symbol : sequence.toCharArray()) {
            boolean transitionFound = false;
            for (Transition transition : transitions) {
                if (transition.getSource().equals(currentState) && transition.getAlphabet().getValue().equals(String.valueOf(symbol))) {
                    currentState = transition.getDestination();
                    currentPrefix.append(symbol);
                    transitionFound = true;
                    break;
                }
            }
            if (!transitionFound) {
                break;
            }
            if (finalStates.contains(currentState)) {
                longestPrefix = currentPrefix.toString();
            }
        }
        if(longestPrefix.isEmpty() && finalStates.contains(initialState))
        {
            return "ε";
        }
        return longestPrefix;
    }

}
