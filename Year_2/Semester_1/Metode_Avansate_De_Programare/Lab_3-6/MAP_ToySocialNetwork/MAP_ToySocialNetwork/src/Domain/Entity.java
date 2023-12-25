package Domain;

import java.io.Serializable;
import java.util.Objects;
/*
    BASE CLASS FOR OUR OBJECTS.
    It holds an id.
 */

/**
 * Enitity base class
 * @param <ID> The type of id for the entity
 */
public class Entity <ID> implements Serializable {
    protected ID id;

    /**
     *
     * @return ID of entity
     */
    public ID getId(){
        return id;
    }

    /**
     * sets id
     * @param id Sets this to new id
     */
    public void setId(ID id)
    {
        this.id=id;
    }

    /**
     *
     * param obj  See if object is
     * return true If the objects are equals
     * else false
     */
    @Override
    public boolean equals(Object obj) {
        if(this==obj)
        {
            return true;
        }
        if(!(obj instanceof Entity<?> entityCastedObject))
        {
            return false;
        }
        return getId().equals(entityCastedObject.getId());

    }

    /**
     * Hashcode of object
     * @return haschoded id
     */
    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }
}
