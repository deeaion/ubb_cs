//
// Created by Deea on 4/17/2023.
//

#ifndef LAB_9_FILEREPOSITORYSUBJECTS_H
#define LAB_9_FILEREPOSITORYSUBJECTS_H
#include "SubjectsRepo.h"


class FileRepositorySubjects: public SubjectsRepo{
private:
    string nameFile;

public:
    void loadRepository();
    void saveRepository();
    void emptyFile();
    explicit FileRepositorySubjects(const string& name);

    [[maybe_unused]] void setPath(const string& name) {
        this->nameFile=name;
    }
//    void store(const Subject &SubjectToAdd) override;
//    void updateSubjectRepo(const Subject &subjectToUpdate) override;
//    void removeSubjectRepo(const string &name, const string &teacher) override;
    ~FileRepositorySubjects();


};


#endif //LAB_9_FILEREPOSITORYSUBJECTS_H
