package org.example.Model.Validators.Interfaces;

import org.example.Model.Validators.Enums.ValidatorStrategy;

public interface Factory {
    Validator createValidator(ValidatorStrategy validatorStrategy);
}
