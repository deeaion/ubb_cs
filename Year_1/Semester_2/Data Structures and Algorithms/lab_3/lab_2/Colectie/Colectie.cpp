#include "Colectie.h"
#include "../IteratorColectie/IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;
//functii nod
/*
 * Create node.
 * Time Complexity: Θ(1)
 */
Nod::Nod(TElem e,int frecventa,PNod urm)
{
    this->e=e;
    this->urm=urm;
    this->frecventa=frecventa;
}
/*
 * To get frequency of node:
 * Time Complexity: Θ(1)
 */
int Nod::get_frecventa() const {
    return this->frecventa;
}
/*
 * To get the respective element of the node.
 * Time Complexity: Θ(1)
 */
TElem Nod:: element() const
{
    return this->e;
}

/*
 * To get the next node pointer.
 * Time Complexity: Θ(1)
 */
PNod Nod::urmator() {
    return urm;
}
/*
 * Create collection.
 * Time Complexity: Θ(1)
 */
Colectie::Colectie() {
	/* de adaugat */
    //initializam primul element
    prim= nullptr;
    ultim= nullptr;
}

/*
 * Adding Elements in collection.
 * Time Complexity: O(n) ->average case
 *                  Θ(1) -> best case (Element does not exist/ collection is empty/ Element is on the first position)
 *                  Θ(n) -> worst case (Element is on the last position of the collection!)
 */
void Colectie::adauga(TElem elem) {

    if (this->dim() != 0) {
        if (!cauta(elem)) {
            PNod nou = new Nod(elem, 1, nullptr);
            this->ultim->urm = nou;
            ultim=nou;

        } else {
            PNod p = this->prim;
            while (p != nullptr) {
                if (elem == p->e)
                    p->frecventa++;
                p=p->urm;
            }
        }
    }
    else
    {
        PNod nou = new Nod(elem, 1, nullptr);
        prim=nou;
        ultim= nou;
    }
    this->size++;
}

/*
 * Deleting Elements in collection.
 * Time Complexity: O(n) ->average case
 *                  Θ(1) -> best case ( collection is empty/ Element is on the first position)
 *                  Θ(n) -> worst case (Element is on the last position of the collection!)
 */
bool Colectie::sterge(TElem elem) {
    if(dim()==0)
        return false;
	if(!cauta(elem))
        return false;
    //altfel inseamna ca l-am gasit
    //initializam primul
    PNod p=prim;
    if(prim->e==elem)
    {   //cazul mai fav unde nu trebuie sa stergi cu adev
        if(prim->frecventa>1)
            prim->frecventa--;
        //altfel trebuie sa avem un nou prim
        else
        {
            prim=p->urm;
            //daca noul prim e nil inseamna ca lista e vida
            if(prim== nullptr)
                ultim= nullptr;
        }

    }
    else
    {   //daca urm nod dupa el e elem nostru
        while(p->urm->e!=elem)
        {
            p=p->urm;
        }
        //acum elementul chiar e pe nodul cu respectivul teelem
        //daca frecv>1 => scadem doar frecv
        if(p->urm->frecventa>1)
        {
            p->urm->frecventa--;
        }
        else
        {
            //verficam daca e nodul urmator este de la sf
            if(p->urm==ultim)
            {
                ultim=p;
            }
            //altfel stergem nodul
            p->urm=p->urm->urm;
        }

    }
    size--;
    return true;
}

/*
 * Searching if  Elements are  in the  collection.
 * Time Complexity: O(n) ->average case
 *                  Θ(1) -> best case (collection is empty/ Element is on the first position)
 *                  Θ(n) -> worst case (Element is on the last position of the collection!)
 */
bool Colectie::cauta(TElem elem) const {
    PNod p=this->prim;
    while(p!= nullptr)
    {
        if(elem==p->e)
            return true;
        p=p->urm;
    }

	return false;
}
/*
 * Find the number of occurrences of that number.
 * Time Complexity: O(n) ->average case
 *                  Θ(1) -> best case (collection is empty/ Element is on the first position)
 *                  Θ(n) -> worst case (Element is on the last position of the collection!)
 */
int Colectie::nrAparitii(TElem elem) const {
    if(!cauta(elem))
        return 0;
    PNod p=this->prim;
    while(p!= nullptr)
    {
        if(elem==p->e)
            return p->frecventa;
        p=p->urm;
    }
    return 0;
}

/*
 * Number of elements in collection.
 * Time Complexity:
 *                  Θ(1)
 *
 */
int Colectie::dim() const {

	return this->size;
}

/*
 * See if the collection is empty.
 * Time Complexity:
 *                  Θ(1)
 *
 */
bool Colectie::vida() const {
	/* de adaugat */
	return this->size==0;
}
/*
 * Create an iterator for collection.
 * Time Complexity:
 *                  Θ(1)
 *
 */
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
 * Delete collection
 * Time Complexity:
 *                  Θ(n)
 *
 */
Colectie::~Colectie() {
    while(prim!= nullptr)
    {
       PNod p=prim;
       prim=prim->urm;
       delete p;
    }
}


