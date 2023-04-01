//
// Created by Deea on 3/10/2023.
//

#ifndef LAB_1_COLECTIE_H
#define LAB_1_COLECTIE_H
//colectie.h
#pragma once
#include <exception>
#include "../Iterator/IteratorColectie.h"

class Iterator;

typedef int TElem;

//pentru definirea unor relatii
typedef bool (*Relatie)(TElem, TElem);

bool rel(TElem, TElem);

class IteratorColectie;

//pentru perechea element,frecventa
typedef struct {
    TElem e;
    int frecv;

} TPereche;

class Colectie {
private:
    //capacitatea colectiei
    int cp;
    //dimensiunea colectiei
    int n;
    //dimensiunea colectie_cu_tot cu frecventa
    int n_total;
    //elementele
    TPereche *p;

    void redim();

public:
    //constructorul implicit
    Colectie();

    //destructorul colectiei
    ~Colectie();
//pentru ca Iteratorul sa poata accesa reprezentarea vectorului
    friend class IteratorColectie;

    //adauga un element in colectie
    void adauga(TElem);

    //sterge o aparitie a unui element din colectie
    //returneaza adevarat daca s-a putut sterge
    bool sterge(TElem e);

    //verifica daca un element se afla in colectie
    bool cauta(TElem elem) const;

    //returneaza numar de aparitii ale unui element in colectie
    int nrAparitii(TElem elem) const;

    //intoarce numarul de elemente din colectie;
    int dim() const;

    //verifica daca colectia e vida
    bool vida() const;

    //returneaza un iterator pe colectie
    IteratorColectie iterator() const;

    void adaugaAparitii(int nr_aparitii,TElem elem);


};
#endif //LAB_1_COLECTIE_H
