//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_VALIDATORSUBJECT_H
#pragma once

#include <string>
#include "../Exceptions/Exceptions.h"
#include "../domain/Subject.h"

using std::string;

class ValidatorSubject {
private:
    static void validateName(const string &name);

    static void validateHours(int hours);

    static void validateTeacher(const string &teacher);

    static void validateType(const string &type);

public:
    static void validateSubject(const Subject &subject);


};


#endif //LAB_6_7_VALIDATORSUBJECT_H
