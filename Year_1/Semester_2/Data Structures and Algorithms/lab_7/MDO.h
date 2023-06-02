#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;
#define cap 2
#define null -1111111
#define nullValue std::make_pair(-1111111,-1111111)
using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
    private:
    //deci find o lista am o lista pt elems, pt st si dr
    TElem *nodes;
    int *left;
    int *right;
    int capacity;
    int root;//radacina
    int size;//cate chei am
    int firstEmpty;

    Relatie r;

    //functii
    void resize();//am v dinamic si tre sa il mod
    void newFirstEmpty();
    int adauga_rec(int node,TElem e);
    int minimum(int node);
    int remove_rec(int node,TElem e,bool &found);
    public:

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
