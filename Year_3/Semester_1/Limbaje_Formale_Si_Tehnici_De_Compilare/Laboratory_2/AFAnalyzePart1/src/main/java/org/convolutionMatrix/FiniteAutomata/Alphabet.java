package org.convolutionMatrix.FiniteAutomata;

import java.util.Objects;

public class Alphabet {
    private String value;
    private static final String EPSILON = "ε";
    public  Alphabet(String value) {
        if(isValid(value)) {
            this.value = value;
        }
        else {
            throw new IllegalArgumentException("Invalid value for alphabet");
        }
    }
    public boolean isValid (String value) {
        // verific daca valoarea corespunde bnf :
        // <symbol> ::= <character>
        //<character> ::=  "a" | "b" | "c" | ... | "z" | "0" | "1" | ... | "9"| -
        if(value.equals(EPSILON)) {
            return true;
        }
        if(value.length() == 1 && (( value.charAt(0)=='-' )|| value.charAt(0) >= 'a' && value.charAt(0) <= 'z') || (value.charAt(0) >= '0' && value.charAt(0) <= '9') || (value.charAt(0)>='A' && value.charAt(0)<='Z') ) {
            return true;
        }
        return false;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        if(isValid(value)) {
            this.value = value;
        }
        else {
            throw new IllegalArgumentException("Invalid value for alphabet");
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Alphabet alphabet)) return false;
        return Objects.equals(getValue(), alphabet.getValue());
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(getValue());
    }
}
