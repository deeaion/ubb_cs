package Repository.InMemoryRepository;

import Domain.Entity;
import Domain.Validators.Validator;
import Exception.RepositoryException.RepositoryException;
import Repository.Repository;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
public class InMemoryRepository<ID,E extends Entity<ID>> implements Repository<ID,E>
{

    private Validator<E > validator;
    private Map<ID,E> entities;

    /**
     * Initializing the repo
     * @param validator- we validate stuff here
     */
    public InMemoryRepository(Validator<E> validator)
    {
        this.validator=validator;
        entities= new HashMap<>();
    }

    /**
     * Findthe id
     * @param id -the id of the entity to be returned
     *           id must not be null
     */
    @Override
    public Optional findOne(ID id) {
        if(id==null)
            throw new RepositoryException("ID must not be null");
        return Optional.ofNullable(entities.get(id));
    }

    @Override
    public Iterable findAll() {
        return entities.values();
    }

    @Override
    public Optional save(E entity) {
        if(entity==null)
        {
            throw new IllegalArgumentException("Entity must not be null!\n");

        }
        validator.vaildate(entity);
       // E entity2=entities.get(entity.getId());
        return Optional.ofNullable(entities.putIfAbsent(entity.getId(), entity));
    }

    @Override
    public Optional delete(ID id) {
        if(entities.get(id)==null)
        {
            throw new RepositoryException("There was no Entity with that ID found!\n");
        }
        else
        {
            return Optional.ofNullable(entities.remove(id));
        }
    }

    @Override
    public Optional update(E entity) {
        if(entity==null)
        {
            throw new RepositoryException("Entity must not be null!\n");
        }
        validator.vaildate(entity);
        return Optional.ofNullable(entities.put(entity.getId(), entity));
    }
}
