//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_SUBJECTSREPO_H
#define LAB_6_7_SUBJECTSREPO_H

//inclusions
#pragma once

#include <vector>
#include <string>
#include "../Exceptions/Exceptions.h"
#include "../domain/Subject.h"
#include <algorithm>

//std
using std::vector;
using std::string;
using std::find_if;

class SubjectsRepo {
private:
    //this will be our vector!
     vector<Subject> subjects;

public:

    SubjectsRepo() = default;

    //we do not permit to copy the objects
    SubjectsRepo(const SubjectsRepo &ot) = delete;
    /** store subject to list of subjects*/
    /*
     * /params: sbj
     * throws exceptions if there is an already existing subject like sbj
     *
     */
    virtual void store(const Subject &sbj);

    /*
     * returns all saved animals
     */
    [[nodiscard]] const vector<Subject> &getAll() const noexcept;

    /*
     * update Subject
     * //params: new Tape
     * throws exceptions if tape doesn't exist
     */
    virtual void updateSubjectRepo(const Subject &subjectToUpdate);

    /*
     * delete Subkect
     * //params: title and teacher
     * deletes the subject if it has the same title and teacher
     */
    virtual void removeSubjectRepo(const string &name, const string &teacher);

    /*
     * search position in vector
     * params: string name,string teacher
     * returns : i!=1 if subject exists
     *              else i=-1 if it doesnt exist
     */
    int searchForSubject(const string &name, const string &teacher);

    /*
     * returns: Subject else throws exception
     */
    const Subject &getSubject(const string &name, const string &teacher);


};


#endif //LAB_6_7_SUBJECTSREPO_H
