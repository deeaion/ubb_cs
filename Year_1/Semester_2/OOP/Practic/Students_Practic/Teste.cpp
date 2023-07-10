//
// Created by Deea on 6/19/2023.
//

#include "Teste.h"
#include "Service.h"
#include <cassert>
void Teste::TestAll() {

    Repository repo{"../teste"};
    Service ctr{repo};
    repo.addStudent(Student(1,"a",2,"info"));
    //repo.addStudent(Student(1,"a",3,"info"));
    for(const auto & st:repo.getStudenti())
    {
        cout<<st.print(',')<<std::endl;
    }
    ctr.updateAll(1);
    for(const auto & st:repo.getStudenti())
    {
        cout<<st.print(',')<<std::endl;
    }
    ctr.UndoAct();
    assert(repo.getStudenti()[0].getVarsta()==2);
    ctr.RedoAct();
    cout<<repo.getStudenti()[0].getVarsta();
    assert(repo.getStudenti()[0].getVarsta()==3);
    ctr.stergereMultipla(repo.getStudenti());
    assert(ctr.getAll().size()==0);
}