//
// Created by Deea on 5/23/2023.
//

#include "Repo.h"

void Repo::loadRepo() {
    ifstream f(path);
    Cutremur cut{};
    while(f>>cut)
    {
        cutremure.push_back(cut);
    }
    f.close();
}

void Repo::store(const Cutremur &cut) {
    cutremure.push_back(cut);
}