//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_EXCEPTII_H
#define IONANDREEAMARINA_EXCEPTII_H

#include <exception>
#include <iostream>
using std::exception;
using std::string;
class RepoExceptie {
    string mes;
public:
    RepoExceptie(const string &m):mes(m){}
    const string &getMes(){return mes;}
};


#endif //IONANDREEAMARINA_EXCEPTII_H
