//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_SERVICE_H
#define IONANDREEAMARINA_SERVICE_H
#include "Repo.h"
#include <memory>
#include "Undo.h"
using std::unique_ptr;
class Service {
    Repository &repo;
    vector<unique_ptr<Undo>> to_undo;
    vector<unique_ptr<Redo>> to_redo;
public:
    Service(Repository &r):repo(r){};
    Service(Service &s)=delete;
    void stergereMultipla(const vector<Student> &stud);
    void updateAll(int i);
    void UndoAct();
    void RedoAct();
    vector<Student> getAll();

};


#endif //IONANDREEAMARINA_SERVICE_H
