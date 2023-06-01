//
// Created by Deea on 3/31/2023.
//

#include "SubjectsRepo.h"

#include <iostream>
#include <string>
using std::cout;
/**GATA SCHIMBAT*/
int SubjectsRepo::searchForSubject(const string &name, const string &teacher) {
    //caut iteratorul
    auto it=find_if(this->subjects.begin(),
                                         this->subjects.end(),
                                         [name,teacher](const Subject& sbj)
                                         { if(sbj.get_name()==name)
                                             if(sbj.get_teacher()==teacher)
                                                 return true;return false;});
    auto poz= std::distance(this->subjects.begin(),it);
    if(it!=this->subjects.end()) //verific daca e la sf
        return (int)poz;
    return -1;
}

 void SubjectsRepo::store(const Subject &SubjectToAdd) {
//    cout<<"\nSunt de aici?\n";
    const string &name = SubjectToAdd.get_name();
    const string &teacher = SubjectToAdd.get_teacher();
    if (searchForSubject(name, teacher) == -1) {
        this->subjects.push_back(SubjectToAdd);
//        cout<<"\nDupa push backi?\n";
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
//    subjectToUpdate.set_type()
//cout<<"CAUTARE";
    int index = searchForSubject(name, teacher);
//    std::cout<<"COPIE";
    if (index != -1) {
        this->subjects[index] = subjectToUpdate;
    } else {
        throw RepositoryException("Subject does not exist!");

    }
//    std::cout<<std::endl;
}


const Subject &SubjectsRepo::getSubject(const string &name, const string &teacher) {
//    cout<<"\nRETURN OBBJECT";
    int index = searchForSubject(name, teacher);
    if (index != -1) {
        return this->subjects[index];
    } else {
        throw RepositoryException("Subject does not exist!");

    }
}