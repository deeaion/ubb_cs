//
// Created by Deea on 4/14/2023.
//

#include "ContractRepo.h"
//#include "../Exceptions/Exceptions.h"
using std::ifstream;
using std::ofstream;

void ContractRepo::add_contract(const Subject &sbj) {
    //I will not let them add the same subject twice!
    const string& name=sbj.get_name();
    const string& teacher=sbj.get_teacher();
    if(search_subject_contract(name,teacher)!=-1)
        throw ContractException("Subject already in contract!");
    else
    {
        this->Contract.push_back(sbj);
    }
}
int ContractRepo::search_subject_contract(const std::string &name, const std::string &teacher) {
    auto it=find_if(this->Contract.begin(),this->Contract.end(),[name,teacher](const Subject& sbj){
        if(sbj.get_name()==name)
            if(sbj.get_teacher()==teacher)
                return true;
        return false;

    });
    long long poz= std::distance(this->Contract.begin(),it);
    if(it!=this->Contract.end())
        return (int)poz;
    return -1;

}
void ContractRepo::empty_contract() noexcept {
    this->Contract.clear();
}
void ContractRepo::generate_contract(int nr_subjects,const vector<Subject>& memory) {
    empty_contract();
    auto to_contract=memory;
    shuffle(to_contract.begin(),to_contract.end(),std::default_random_engine (time(nullptr)));
    while(nr_subjects&&!to_contract.empty())
    {
        add_contract(to_contract.back());
        to_contract.pop_back();
        nr_subjects--;
    }
}
const vector<Subject>& ContractRepo::get_Contract() {
    return this->Contract;
}

string ContractRepo::export_contract(const std::string &name_file) {
    string filename=name_file;
    auto pos=filename.find_last_of('.');
    if(pos<filename.size())
    {
        auto file_extension=name_file.substr(pos);
        if(file_extension!=".html")
            filename=filename+".html";
    }


    std::ofstream fout(filename);
    fout<<"<html>\n"
          "<body>\n"
          "<head>\n"
          "    <h3 style=\" font-family: 'Caviar Dreams',serif; color:mediumpurple; \">Contracted Subjects</h3>\n"
          "    </head>\n"
          "<style>\n"
          "    p {\n"
          "        color: #D7BDE2 ;\n"
          "        background-color: #A9CCE3 ;\n"
          "        border: 1px solid black; }\n"
          "    table,th,td{\n"
          "        border: 1px solid black;\n"
          "    }\n"
          "    th{\n"
          "        color: darkviolet;\n"
          "    }\n"
          "    body{\n"
          "        background-color: #CACFD2;\n"
          "    }\n"
          "</style>\n";
    fout<<"<table>\n"
          "\n"
          "        <th>Name</th>\n"
          "        <th>Hours</th>\n"
          "        <th>Type</th>\n"
          "        <th>Teacher</th>";
    for(const Subject& sbj:get_Contract())
    {
        fout<<"<tr>\n";
        fout<<"<th>"<<sbj.get_name()<<"</th>\n"
            <<"<th>"<<sbj.get_hours()<<"</th>\n"
            <<"<th>"<<sbj.get_type()<<"</th>\n"
            <<"<th>\n"<<sbj.get_teacher()<<"</th>\n"
            <<"</tr>\n";


    }
    fout<<"</table>\n"
          "\n"
          "\n"
          "</body>\n"
          "</html>";

    return filename;
}