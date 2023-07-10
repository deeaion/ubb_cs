//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_VALIDATOR_H
#define PARTIAL_IONANDREEA_VALIDATOR_H
#include "Exceptions.h"
#include "Domain.h"

class Validator {
public:
    void validate(const Cutremur &cut)
    {
        string errors;
        if(cut.get_adancime()<0)
            errors+="Adancime invalida\n";
        if(cut.get_intensitate()<0||cut.get_intensitate()>10)
            errors+="Intensitate invalida\n";
        if(!errors.empty())
            throw ValidException(errors);
    }
};


#endif //PARTIAL_IONANDREEA_VALIDATOR_H
