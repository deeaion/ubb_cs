//
// Created by Deea on 3/31/2023.
//

#include "SubjectsRepo.h"

#include <iostream>

using std::cout;

int SubjectsRepo::searchForSubject(const string &name, const string &teacher) {

    vector<Subject> sbjs = this->subjects;
    for (int i = 0; i < (int) this->subjects.size(); i++)
        if (subjects[i].get_name() == name)
            if (subjects[i].get_teacher() == teacher)
                return i;
    return -1;
}

void SubjectsRepo::store(const Subject &SubjectToAdd) {
    const string &name = SubjectToAdd.get_name();
    const string &teacher = SubjectToAdd.get_teacher();
    if (searchForSubject(name, teacher) == -1) {
        this->subjects.push_back(SubjectToAdd);
    } else {
        throw RepositoryException("Subject already exists\n");

    }
}

const vector<Subject> &SubjectsRepo::getAll() const noexcept {
    return this->subjects;
}

void SubjectsRepo::removeSubjectRepo(const string &name, const string &teacher) {
    int index = searchForSubject(name, teacher);
    if (index != -1) {
        auto first = this->subjects.begin();
        this->subjects.erase(first + index);
    } else {
        throw RepositoryException("Subject does not exist!");

    }
}

void SubjectsRepo::updateSubjectRepo(const Subject &subjectToUpdate) {
    const string &name = subjectToUpdate.get_name();
    const string &teacher = subjectToUpdate.get_teacher();
    int index = searchForSubject(name, teacher);
    if (index != -1) {
        this->subjects[index] = subjectToUpdate;
    } else {
        throw RepositoryException("Subject does not exist!");

    }
}

const Subject &SubjectsRepo::getSubject(const string &name, const string &teacher) {
    int index = searchForSubject(name, teacher);
    if (index != -1) {
        return this->subjects[index];
    } else {
        throw RepositoryException("Subject does not exist!");

    }
}