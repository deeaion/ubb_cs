//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_SUBJECTSSERVICE_H
#define LAB_6_7_SUBJECTSSERVICE_H
#pragma once
#include "../repository/FileRepositorySubjects.h"
#include "../validator/ValidatorSubject.h"
#include "../repository/SubjectsRepo.h"
#include "../ContractRepository/ContractRepo.h"
#include <string>
#include <vector>
#include <functional>
#include <random>
#include <memory>
#include <algorithm>
using std::copy_if;
using std::shuffle;
using std::string;
using std::unique_ptr;
using std::vector;
using std::function;
#include <map>
#include <set>
using std::set;
using std::map;
#include "../Undo/Undo.h"

class SubjectsService: public Observable{
     FileRepositorySubjects &repo;
     ValidatorSubject &val;
     ContractRepo &contract;
     std::vector<unique_ptr<ActiuneUndo>> undoActions;

    /*
     *Function that sorts the list it is given of Subjects
     * it compares two Subjects
     * it is given a key tehnically which is one of the functions that the file subject
     * has
     * returns: a copied list of the subjects but sorted
     *
     */
//    vector<Subject> generalSort(bool(*cmpKey)(const Subject &, const Subject &));

    /*
     * Generic Function
     * fct-> can be a function or lambda ( function <> allows lambda functions!)
     * returns: only the subjects that satisfy the criteria
     *
     */
//    vector<Subject> filter(const function<bool(const Subject &)> &fct);

public:
    /*
     * Contract
     */
    /*
     * get contract
     */
    void Undo();
    const vector<Subject> & getAllContract() noexcept;
    /*
     * get contract size -> to not get reference every time
     */
    int getContractSize();
     /*
      * add to contract!
      */
     void add_to_contract(const string& name, const string& teacher,const vector<Subject>& filtered);

     void generateContract(int nrSubjects);

     void exportContract(const string& name);

     void emptyContract();



    SubjectsService(FileRepositorySubjects &repo, ContractRepo &contract ,ValidatorSubject &val) : repo{repo}, val{val},contract{contract} {}

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

    [[maybe_unused]] vector<Subject> filterBySubjectName(const string &name);

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

    map<string,vector<Subject>> creatingmap();
    set<string> number_of_types();
    vector<Subject> filterByType(const string & type);
};


#endif //LAB_6_7_SUBJECTSSERVICE_H
