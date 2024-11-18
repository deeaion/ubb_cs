package org.example;

import java.util.Objects;

public class TSValue {
    private String value;
    private int position;
    private int codAtom;
    private String atom;

    public TSValue(String value, int position, int codAtom, String atom) {
        this.value = value;
        this.position = position;
        this.codAtom = codAtom;
        this.atom = atom;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public int getCodAtom() {
        return codAtom;
    }

    public void setCodAtom(int codAtom) {
        this.codAtom = codAtom;
    }

    public String getAtom() {
        return atom;
    }

    public void setAtom(String atom) {
        this.atom = atom;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof TSValue tsValue)) return false;
        return tsValue.value.equals(value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(getValue());
    }

    @Override
    public String toString() {
        return position + "," + value + "," + codAtom + "," + atom;
    }
}
