package org.example.Repository.DataBaseRepository.Factory;

import org.example.Domain.Validators.Validator;
import org.example.Repository.DataBaseRepository.Util.AbstractDataBaseRepository;

public interface DataBaseFactory {
    /**
     * Creates Factory for strategy
     * @param strategy Strategy that decides type of Validator
     * @return DataBaseFactory conform to strategy
     */
    AbstractDataBaseRepository createRepositor(DataBaseRepositoryStrategy strategy, Validator validator);
}
