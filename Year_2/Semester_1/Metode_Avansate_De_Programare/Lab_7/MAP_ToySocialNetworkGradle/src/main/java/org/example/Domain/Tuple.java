package org.example.Domain;


import java.util.Objects;

public class Tuple<E1,E2> {
    private E1 e1;
    private E2 e2;

    /**
     * creates tuple of two entities
     * @param e1  first entity of tuple
     * @param e2  second entity of tuple
     */
    public Tuple(E1 e1, E2 e2) {
        this.e1 = e1;
        this.e2 = e2;
    }

    /**
     *
     * @return E1 entity
     */
    public E1 getLeft() {
        return e1;
    }

    /**
     * set first entity
     * @param e1
     */
    public void setLeft(E1 e1) {
        this.e1 = e1;
    }

    /**
     * gets second entity
     * @return second entity
     */
    public E2 getRight() {
        return e2;
    }

    /**
     * sets second entity
     * @param e2 to set as second entity
     */
    public void setRight(E2 e2) {
        this.e2 = e2;
    }

    /**
     * to string for the tuple
     * @return strings to be printed
     */
    @Override
    public String toString() {
        return e1+", "+e2;
    }

    /**
     * equality of tuples
     * @param o  to check if object is equal
     * @return true  if they are equal else false
     */
    @Override
    public boolean equals(Object o) {
        return this.e1.equals(((Tuple) o).e1)&&this.e2.equals(((Tuple) o).e2);
    }

    /**
     * hashcode of tuple
     * @return hashcode of objects
     */
    @Override
    public int hashCode() {
        return Objects.hash(e1, e2);
    }
}
