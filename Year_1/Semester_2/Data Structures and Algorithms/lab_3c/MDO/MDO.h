#pragma once

#include <vector>
#define CAPACITY 2

typedef int TCheie;
typedef int TValoare;
#define NULL_TVALOARE -100;

#include <utility>
#include <iostream>
using namespace std;
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;
typedef pair<TValoare,int> frecventa;
class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);
class SmallList {
friend class MDO;
friend class IteratorMDO;

private:
    /* aici e reprezentarea */

    int cp;
    int *urm;//vectori de poz urmatoare
    //int prim; //primul nod
    int primLiber;//primul el liber din mdo
    int len;//nr element
    int initialized;
    TElem * vals;//vectorul de elemente. Eu o sa am o lista de liste
    TCheie cheie;
    int aloca();
    void dealoca(int i);
    int creeazaNod(TElem el);
    void redim();
    //~SmallList()=default;
public:
    int prim;
    SmallList();
    SmallList(TCheie c);
};
class MDO {
	friend class IteratorMDO;
    friend class SmallList;

private:
	/* aici e reprezentarea */
    Relatie rel;
    int cp;
    int *urm;//vectori de poz urmatoare
     //primul nod
    int primLiber;//primul el liber din mdo
    int len;//nr element
    int prim;
    SmallList* elems;//vectorul de elemente. Eu o sa am o lista de liste
    int aloca();
    void dealoca(int i);
    int creeazaNod(TElem el);
    void redim();
    bool sterge_val(TCheie c, TValoare v,int poz);

    public:
    TValoare ceaMaiFrecventaValoare() const;
    void printare();
	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};
