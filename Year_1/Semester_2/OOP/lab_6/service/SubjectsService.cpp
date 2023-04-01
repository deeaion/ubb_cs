//
// Created by Deea on 3/31/2023.
//

#include "SubjectsService.h"

void SubjectsService::updateSubject(const string &name, const string &teacher, int hours, const string &type) {
    Subject modifiecObject{name, hours, type, teacher};
    ValidatorSubject::validateSubject(modifiecObject);
    repo.updateSubjectRepo(modifiecObject);
}

void SubjectsService::addSubject(const std::string &name, int hours, const string &teacher,
                                 const string &type) {
    Subject subjectToAdd{name, hours, type, teacher};
    ValidatorSubject::validateSubject(subjectToAdd);
    repo.store(subjectToAdd);
}

void SubjectsService::deleteSubject(const std::string &name, const std::string &teacher) {
    repo.removeSubjectRepo(name, teacher);
}

const Subject &SubjectsService::searchForSubject(const std::string &name, const std::string &teacher) {
    return repo.getSubject(name, teacher);
}


const vector<Subject> &SubjectsService::getAll() noexcept {
    return this->repo.getAll();
}

vector<Subject> SubjectsService::generalSort(bool(*cmpKey)(const Subject &, const Subject &)) {
    vector<Subject> subjects{repo.getAll()};
    for (size_t i = 0; i < subjects.size(); i++) {
        for (size_t j = i + 1; j < subjects.size(); j++) {
            if (!cmpKey(subjects[i], subjects[j])) {
                //interschimbam
                Subject aux = subjects[i];
                subjects[i] = subjects[j];
                subjects[j] = aux;
            }
        }
    }
    return subjects;
}

vector<Subject> SubjectsService::filter(const function<bool(const Subject &)> &fct) {
    vector<Subject> result;
    for (const auto &subject: repo.getAll()) {
        if (fct(subject)) {
            result.push_back(subject);
        }
    }
    return result;
}

vector<Subject> SubjectsService::filterByHours(int hours) {
    return filter([hours](const Subject &sbj) {
        return sbj.get_hours() == hours;
    });
}

vector<Subject> SubjectsService::filterByTeacher(const string &teacher) {
    return filter([teacher](const Subject &sbj) {
        return sbj.get_teacher() == teacher;
    });
}

vector<Subject> SubjectsService::sortByName() {
    return generalSort(cmpName);
}

vector<Subject> SubjectsService::sortByHours() {
    return generalSort(cmpHours);
}

vector<Subject> SubjectsService::sortByTeacherandType() {
    return generalSort(cmpTeacherandType);

}