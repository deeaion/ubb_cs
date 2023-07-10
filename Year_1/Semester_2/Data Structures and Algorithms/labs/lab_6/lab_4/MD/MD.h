#pragma once
#include<vector>
#include<utility>

using namespace std;

typedef int TCheie;
typedef int TValoare;


typedef std::pair<TCheie, TValoare> TElem;
class Nod;
typedef Nod* PNod;
class IteratorMD;
class Nod {
public:
    friend class MD;
    friend class IteratorMD;
    Nod(TCheie key,vector<TElem>& vals);
private:
    TCheie cheie;
    vector<TElem> vals;

};



class MD
{
	friend class IteratorMD;
    friend class Nod;

private:
	int n;
    int m;
    PNod *keys;
    //vector<int> urm;
    //int primLiber=0;
    int d(TCheie c,int i) const;
    int d1(TCheie c) const;
    int d2(TCheie c) const;
public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();



};

