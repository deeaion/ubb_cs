//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_SUBJECTSSERVICE_H
#define LAB_6_7_SUBJECTSSERVICE_H
#pragma once

#include "../validator/ValidatorSubject.h"
#include "../repository/SubjectsRepo.h"
#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::function;

class SubjectsService {
    SubjectsRepo &repo;
    [[maybe_unused]] ValidatorSubject &val;

    /*
     *Function that sorts the list it is given of Subjects
     * it compares two Subjects
     * it is given a key tehnically which is one of the functions that the file subject
     * has
     * returns: a copied list of the subjects but sorted
     *
     */
    vector<Subject> generalSort(bool(*cmpKey)(const Subject &, const Subject &));

    /*
     * Generic Function
     * fct-> can be a function or lambda ( function <> allows lambda functions!)
     * returns: only the subjects that satisfy the criteria
     *
     */
    vector<Subject> filter(const function<bool(const Subject &)> &fct);

public:
    SubjectsService(SubjectsRepo &repo, ValidatorSubject &val) : repo{repo}, val{val} {

    }

    //we don't allow the copy of objects in SubjectsService
    SubjectsService(const SubjectsService &ot) = delete;

    /*
     * returns: all the subjects in the order they were added
     */
    const vector<Subject> &getAll() noexcept;

    /*
     * Add the Subjects
     * Throws Exception if: it already exists or is not valid
     */
    void addSubject(const string &name, int hours, const string &teacher, const string &type);

    /*
     * Delete the subject
     * Throws Exception if : subject does not exist
     */
    void deleteSubject(const string &name, const string &teacher);

    /*
     * Update the subject
     * Throws Exception if: the subject does not exist
     *                      the new parameters are not valid
     */
    void updateSubject(const string &name, const string &teacher, int hours, const string &type);

    /*
     * Search for the subject by name and teacher
     * Throws Exception if : the subject does not exist
     *
     */
    const Subject &searchForSubject(const string &name, const string &teacher);

    /**FILTERS*/

    /*Filter by number of hours*/
    vector<Subject> filterByHours(int hours);

    /*Filter by teacher's name*/
    vector<Subject> filterByTeacher(const string &teacher);

    /** SORT*/
    /*
     * Sort by name of subject
     */
    vector<Subject> sortByName();

    /*
     * Sort by number of hours
     */
    vector<Subject> sortByHours();

    /*
     * Sort by teacher and type
     */
    vector<Subject> sortByTeacherandType();

};


#endif //LAB_6_7_SUBJECTSSERVICE_H
