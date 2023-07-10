//
// Created by Deea on 5/23/2023.
//

#include "Domain.h"
vector<string> splitLine(const string &line,char del)
{
    vector<string> atr;
    stringstream stream(line);
    string obj;
    while(getline(stream,obj,del))
    {
        atr.push_back(obj);
    }
    return atr;

}
istream &operator>>(istream &input, Cutremur &cut) {
    string line;
    getline(input, line);
    if (line.empty())
        return input;
    vector<string> atr = splitLine(line, ',');
    cut.set_locatie(atr[0]);
    cut.set_data(atr[1]);
    cut.set_intensitate(stoi(atr[2]));
    cut.set_adancime(stoi(atr[3]));
    return input;
}

string Cutremur::print() const {
    return locatie+","+data+","+ to_string(intensitate)+","+ to_string(adancime)+"\n";
}