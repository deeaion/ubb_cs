package org.example.Model;

import java.io.Serializable;
import java.util.Objects;

public class Entity<ID> implements Serializable {
    private ID id;
    public ID getId()
    {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Entity<?> entity)) return false;
        return Objects.equals(getId(), entity.getId());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }
}
