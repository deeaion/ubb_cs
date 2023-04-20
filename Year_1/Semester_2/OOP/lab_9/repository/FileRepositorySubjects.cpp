//
// Created by Deea on 4/17/2023.
//
#include <fstream>
//#include <utility>
#include "FileRepositorySubjects.h"
 FileRepositorySubjects::FileRepositorySubjects(const std::string &name) {
    this->nameFile=name;
    loadRepository();
}
void FileRepositorySubjects::loadRepository() {
    std::ifstream file(nameFile);
    Subject subject{};
    while(file>>subject)
    {   string name;
        file>>name;
        int hours;
        file>>hours;
        store(subject);
    }
}
void FileRepositorySubjects::saveRepository() {
    std::ofstream ofile(nameFile);
    if(!ofile.is_open())
        throw RepositoryException("File does not exist\n");
    for(const auto& subject:this->getAll())
    {
        ofile<<subject;
    }
    ofile.close();
}
void FileRepositorySubjects::emptyFile() {
    std::ofstream ofile(nameFile);
    ofile<<"";
}
FileRepositorySubjects::~FileRepositorySubjects() = default;
