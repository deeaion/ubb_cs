//
// Created by Deea on 5/23/2023.
//

#include "Teste.h"
#include "Controler.h"
#include "Domain.h"
#include "Repo.h"
#include "Exceptions.h"
#include <cassert>
void Teste::testAll() {
    Repo repo{"../test.txt"};
    Validator val;
    Controler ctr{repo,val};
    for(const auto &cut:repo.get_all())
    {
        cout<<cut.print();
    }
    assert(repo.get_all().size()==2);
    Cutremur c1=repo.get_all()[0];
    assert(c1.get_locatie()=="Here");
    assert(c1.get_data()=="23.02.2022");
    assert(c1.get_intensitate()==8);
    assert(c1.get_adancime()==9);
    ctr.store_Cut("Nou","23.01.2022",7,8);
    assert(ctr.get_cutremure().size()==3);
    try {
        ctr.store_Cut("Nou","23.01.2022",-1,-1);
    }
    catch (ValidException &m)
    {
        assert(m.get_message()=="Adancime invalida\nIntensitate invalida\n");
    }
    assert(ctr.filter_loc_int("Here",8).size()==1);
    assert(ctr.filter_loc_int("dsda",1).size()==0);
    assert(ctr.get_locatii().size()==3);
    Cutremur c2{"HEre","fef",2,10};
    repo.store(c2);
    assert(repo.get_all().size()==4);
    assert(ctr.filter_loc_int("None",0).size()==ctr.get_cutremure().size());
    assert(ctr.filter_loc_int("None",8).size()==1);
}