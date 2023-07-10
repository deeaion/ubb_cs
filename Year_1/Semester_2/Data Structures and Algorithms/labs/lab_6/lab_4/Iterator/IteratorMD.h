#pragma once
#include "../MD/MD.h"

class MD;

class IteratorMD
{
	friend class MD;

private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorMD(const MD& c);
    int index;
    int index_val;
    int prim_index_keys;
    int index_keys;
    int lungime;
	//contine o referinta catre containerul pe care il itereaza
	const MD& md;
    TElem *array;

	/* aici e reprezentarea  specifica a iteratorului */

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;
        void revinoKPasi(int k);
};

