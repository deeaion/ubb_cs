//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_UNDO_H
#define IONANDREEAMARINA_UNDO_H

#include "Domain.h"
#include "Repo.h"
class Undo {
public:
    virtual void doUndo()=0;
    virtual int getId()=0;
    virtual int getVal()=0;
    virtual string typeUndo()=0;
    virtual Student getStudent()=0;
    virtual ~Undo()=default;
};
class UndoModifica:public Undo{
    Student ModifiedStud;
    int i;
    Repository &repo;
public:
    UndoModifica(Repository &r,const Student &Modifed,int is):repo(r),ModifiedStud(Modifed),i(is){};
    void doUndo() override{
       repo.updateStudent(ModifiedStud.getNr(),ModifiedStud.getVarsta());
    }
    int getId() override{
        return ModifiedStud.getNr();
    }
    int getVal() override{
        return i;
    }
    Student getStudent() override
    {
        return ModifiedStud;
    }
     string typeUndo() override
     {
        return "mod";
     }


};
class UndoStergere:public Undo{
    Student DeletedStud;
    Repository &repo;
public:
    UndoStergere(Repository &r,const Student &Modifed):repo{r},DeletedStud(Modifed){}
    void doUndo() override{
        repo.addStudent(DeletedStud);
    }
    Student getStudent() override{
        return DeletedStud;
    }
    int getId() override{
        return DeletedStud.getNr();
    }
    int getVal() override{
        return DeletedStud.getVarsta();
    }

    string typeUndo() override
    {
        return "del";
    }

};
class Redo {
public:
    virtual void doRedo()=0;
    virtual ~Redo()=default;
};
class RedoModifica:public Redo{
    int id=0;
    int i=0;
    Repository &repo;
public:
    RedoModifica(Repository &r, int ids,int is):repo(r),id(ids),i(is){};
    void doRedo() override{
        repo.updateStudent(id,i);
    }

};
class RedoStergere:public Redo{
    Student DeletedStud;
    Repository &repo;
public:
    RedoStergere(Repository &r,const Student &Modifed):repo{r},DeletedStud(Modifed){}
    void doRedo() override{
        repo.deleteStudent(DeletedStud);
    }

};
#endif //IONANDREEAMARINA_UNDO_H
