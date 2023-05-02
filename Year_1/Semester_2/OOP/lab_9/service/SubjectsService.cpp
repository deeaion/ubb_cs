//
// Created by Deea on 3/31/2023.
//

#include "SubjectsService.h"
/** CONTRACT
 * */
const vector<Subject> & SubjectsService::getAllContract() noexcept {
     return contract.get_Contract();
 }
 void SubjectsService::generateContract(int nrSubjects) {
    contract.generate_contract(nrSubjects,repo.getAll());
}
void SubjectsService::exportContract(const std::string &name) {
    contract.export_contract(name);
}
void SubjectsService::emptyContract() {
    contract.empty_contract();
}
void SubjectsService::add_to_contract(const string& name, const string& teacher,const vector<Subject>& filtered)
{
    auto found=repo.searchForSubject(name,teacher);
    if(found!=-1)
    {
        //inseamna ca exista deja in subiecte cel introdus deci doar il adaugam
        auto subject=repo.getSubject(name,teacher);
        contract.add_contract(subject);
    }
    else
    {
        //inseamna ca nu exista . soo trebuie sa luam unul rand
        auto to_add=filtered;
        std::shuffle(to_add.begin(),to_add.end(),std::default_random_engine(time(0)));
       contract.add_contract(filtered.back());
    }
}
void SubjectsService::Undo() {
        if (undoActions.empty()) {
            throw RepositoryException{"Nu mai exista operatii"};
        }
        undoActions.back()->doUndo();
        undoActions.pop_back();
    repo.saveRepository();
}
int SubjectsService::getContractSize() {
     return (int)contract.get_Contract().size();
 }

void SubjectsService::updateSubject(const string &name, const string &teacher, int hours, const string &type) {
    Subject modifiecObject{name, hours, type, teacher};
    Subject oldObject= searchForSubject(name,teacher);
    ValidatorSubject::validateSubject(modifiecObject);
    repo.updateSubjectRepo(modifiecObject);
    undoActions.push_back(std::make_unique<UndoModifica>(oldObject,repo));
    repo.saveRepository();
}


void SubjectsService::addSubject(const std::string &name, int hours, const string &teacher,
                                 const string &type) {
    Subject subjectToAdd{name, hours, type, teacher};
//    std::cout<<"\nsunt de dupa creere obiect\n";
    ValidatorSubject::validateSubject(subjectToAdd);
    repo.store(subjectToAdd);
    undoActions.push_back(std::make_unique<UndoAdauga>(subjectToAdd,repo));
//    std::cout<<"\nsunt de dupa adaugare obiect\n";
    repo.saveRepository();
}

void SubjectsService::deleteSubject(const std::string &name, const std::string &teacher) {
    Subject copy=repo.getSubject(name,teacher);
    repo.removeSubjectRepo(name, teacher);
    undoActions.push_back(std::make_unique<UndoSterge>(repo,copy));
    repo.saveRepository();
}

const Subject &SubjectsService::searchForSubject(const std::string &name, const std::string &teacher) {
    return repo.getSubject(name, teacher);
}


const vector<Subject> &SubjectsService::getAll() noexcept {
    return this->repo.getAll();
}

//vector<Subject> SubjectsService::generalSort(bool(*cmpKey)(const Subject &, const Subject &)) {
//    vector<Subject> subjects{repo.getAll()};
//    for (size_t i = 0; i < subjects.size(); i++) {
//        for (size_t j = i + 1; j < subjects.size(); j++) {
//            if (!cmpKey(subjects[i], subjects[j])) {
//                //interschimbam
//                Subject aux = subjects[i];
//                subjects[i] = subjects[j];
//                subjects[j] = aux;
//            }
//        }
//    }
//    return subjects;}

vector<Subject> SubjectsService::filterByType(const string& type) {
    vector<Subject> filtered;
    copy_if(repo.getAll().begin(),
            repo.getAll().end(),
            std::back_inserter(filtered),
            [type](const Subject& sbj) {
                return sbj.get_type()==type;
            });
    return filtered;}

vector<Subject> SubjectsService::filterByHours(int hours) {
    vector<Subject> filtered;
    copy_if(repo.getAll().begin(),
            repo.getAll().end(),
            std::back_inserter(filtered),
            [hours](const Subject& sbj) {
        return sbj.get_hours()==hours;
    });
    return filtered;}

vector<Subject> SubjectsService::filterByTeacher(const string &teacher) {
    vector<Subject> filtered;
    copy_if(repo.getAll().begin(),
            repo.getAll().end(),
            std::back_inserter(filtered),
            [teacher](const Subject& sbj) {
                return sbj.get_teacher()==teacher;
            });
    return filtered;}

 vector<Subject> SubjectsService::filterBySubjectName(const string &name) {
    vector<Subject> filtered;
    copy_if(repo.getAll().begin(),
            repo.getAll().end(),
            std::back_inserter(filtered),
            [name](const Subject& sbj) {
                return sbj.get_name()==name;
            });
    return filtered;}


vector<Subject> SubjectsService::sortByName() {
    auto sorted=repo.getAll();
    sort(sorted.begin(),sorted.end(), cmpName);
    return sorted;}

vector<Subject> SubjectsService::sortByHours() {
    auto sorted=repo.getAll();
    sort(sorted.begin(),sorted.end(), cmpHours);
    return sorted;}

vector<Subject> SubjectsService::sortByTeacherandType() {
    auto sorted=repo.getAll();
    sort(sorted.begin(),sorted.end(), cmpTeacherandType);
    return sorted;}


    set <string> SubjectsService::number_of_types()
    {  set <string> types;
        vector<Subject> subjects=getAll();
        for(const auto &i:subjects)
        {       types.insert(i.get_type());
        }
        return types;
    }

map<string,vector<Subject>> SubjectsService:: creatingmap()
{
    map<string,vector<Subject>> mapFiltered;
    set <string> types= number_of_types();
    for(const auto& t: types)
    {
        vector <Subject> found_obj= filterByType(t);
        mapFiltered[t]=found_obj;
    }
    return mapFiltered;

}
