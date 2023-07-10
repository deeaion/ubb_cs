//
// Created by Deea on 6/19/2023.
//

#include "Service.h"
/*
 * deletes all el from v
 */
void Service::stergereMultipla(const vector<Student> &stud)
{
    for(const auto& st:stud)
    {
        to_undo.push_back(std::make_unique<UndoStergere>(repo,st));
        repo.deleteStudent(st);


    }
    repo.saveRepository();
}
//updates to age
void Service::updateAll(int i)
    {
        for(const auto&st:repo.getStudenti())
        {
            to_undo.push_back(std::make_unique<UndoModifica>(repo,st,-i));
            if(st.getVarsta()+i<=0) throw RepoExceptie("Sunt studenti cu varsta invalida;");
            int v=st.getVarsta()+i;
           // Student modified(st.getNr(),st.getNume(),v,st.getFacultate());
            repo.updateStudent(st.getNr(),v);

        }

    }


//undoes last op
void Service::UndoAct() {
    if(to_undo.empty())
    {
        throw RepoExceptie{"Nu mai poti face undo!\n"};
    }
    string type=to_undo.back()->typeUndo();
    auto st=to_undo.back()->getStudent();

    if(type=="mod")
    {  int i=0;
//        int i=0;
        while(i<repo.getStudenti().size())
        {to_redo.push_back(std::make_unique<RedoModifica>(repo,st.getNr(),st.getVarsta()-to_undo.back()->getVal())); i++;}
    }
    if(type=="del")
        to_redo.push_back(std::make_unique<RedoStergere>(repo,st));
    to_undo.back()->doUndo();
    to_undo.pop_back();

}
/*
 * returns sorted
 */
vector<Student> Service::getAll() {
    auto sorted=repo.getStudenti();
    sort(sorted.begin(),sorted.end(), cmpVarsta);
    return sorted;
}
//redoes last ac
void Service::RedoAct() {
    if(to_redo.empty())
    {
        throw RepoExceptie{"Nu mai poti face redo!\n"};

    }
    to_redo.back()->doRedo();
    to_redo.pop_back();
    //repo.saveRepository();
}