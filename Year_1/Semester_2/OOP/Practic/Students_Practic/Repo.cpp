//
// Created by Deea on 6/19/2023.
//

#include "Repo.h"

void Repository::loadRepository() {
    ifstream fin(path);
    Student student;
    while(fin>>student)
    {
        studenti.push_back(student);
    }
    fin.close();
}
//save repo
void Repository::saveRepository() {
    ofstream fout(path);
    for(const auto &st:studenti)
    {
        fout<<st;
    }
    fout.close();
}
//searches pos
int Repository::FindStudent(int id) {
    auto it=find_if(studenti.begin(),studenti.end(),[id](const Student& st)
    {
       return id==st.getNr();
    });
    if(it==studenti.end()) return -1;
    return (int) std::distance(studenti.begin(),it);
}
//adds
void Repository::addStudent(const Student &student) {
    studenti.push_back(student);
    saveRepository();
}
//deletes stud
void Repository::deleteStudent(const Student &st) {
    studenti.erase(studenti.begin()+ FindStudent(st.getNr()));
    saveRepository();
}
//updates student with the it
void Repository::updateStudent(int id,int i) {
    Student st=studenti[FindStudent(id)];
    Student nou=Student(st.getNr(),st.getNume(),i,st.getFacultate());
    studenti[FindStudent(id)]=nou;
    saveRepository();

}
