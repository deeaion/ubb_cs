//
// Created by Deea on 3/31/2023.
//

#include "Subject.h"
#include <iostream>
#include <vector>
//#include <fstream>
#include <sstream>

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
bool Subject::operator!=(const Subject &other) {
    return !operator==(other);
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
void Subject::set_teacher(const std::string &nteacher) {
    this->teacher=nteacher;
}
void Subject::set_name(const std::string &nname) {
    this->name=nname;
}


std::vector<string> splitInput(const string& inputString, char delimitator)
{
    std::vector<string> splited;
    std:: stringstream stream(inputString);
    std::string curent;
    while(std::getline(stream,curent,delimitator))
    {
        splited.push_back(curent);
    }
    return splited;
}
std::istream  & operator>>(std::istream & inputStream, Subject & subject)
{
    std::string line;
    std::getline(inputStream,line);
    std::vector<string> objects= splitInput(line,',');
    if(objects.size()!=4)
        return inputStream;
    subject.set_name(objects[0]);
    subject.set_hours(std::stoi(objects[1]));
    subject.set_type(objects[2]);
    subject.set_teacher(objects[3]);
    return inputStream;
}

std::ostream & operator<<(std::ostream & outputStream, const Subject& subject)
{
    outputStream << subject.get_name()<<  ","<<subject.get_hours()<< ","<<subject.get_type()<<","<<subject.get_teacher()<<std::endl;
    return outputStream;
}