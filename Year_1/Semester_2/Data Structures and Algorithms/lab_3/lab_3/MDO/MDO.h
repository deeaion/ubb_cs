#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);
//nod pt valori
struct ValueNode
{
    ValueNode *urm;
    TValoare value;
};
//lista de valori
struct ValuesLSI{
    ValueNode *head;
    ValueNode *tail;
};

struct KeyNode{
    TCheie key; //fiecare nod are o cheie
    ValuesLSI* values; // valoriile sunt reprez prin o lsi
    KeyNode *urm; // pointer la urmatoarea cheie
};

struct KeyNodesLSI{
    KeyNode *head;
    KeyNode *tail;
};

class MDO {
	friend class IteratorMDO;
    private:
	KeyNodesLSI* lsikeys;
    Relatie relatie;
    /*
     * in momentul in care se doreste stergerea cu totul a nodului se sterge cu totul.
     * Asta sau in momentul in care nu mai are Tvalori cheia resp
     */
    void deleteKeyElement(KeyNode* pr,KeyNode* current)   ;
    /*
     * stergerea de doar a unei valori la cheia resp
     */
    bool deleteValueElement(ValuesLSI* lsivalues,TValoare value);
    /*
     * search for key node! This is made to not repeat code. If we find we return true. Also we are working with pointers so this if found will also set
     * our pointer to the node
     */
    bool searchForKeyNode(TCheie cheie, KeyNode*& key, KeyNode*& prec) const;

    /*
     * pentru a adauga atunci cand cheia nu exista
     */
    void adaugaCheieNoua(TCheie cheie, TValoare valoare,KeyNode* precedent);

    void adaugaValoareLaFinal(ValuesLSI* lsivalues, TValoare valoare);
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
