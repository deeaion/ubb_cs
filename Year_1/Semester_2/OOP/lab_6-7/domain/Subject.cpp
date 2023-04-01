//
// Created by Deea on 3/31/2023.
//

#include "Subject.h"

/**DEFAULT CONSTRUCTOR*/
Subject::Subject() {
    this->name="";
    this->hours=0;
    this->type="";
    this->teacher="";
}


/**CONSTRUCTOR OF SUBJECT*/
Subject::Subject(const std::string &n, int h, const std::string &t, const std::string &te) {
    this->name = n;
    this->hours = h;
    this->type = t;
    this->teacher = te;
}

/**DESTRUCTOR*/
Subject::~Subject() {
    std::cout<<"Subject was destroyed"<<std::endl;
}

/**COPY CONSTRUCTOR*/
Subject::Subject(const Subject &subject) {
    this->name=subject.name;
    this->hours=subject.hours;
    this->type=subject.type;
    this->teacher=subject.teacher;
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

void Subject::set_hours(int new_hours) {
    this->hours=new_hours;
}

void Subject::set_type(const std::string &new_type) {
    this->type=new_type;
}

/**TO STRING*/
string Subject::to_string_print() {
    return "Subject "+ this->name+ "\n\tHours: "+ std::to_string(this->hours) + "\n\tType: "+ this->type+"\n\tTeacher: "+this->type;
}

/**OPERATORS*/

Subject &Subject::operator=(const Subject &other) {
    this->name=other.name;
    this->hours=other.hours;
    this->type=other.type;
    this->teacher=other.teacher;
    return *this;
}

bool Subject::operator==(const Subject &other) {
    return this->name==other.name && this->teacher==other.teacher;
}

/**COMPARATORS*/

bool cmpName(const Subject& sbj_1,const Subject& sbj_2)
{
    if(sbj_1.get_name()<sbj_2.get_name())
        return true;
    else
        return false;
}

bool cmpHours(const Subject& sbj_1,const Subject& sbj_2){
    if(sbj_1.get_hours()<sbj_2.get_hours())
        return true;
    else
        return false;
}

bool cmpTeacher(const Subject& sbj_1,const Subject& sbj_2){
    if(sbj_1.get_teacher()<sbj_2.get_teacher())
        return true;
    else
        return false;
}

bool cmpType(const Subject& sbj_1,const Subject& sbj_2){
    if(sbj_1.get_type()<sbj_2.get_type())
        return true;
    else
        return false;
}
