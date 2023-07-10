//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_REPO_H
#define PARTIAL_IONANDREEA_REPO_H
#include "Domain.h"
#include <fstream>
class Repo {
    string path;
    vector<Cutremur> cutremure;
    void loadRepo();
public:
    Repo(const string &p):path(p){loadRepo();};
    Repo(Repo &other)=delete;
    void store(const Cutremur &cut);
    const vector<Cutremur> get_all(){return cutremure;}
};


#endif //PARTIAL_IONANDREEA_REPO_H
