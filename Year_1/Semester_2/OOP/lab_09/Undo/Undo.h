//
// Created by Deea on 4/18/2023.
//

#ifndef LAB_9_UNDO_H
#define LAB_9_UNDO_H
#include "../domain/Subject.h"
#include "../repository/SubjectsRepo.h"
class ActiuneUndo {
public:
    virtual void doUndo()=0;
    //destructor virtual
    virtual ~ActiuneUndo()=default;

};
//clasa pentru undo adauga care mosteneste metotdele lui actiuneundo
class UndoAdauga:public ActiuneUndo{
    Subject subject_added;
    SubjectsRepo& repo;
public:
    UndoAdauga(const Subject& subject,SubjectsRepo & repo) : repo{repo}, subject_added(subject){};
    void doUndo() override{
        repo.removeSubjectRepo(subject_added.get_name(),subject_added.get_teacher());
    }
};

//undo delete

class UndoSterge:public ActiuneUndo{
    Subject to_readd;
    SubjectsRepo& repo;
public:
    UndoSterge(SubjectsRepo& repo,const Subject& subject): repo {repo},to_readd{subject}{};
    void doUndo() override{
        repo.store(to_readd);
    }
};

class UndoModifica:public ActiuneUndo{
    Subject subject_added;
    SubjectsRepo& repo;
public:
    UndoModifica(const Subject& subject,SubjectsRepo & repo) : repo{repo}, subject_added(subject){};
    void doUndo() override{
        repo.updateSubjectRepo(subject_added);
    }
};

#endif //LAB_9_UNDO_H
