package org.convolutionMatrix.FiniteAutomata;

public class Transition {
    private State source;
    private Alphabet alphabet;
    private State destination;

    public Transition(State source, Alphabet alphabet, State destination) {
        this.source = source;
        this.alphabet = alphabet;
        this.destination = destination;
    }

    public State getSource() {
        return source;
    }

    public void setSource(State source) {
        this.source = source;
    }
    public static Transition stringToTransition(String string) {
        String[] parts = string.split("->");
        State source = new State(parts[0]);
        State destination = new State(parts[1].split(",")[0]);
        Alphabet alphabet = new Alphabet(parts[1].split(",")[1]);
        return new Transition(source, alphabet, destination);
    }
    public Alphabet getAlphabet() {
        return alphabet;
    }

    public void setAlphabet(Alphabet alphabet) {
        this.alphabet = alphabet;
    }

    public State getDestination() {
        return destination;
    }

    public void setDestination(State destination) {
        this.destination = destination;
    }
}
