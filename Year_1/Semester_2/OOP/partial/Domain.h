//
// Created by Deea on 5/23/2023.
//

#ifndef PARTIAL_IONANDREEA_DOMAIN_H
#define PARTIAL_IONANDREEA_DOMAIN_H
#include<iostream>
using namespace std;
#include <sstream>
#include <vector>
vector<string> splitLine(const string &line,char del);
class Cutremur{
    string locatie;
    string data;
    int intensitate;
    int adancime;
public:
    //constructor
    Cutremur()
    {
        locatie="";
        data="";
        intensitate=-1;
        adancime=0;
    }

    Cutremur(const string &l,const string &d,int i,int a):locatie(l),data(d),intensitate(i),adancime(a){};
    //copy constructor
    Cutremur(const Cutremur&other)
    {
        locatie=other.locatie;
        data=other.data;
        intensitate=other.intensitate;
        adancime=other.adancime;
    }
    Cutremur &operator=(const Cutremur &other)=default;
    //getters
    const string&get_locatie() const{return locatie;};
    const string&get_data() const{return data;};
    int get_intensitate() const{return intensitate;};
    int get_adancime() const{return adancime;}
    //setters
    void set_locatie(const string &l){locatie=l;};
    void set_data(const string &d){data=d;};
    void set_intensitate(int i){intensitate=i;};
    void set_adancime(int a){adancime=a;};
    friend istream &operator>>(istream &input, Cutremur &cut);
    string print() const;

};


#endif //PARTIAL_IONANDREEA_DOMAIN_H
