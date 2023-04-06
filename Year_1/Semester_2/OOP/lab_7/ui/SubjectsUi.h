//
// Created by Deea on 3/31/2023.
//

#ifndef LAB_6_7_SUBJECTSUI_H
#define LAB_6_7_SUBJECTSUI_H
#pragma once

#include "../service/SubjectsService.h"
#include <iostream>
#include <string>

using std::string;

using std::cout;
using std::cin;
using std::getline;

class SubjectsUi {
    SubjectsService &ctr;

    void UiAdd();

    void Uidelete();

    void Uiupdate();

    void Uisearch();

    void Uifilter();

    void Uisort();

    static void print_subjects(const DynamicVector<Subject> &subjects);

    void print_all();

    static void menu();

public:
    explicit SubjectsUi(SubjectsService &ctr) : ctr{ctr} {

    }

    //we dont allow to copy the objects
    SubjectsUi(const SubjectsUi &ot) = delete;

    void start();
};


#endif //LAB_6_7_SUBJECTSUI_H
