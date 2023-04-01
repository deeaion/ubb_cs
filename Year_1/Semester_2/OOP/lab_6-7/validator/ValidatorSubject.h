//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_VALIDATORSUBJECT_H

#include <string>
#include "../Exceptions/Exceptions.h"

using std::string;

class ValidatorSubject {
private:
    void validateName(const string &name);

    void validateHours(int hours);

    void validateTeacher(const string &teacher);

    void validateType(const string &type);

public:
    void validateSubject(const string &name, int hours, const string &teacher, const string &type);


};


#endif //LAB_6_7_VALIDATORSUBJECT_H
