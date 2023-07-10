//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_CONTROLER_H
#define PARTIAL_IONANDREEA_CONTROLER_H
#include "Repo.h"
#include "Exceptions.h"
#include "Validator.h"
#include <set>

class Controler {
    Repo &repo;
    Validator &val;
public:
    Controler (Repo &r,Validator &val): repo(r),val(val){};
    Controler(Controler& o)=delete;
    void store_Cut(const string &loc,const string &d,int inten,int adancime);
    vector<Cutremur> filter_loc_int(const string &loc,int inten);
    const vector<Cutremur> get_cutremure(){return repo.get_all();};
    set<string> get_locatii();

};


#endif //PARTIAL_IONANDREEA_CONTROLER_H
