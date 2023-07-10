//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_REPO_H
#define IONANDREEAMARINA_REPO_H
#include "Domain.h"
#include "Exceptii.h"
using std::find_if;
using std::ofstream;
class Repository {
    string path;
    vector<Student> studenti;
    void loadRepository();

public:
    void saveRepository();
    Repository(const string &p):path(p){loadRepository();}
    void addStudent(const Student& student);
    void deleteStudent(const Student& student);
    int FindStudent(int id);
    void updateStudent(int id,int i);
    vector<Student> getStudenti(){return studenti;}
};


#endif //IONANDREEAMARINA_REPO_H
