//
// Created by Deea on 5/23/2023.
//

#include "Controler.h"

void Controler::store_Cut(const std::string &loc, const std::string &d, int inten, int adancime) {
    Cutremur to_add(loc,d,inten,adancime);
    val.validate(to_add);
    repo.store(to_add);


}

vector<Cutremur> Controler::filter_loc_int(const std::string &loc, int inten) {
    vector<Cutremur> filtered;
    const auto &cutre=repo.get_all();
    if(loc=="None"&&inten==0)
        return repo.get_all();
    if(loc!="None")
        copy_if(cutre.begin(),cutre.end(), back_inserter(filtered),[loc,inten]
        (const Cutremur &cut){

        if(cut.get_locatie()==loc)
            if(cut.get_intensitate()>=inten)
                return true;
        return false;
    });
    if(loc=="None")
    {
        copy_if(cutre.begin(),cutre.end(), back_inserter(filtered),[inten]
                (const Cutremur &cut){
                if(cut.get_intensitate()>=inten)
                    return true;
            return false;
        });
    }
    return filtered;
}

set<string> Controler::get_locatii() {
    set<string> locatii;
    for(const auto &cut:repo.get_all())
    {
        locatii.insert(cut.get_locatie());
    }
    return locatii;}
