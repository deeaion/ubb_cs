//
// Created by Deea on 3/31/2023.
//

#include "ValidatorSubject.h"

void ValidatorSubject::validateName(const std::string &name) {
    if (name.empty())
        throw ValidatorException("\nInvalid name ");
}

void ValidatorSubject::validateTeacher(const std::string &teacher) {
    if (teacher.empty())
        throw ValidatorException("\nInvalid teacher.");

}

void ValidatorSubject::validateHours(int hours) {
    if (hours < 0)
        throw ValidatorException("\n Invalid number of hours.");

}

void ValidatorSubject::validateType(const std::string &type) {
    if (type.empty())
        throw ValidatorException("\nInvalid type ");
}

void ValidatorSubject::validateSubject(const std::string &name, int hours, const std::string &teacher,
                                       const std::string &type) {
    string exceptions;
    try {
        validateName(name);
    }
    catch (ValidatorException &ve) {
        exceptions += ve.getMessage();
    }


    try {
        validateHours(hours);
    }
    catch (ValidatorException &ve) {
        exceptions += ve.getMessage();
    }


    try {
        validateTeacher(teacher);
    }
    catch (ValidatorException &ve) {
        exceptions += ve.getMessage();
    }

    try {
        validateType(type);
    }
    catch (ValidatorException &ve) {
        exceptions += ve.getMessage();
    }

    if (!exceptions.empty()) {
        throw ValidatorException(exceptions);
    }

}