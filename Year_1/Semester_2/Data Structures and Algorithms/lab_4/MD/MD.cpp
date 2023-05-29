#include "MD.h"
#include "../Iterator/IteratorMD.h"
#include <exception>
#include <iostream>
#define len 200000
#define NULL_TVALUE -1
using namespace std;
/* Time Complexity: theta(1)
   Creeare nod cu cheie noua
*/
Nod::Nod(TCheie key, vector<TElem> &vals) :vals{vals}{
    cheie=key;
   // vals=vals;
}
/* Time Complexity: theta(m)
  Constructor MD. Creeam un MD cu m poz pt table
*/
MD::MD() {
	n=0;
    m=len;
    //urm.resize(m,-1);
    keys=new PNod[m];
    for(int i=0;i<m;i++)
    {
        this->keys[i]= NULL;
    }
    //primLiber=0;
}

/* Time Complexity: theta(1)
   Calculator for dispertion function 2(+*/
int MD::d2(TCheie c) const {
    return 1+c%(m-1);
}

/* Time Complexity: theta(1)
   Calculator for dispertion function 1(+*/
int MD::d1(TCheie c) const {
    return c%m;
}
/* Time Complexity: theta(1)
   Calculator for dispertion function */
int MD::d(TCheie c, int i) const {
    return  (d1(abs(c))+i* d2(abs(c)))%m;
}
/* Time Complexity: thata(1) - Average case (amortizata) //cand sunt toate dispersate normal
 *                  O(m) - Worst case //cand exista lupte pentru a o cauta poz

*/

void MD::adauga(TCheie c, TValoare v) {
	int i=0;

    int index=-2;
    int pos=d(c,i);
    while(i!=m)
    {
        pos=d(c,i);
        //inseamna ca nu exista nimic aia
        if(keys[pos]== nullptr)
        {   vector<TElem> elems;
            PNod value=new Nod(c,elems);
            keys[pos]=value;
            n++;
            value->vals.push_back(make_pair(c,v));
            return;
        }
        if(keys[pos]->cheie==c)
        {
            keys[pos]->vals.push_back(make_pair(c,v));
            n++;
            return;

        }
        i++;

    }

}


bool MD::sterge(TCheie c, TValoare v) {
    int i = 0;
    int pos = d(c, i);
    while (i < m) {
        if (keys[pos] != nullptr)
            if (keys[pos]->cheie == c)
                break;
        i++;
        pos = d(c, i);
    }
    bool found = false;
    if (i == m)
        return false;
    for (int i = 0; i < keys[pos]->vals.size(); i++) {
        if (keys[pos]->vals[i].second == v) {
            keys[pos]->vals.erase(keys[pos]->vals.begin() + i);
            n--;
            found = true;
            break;
        }
    }
    if (found) {
        if (keys[pos]->vals.size() == 0) {
            keys[pos]->vals.clear();
            delete keys[pos];
            keys[pos] = nullptr;
        }
        return true;
    }
    return false;
}

/* Time Complexity: O(k) - Average case, O(k + m) - Worst case
        Dat hash table ului avem o cautare amortizata cand vine vorba de cautarea cheii in average case.
                Ce ar fi theta(1). Insa cautam si toate val de la cheie. Asa ca avem O(1+k)=O(k)
                Worst case cand nu ajuta amortiz e O(k+m)
*/
vector<TValoare> MD::cauta(TCheie c) const {
    vector<TValoare> vals;
    int i=0;
    int pos;
    pos=d(c,i);
    if(pos>n)
        return vals;
    while(i<m||pos>m)
    {   if(keys[pos]!= NULL)
            if(keys[pos]->cheie==c)
                break;
        i++;
        pos= d(c,i);
    }
    if(i==m||pos>m)
        return vals;
    for(auto j:keys[pos]->vals)
    {
        vals.push_back(j.second);
    }
	return vals;
}


/*
 * Time complexity: theta(1)
 * Dimension of MD
 */
int MD::dim() const {

	return n;
}

/*
 * Time complexity: theta(1)
 * See if MD is empt
 */
bool MD::vid() const {
	if(n==0)
        return true;
    return false;
}

/*
 * Time complexity: theta(1)
 * Reference to our iterator
 */
IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}

/* Time Complexity: O(m)
    Avem odata parcurgerea pe el tabloului O(m). Stergerea in el se face in Theta(1) constant. Asa ca avem BC=WC=AC
    ->O(m)
*/
MD::~MD() {
	for(int i=0;i<m;i++)
    {
        if(keys[i]!= NULL)
        {
            keys[i]->vals.clear();
            delete keys[i];
        }
    }
    delete [] keys;
}

