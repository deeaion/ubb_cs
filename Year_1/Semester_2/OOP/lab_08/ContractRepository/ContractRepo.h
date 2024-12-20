//
// Created by Deea on 4/14/2023.
//

#ifndef LAB_8_CONTRACTREPO_H
#define LAB_8_CONTRACTREPO_H
#include <vector>
#include "../domain/Subject.h"
using std::vector;
using std::shuffle;
#include <random>
#include <fstream>
#include <algorithm>
class ContractRepo {
private:
    vector<Subject> Contract;
public:
    void empty_contract() noexcept;
    void add_contract(const Subject& sbj);
    void generate_contract(int nr_subjects, const vector<Subject>& memory);
    void export_contract(const string& name_file);
    const vector<Subject>& get_Contract();
    int search_subject_contract(const string& name, const string& teacher);

};


#endif //LAB_8_CONTRACTREPO_H
