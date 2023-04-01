//
// Created by Deea on 3/19/2023.
//
#include "Colectie.h"
#include "../Iterator/IteratorColectie.h"

/*
 * preconditii: e1 si e2 apartin TElem (int)
 * Complexitate: Θ(1) (theta)
 * returns: true -> daca e1<=e2
 *          false -> e1>e2
 */
bool rel(TElem e1, TElem e2) {
    if (e1 <= e2)
        return true;
    return false;
}

/*
 * preconditii: capacitate==size of dynamic array
 * returns : D_A' with cp'=2*cp
 * Complexity: Θ(n) ( Θ(cp) )
 */
void Colectie::redim() {
    TPereche *pNou = new TPereche[2 * cp];
    for (int i = 0; i < n; i++) {
        pNou[i].e = p[i].e;
        pNou[i].frecv = p[i].frecv;
    }
    cp = 2 * cp;
    delete[] p;
    p = pNou;
}

/*
 *precondiiti: -
 * returns: an empty colection ,cp=1
 * Complexity: Θ(1)
 */
Colectie::Colectie() {
    //setez capacitatea
    this->cp = 1;
    //aloc spatiu pentru vector
    p = new TPereche[cp];
    this->n = 0;
    this->n_total = 0;

}

/*
 *preconditii: e->TElem
 *returns: D_M' cu +e ( daca e nu apartine Colectiei)
 *              cu o incrementare a perechii unde se afla elementul
 *Complexity:
 *              Best Case -> Θ(1)
 *              Worst Case -> Θ(n)
 *              Average Case -> O(n)
 */
void Colectie::adauga(TElem e) {
    if (n == cp)
        redim();
    if (!this->cauta(e)) {
        int i, poz = -1;
        int ok = false;
        //in cazul in care colectia este goala
        if (n == 0)
            poz = 0;
            //daca este in relatie cu ult el ! atunci adaugam la sfarsit
        else if (rel(p[n - 1].e, e)) {
            poz = n;
        } else {
            for (i = 0; i < n - 1 && ok == false; i++)
                if (rel(p[i].e, e) && rel(e, p[i + 1].e)) {
                    poz = i + 1;
                    ok = true;
                }
        }
        //inseamna ca e in cazul relatiei noastre cel mai mic
        if (poz == -1) {
            poz = 0;
        }

        //inseram pe pozitia corecta
        for (i = n; i > poz; i--) {
            p[i].e = p[i - 1].e;
            p[i].frecv = p[i - 1].frecv;
        }

        //acum putem sa adaugam elementul pe pozita corespunzatoare
        p[poz].e = e;
        p[poz].frecv = 1;
        n++;


    } else {
        //doar efectuez o cautare binare O(log2n) pentru a cauta unde trebbuie sa incrementez frecv
        int l = 0;
        int r = n;
        int gata = -1;
        while (l < r && gata == -1) {
            int m = (l + r) / 2;
            if (p[m].e == e) {
                p[m].frecv = p[m].frecv + 1;
                gata = 1;
            } else if (rel(p[m].e, e)) {
                l = m + 1;

            } else {
                r = m;
            }
        }
    }
    //in colectie sunt tehnic salvate si frecventele deci orice ar fi incrementam
    n_total++;
}

/*
 *preconditii: e- apartine Colectiei
 *returns: true e- apartine colectiei   D_M'-e ( daca e are doar o aparitie in colectie)
 *                                      nr_aparitii(D_M',e)-1! -> scade frecventa
 *         false e- nu apartine colectiei
 *Complexity:
 *              Best Case -> Θ(1) (poz el=0)
 *              Worst Case -> Θ(n) (elementul se afla pe prima pozitie si are frecventa 1)
 *              Average Case -> O(n)
 */
bool Colectie::sterge(TElem e) {
    if (!cauta(e))
        return false;
    else {
        int i;
        int l = 0;
        int r = n;
        int poz = -1;
        while (l < r && poz == -1) {
            int m = (l + r) / 2;
            if (p[m].e == e)
                poz = m;
            else if (!rel(p[m].e, e)) {
                r = m;

            } else {
                l = m + 1;
            }
        }
        if (p[poz].frecv > 1) {
            p[poz].frecv--;
            n_total--;
        } else {
            for (i = poz; i < n - 1; i++) {
                p[i].e = p[i + 1].e;
                p[i].frecv = p[i + 1].frecv;
            }
            n--;
            n_total--;
        }
        return true;
    }

}

/*
 *preconditii: e- apartine Colectiei
 *returns: true e- apartine colectiei
 *
 *         false e - nu apartine colectiei
 *
 *Complexity:
 *             Θ(log2n) -> binary search
 */
bool Colectie::cauta(TElem elem) const {
    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (p[m].e == elem)
            return true;
        else if (rel(p[m].e, elem)) {
            l = m + 1;

        } else {
            r = m;
        }
    }
    return false;
}
/*
 *preconditii: e->TElem
 *returns: D_M' cu +e cu o frecventa de nr_apariti  ( daca e nu apartine Colectiei)
 *              cu o incrementare a perechii unde se afla elementul de nr_aparitii
 *Complexity:
 *              Best Case -> Θ(nr_aparitii)/ Θ(1)
 *              Worst Case -> Θ(n) - daca nr_aparitii este un n^(k-1)
 *              Average Case -> O(n)
 */
void Colectie::adaugaAparitii(int nr_aparitii,TElem elem)
{
    if(nr_aparitii<0)
    {
        throw "\nNumar de aparitii invalid";

    }
    else
    {
        for(int i=0;i<nr_aparitii;i++)
            adauga(elem);
    }

}
/*
*preconditii: e- apartine Colectiei
*returns: true e- apartine colectiei
*
*         false e - nu apartine colectiei
        *
        *Complexity:
*             Θ(log2n) -> binary search
*/
int Colectie::nrAparitii(TElem elem) const {
    int poz = -1, l = 0, r = n - 1;
    if (!cauta(elem))
        return 0;
    else
        while (l <= r && poz == -1) {
            int m = (l + r) / 2;
            if (p[m].e == elem)
                poz = m;
            else if (!rel(p[m].e, elem)) {
                r = m;

            } else {
                l = m + 1;
            }
        }
    return p[poz].frecv;
}
/*
 * preconditii: -
 * returns: the number of elements in the collection
 */
int Colectie::dim() const {
    return n_total;
}

/*
 * preconditii: -
 * returns: true <- if the collection is empty
 *          false <- if the collection is not empty
 * Complexity : Θ(1)
 */
bool Colectie::vida() const {
    if (n == 0)
        return true;
    else
        return false;
}

/*
 * preconditii: -
 * returns: an iterator for the collection
 * Complexity: Θ(1)
 */
IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}

/*
 *returns -
 * Complexity: Θ(1)
 */
Colectie::~Colectie() {
    //eliberam zona de memorare alocata
    delete[] p;
}
