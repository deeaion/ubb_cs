package Repository;

/**
 * interface for factory
 */
public interface Factory {
    public Repository createRepository(RepositoryStrategy strategy);

}
