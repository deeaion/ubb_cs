//
// Created by Deea on 6/19/2023.
//

#include "Domain.h"
vector<string> splitLine(const string &line,char del)
{
    vector<string> objs;
    string item;
    stringstream stream(line);
    while(getline(stream,item,del))
    {
        objs.push_back(item);
    }
    return objs;
}
string Student::print(char del) const {
    return to_string(nrmatricol)+del+nume+del+ to_string(varsta)+ del+facultate;
}
/*
 * istream for getting files
 */
std::istream &operator>>(std::istream &input,Student &stud)
{
    string line;
    getline(input,line);
    if(line=="") return input;
    vector<string> obj= splitLine(line,',');
    stud.setNr(stoi(obj[0]));
    stud.setNume(obj[1]);
    stud.setVarsta(stoi(obj[2]));
    stud.setFacultate(obj[3]);
    return input;
}
 std::ostream &operator<<(std::ostream &output,const Student &stud)
 {
    output<<stud.print(',')<<std::endl;
     return output;
 }
bool cmpVarsta(const Student&s1, const Student&s2)
{
    return s1.getVarsta()<s2.getVarsta();
}
