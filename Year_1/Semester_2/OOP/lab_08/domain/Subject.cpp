//
// Created by Deea on 3/31/2023.
//

#include "Subject.h"
#include <iostream>

/**DEFAULT CONSTRUCTOR*/
Subject::Subject() {
    this->name = "";
    this->hours = -1;
    this->type = "";
    this->teacher = "";
//    std::cout << "default creating subject" << std::endl;
}


/**CONSTRUCTOR OF SUBJECT*/
Subject::Subject(const std::string &n, int h, const std::string &t, const std::string &te) {
//    std::cout << "constructing subject with params" << std::endl;
    this->name = n;
    this->hours = h;
    this->type = t;
    this->teacher = te;

}

/**DESTRUCTOR*/
Subject::~Subject() = default;

/**COPY CONSTRUCTOR*/
Subject::Subject(const Subject &subject) {
    this->name = subject.name;
    this->hours = subject.hours;
    this->type = subject.type;
    this->teacher = subject.teacher;
//    std::cout << "copy constructing subject" << std::endl;
}

/**
 * GETTERS
 *
 */
int Subject::get_hours() const {
    return this->hours;
}

const string &Subject::get_name() const {
    return this->name;
}

const string &Subject::get_type() const {
    return this->type;
}

const string &Subject::get_teacher() const {
    return this->teacher;
}

/**SETTERS*/

[[maybe_unused]] void Subject::set_hours(int new_hours) {
    this->hours = new_hours;
}

[[maybe_unused]] void Subject::set_type(const std::string &new_type) {
    this->type = new_type;
}

/**TO STRING*/
string Subject::to_string_print() const {
    return "\tSubject " + this->name + "\n\tHours: " + std::to_string(this->hours) + "\n\tType: " + this->type +
           "\n\tTeacher: " + this->teacher;
}

/**OPERATORS*/

Subject &Subject::operator=(const Subject &other) = default;

bool Subject::operator==(const Subject &other) {
    return this->name == other.name && this->teacher == other.teacher;
}

/**COMPARATORS*/

bool cmpName(const Subject &sbj_1, const Subject &sbj_2) {
    if (sbj_1.get_name() < sbj_2.get_name())
        return true;
    else
        return false;
}

bool cmpHours(const Subject &sbj_1, const Subject &sbj_2) {
    if (sbj_1.get_hours() < sbj_2.get_hours())
        return true;
    else
        return false;
}

bool cmpTeacher(const Subject &sbj_1, const Subject &sbj_2) {
    if (sbj_1.get_teacher() < sbj_2.get_teacher())
        return true;
    else
        return false;
}

bool cmpType(const Subject &sbj_1, const Subject &sbj_2) {
    if (sbj_1.get_type() < sbj_2.get_type())
        return true;
    else
        return false;
}

bool cmpTeacherandType(const Subject &sbj_1, const Subject &sbj_2) {
    if (sbj_1.get_teacher()>sbj_2.get_teacher())
        return false;
    if (sbj_1.get_teacher()<sbj_2.get_teacher())
        return true;
    if (sbj_1.get_teacher() == sbj_2.get_teacher()) {
        if (sbj_1.get_type() < sbj_2.get_type())
            return true;
        else if (sbj_1.get_type() > sbj_2.get_type())
            return false;
    }
    return false;
}
