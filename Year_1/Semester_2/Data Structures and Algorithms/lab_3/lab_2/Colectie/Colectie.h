#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;
class Nod;
typedef Nod *PNod;
class Nod{
public:
    friend class Colectie;
    //constructor
    Nod(TElem e,int frecventa,PNod urm);
    TElem element() const;
    int get_frecventa() const;
    PNod urmator();
private:
    TElem e;
    PNod urm;
    int frecventa;
};
class Colectie
{

private:
	/* aici e reprezentarea */
    PNod prim;
    PNod ultim;
    int size=0;
public:
		//constructorul implicit
        friend class IteratorColectie;
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


};

