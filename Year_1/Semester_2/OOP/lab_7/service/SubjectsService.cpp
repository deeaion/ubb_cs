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


const DynamicVector<Subject> &SubjectsService::getAll() noexcept {
    return this->repo.getAll();
}

DynamicVector<Subject> SubjectsService::generalSort(bool(*cmpKey)(const Subject &, const Subject &)) {
    DynamicVector<Subject> subjects{repo.getAll()};
    for (int i=0;i<subjects.getSize();i++) {
        for (size_t j = i + 1; j < subjects.getSize(); j++) {
            if (!cmpKey(subjects[i], subjects[j])) {
                //interschimbam
                Subject aux = subjects[i];
                subjects[i] = subjects[j];
                subjects[j] = aux;
            }
        }
    }
    return subjects;}

DynamicVector<Subject> SubjectsService::filter(const function<bool(const Subject &)> &fct) {
    DynamicVector<Subject> result;
    for (const auto &subject: repo.getAll()) {
        if (fct(subject)) {
            result.push_back(subject);
        }
    }
    return result;}

DynamicVector<Subject> SubjectsService::filterByHours(int hours) {
    return filter([hours](const Subject &sbj) {
        return sbj.get_hours() == hours;
    });
}

DynamicVector<Subject> SubjectsService::filterByTeacher(const string &teacher) {
    return filter([teacher](const Subject &sbj) {
        return sbj.get_teacher() == teacher;
    });
}

DynamicVector<Subject> SubjectsService::sortByName() {
    return generalSort(cmpName);
}

DynamicVector<Subject> SubjectsService::sortByHours() {
    return generalSort(cmpHours);
}

DynamicVector<Subject> SubjectsService::sortByTeacherandType() {
    return generalSort(cmpTeacherandType);

}