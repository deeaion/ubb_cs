//
// Created by Deea on 6/19/2023.
//

#ifndef IONANDREEAMARINA_DOMAIN_H
#define IONANDREEAMARINA_DOMAIN_H
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using std::vector;
using std::stringstream;
using std::string;
using std::to_string;
using std::ifstream;
using std::ostream;
using std::cout;
using std::getline;
class Student {
private:
    int nrmatricol;
    string nume;
    int varsta;
    string facultate;
public:
    Student():nrmatricol(-1),nume(""),varsta(-1),facultate(""){};
    Student(int nr,const string &n,int v,const string &f):nrmatricol(nr),nume(n),varsta(v),facultate(f){}
    Student(const Student&s):nrmatricol(s.nrmatricol),nume(s.nume),varsta(s.varsta),facultate(s.facultate)
    {}
    Student &operator=(const Student &s)=default;
    //getters
    int getNr() const{return nrmatricol;}
    const string &getNume() const{return nume;}
    const string &getFacultate() const{return facultate;}
    int getVarsta() const{return varsta;}
    //setters
    void setNr(int n){nrmatricol=n;}
    void setVarsta(int v){varsta=v;}
    void setNume(const string &n){nume=n;}
    void setFacultate(const string &fac){facultate=fac;}
  //  const string &getNum() const{return nume;}
    string print(char del) const;
    friend std::istream &operator>>(std::istream &input,Student &stud);
    friend std::ostream &operator<<(std::ostream &output,const Student &stud);


};
vector<string> splitLine(const string &line,char del);
bool cmpVarsta(const Student&s1, const Student&s2);


#endif //IONANDREEAMARINA_DOMAIN_H
