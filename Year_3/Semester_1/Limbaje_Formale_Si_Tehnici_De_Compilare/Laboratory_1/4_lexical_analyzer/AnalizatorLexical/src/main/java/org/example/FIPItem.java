package org.example;

public class FIPItem {
    private String item;
    private int codTS;
    private int codAtom;
    private String atom;

    public FIPItem(String item, int codTS, int codAtom, String atom) {
        this.item = item;
        this.codTS = codTS;
        this.atom=atom;
        this.codAtom = codAtom;
    }

    @Override
    public String toString() {
        return atom+","+this.codAtom + "," + this.item + "," + (this.codTS == -1 ? "-" : this.codTS);
    }

    public String getItem() {
        return item;
    }

    public void setItem(String item) {
        this.item = item;
    }

    public int getCodTS() {
        return codTS;
    }

    public void setCodTS(int codTS) {
        this.codTS = codTS;
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
}

