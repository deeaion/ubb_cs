package org.convolutionMatrix.FiniteAutomata;

import java.util.Objects;

public class State {
    private String value;
    private StateType type=StateType.NORMAL;
    public State(String value) {
        if(isValid(value)) {
            this.value = value;
        }
        else {
            throw new IllegalArgumentException("Invalid value for state");
        }
    }
    public State(String value, StateType type) {
        if(isValid(value)) {
            this.value = value;
            this.type = type;
        }
        else {
            throw new IllegalArgumentException("Invalid value for state");
        }
    }

    public StateType getType() {
        return type;
    }

    public void setType(StateType type) {
        this.type = type;
    }

    public boolean isValid(String value) {
        if (value.isEmpty()) {
            return false;
        }
        int i = 0;

        while (i < value.length() && value.charAt(i) >= 'a' && value.charAt(i) <= 'z') {
            i++;
        }
        while (i < value.length() && value.charAt(i) >= '0' && value.charAt(i) <= '9') {
            i++;
        }
        return i == value.length();
    }


    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        if(isValid(value)) {
            this.value = value;
        }
        else {
            throw new IllegalArgumentException("Invalid value for state");
        }
    }

    @Override
    public String toString() {
      if(type == StateType.INITIAL) {
          return "Initial state: " + value;
      }
        else if(type == StateType.FINAL) {
            return "Final state: " + value;
        }
        return "State: " + value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof State state)) return false;
        return Objects.equals(getValue(), state.getValue()) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(getValue());
    }
}
