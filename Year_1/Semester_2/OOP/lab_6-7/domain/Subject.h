//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_SUBJECT_H
#define LAB_6_7_SUBJECT_H
#include <iostream>
using std :: string;
#include <string>
class Subject {
private:
    string name;
    int hours;
    string type;
    string teacher;


public:
    /** Constructor of subject*/
    /*
     * A subject contains:  ->name
     *                      ->hours
     *                      ->type
     *                      ->teacher
     *
     *
     */
    Subject(const string &n, int h, const string &t, const string &te);
    /**
     * Implicit constructor
     */
    Subject();
    /**
     * destructor:
     */
    ~Subject();
    /**
     * copy constructor- when u want to copy something
     */
     Subject (const Subject &subject);

    /***
           *** GETTERSSS ***
     ***/


    //get name of subject
    const string &get_name() const;
    //get hours of subject
    int get_hours() const;
    //get type of subject
    const string &get_type() const;
    //get teacher of subject
    const string &get_teacher() const;

    /***
     * setters : modifiable are : hours and type!
     * ***/

    //set new hours for subject
    void set_hours(int new_hours);
    //set new type of subject
    void set_type(const string& new_type);

    //printing function
    string to_string_print();

    /**OPERATORS*/

    //Copy assignment operator - assigning an object to another
    Subject &operator=(const Subject &other);
    /*Equality operator for id identification
     * for this class "Subject" two objects are considered equal
     *              only if the name of the subject and teacher are the same
     * */
    bool operator==(const Subject &other);

};
/**COMPARATORS*/
/*
 * comparators: Return True if sbj_1.atribute<sbj_2.atribute
 *                  else
 *                     False
 *
 */
//returns true if sbj_1.name<sbj_2.name
bool cmpName(const Subject& sbj_1,const Subject& sbj_2);

//returns true if sbj_1.hours<sbj_2.hours
bool cmpHours(const Subject& sbj_1,const Subject& sbj_2);

//returns true if sbj_1.teacher<sbj_2.teacher
bool cmpTeacher(const Subject& sbj_1,const Subject& sbj_2);

//returns true if sbj_1.type<sbj_2.type
bool cmpType(const Subject& sbj_1,const Subject& sbj_2);

#endif //LAB_6_7_SUBJECT_H
