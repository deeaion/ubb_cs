#include "../Iterator/IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;
/**LISTA !*/
/**
 * CREATING LIST NORMALLY
 * @COMPLEXTIY: θ(1)
 */
SmallList::SmallList() {
    prim=-1;
    primLiber=-1;
    cp=0;
    len=0;
    initialized=0;

}
/**LISTA !*/
/**
 * CREATING LIST for a certain key
 * @COMPLEXTIY: θ(1)
 */
SmallList::SmallList(TCheie c) {
    len=0;
    initialized=1;
    cheie=c;
    this->prim=-1;
    this->primLiber=0;
    this->cp=CAPACITY;
    this->vals=new TElem [cp];//trebuie dealocat. Am construit 2 liste
    urm=new int[cp];
    for(int i=0;i<=cp-1;i++)
    {
        urm[i]=i+1;
    }
    urm[cp-1]=-1;// gata nu mai ai unde
}
/**LISTA !*/
/**
 * Alocate node to a certain key
 * @COMPLEXTIY: θ(1)
 */
int SmallList::aloca() {
    int i=primLiber;//ocupam poz prim Liber
    primLiber=urm[primLiber];//urm de prim Liber devine noul liber
    return i;
}
/**Dealocate node of a certain position
@COMPLEXTIY: θ(1)*/
void SmallList::dealoca(int i) {
    urm[i]=primLiber;//Cum acest nod va deveni liber el va deveni prim Liber
    //asa ca noul prim liber va pointa la vechiul prim liber
    primLiber=i;
}
/**Create new node for values
@COMPLEXTIY: θ(1)<-amortizata*/
int SmallList::creeazaNod(TElem el) {
    if(primLiber==-1)//daca nu exista noduri libere
        redim();
    int i=aloca();//alocam spatiul
    vals[i]=el;
    urm[i]=prim;
    prim=i;
    len++;
    return i;//poz nod
}
/**Redimension of vector
@COMPLEXTIY: θ(cp*2/n)*/
void SmallList::redim() {
    int cp_nou=cp*2;
    TElem * elems_nou=new TElem [cp_nou];
    int *urm_nou=new int[cp_nou];
    //copiem el
    for (int i = 0; i < cp; ++i)
    {
        elems_nou[i] = vals[i];
        urm_nou[i] = urm[i];
    }
    //marcam restul de poz ca si goale
    for (int i = cp; i < cp_nou - 1; ++i)
    {
        urm_nou[i] = i + 1;
    }
    urm_nou[cp_nou-1]=-1;
    primLiber=cp;
    //stergem vectorul vechi
    delete[] urm;
    delete[] vals;

    this->vals=elems_nou;
    this->urm=urm_nou;
    this->cp=cp_nou;
}
/**PRIVATE PART OF MDO*/
/**
 * Marcheaza un nod ca fiind ocupat
 * @COMPLEXITY: THETA(1)
 */
int MDO::aloca() {
    int i=primLiber;//ocupam poz prim Liber
    primLiber=urm[primLiber];//urm de prim Liber devine noul liber
    return i;
}
/**
 * MARCHEAZA UN NOD CA FIIND LIBER
 * @COMPLEXITY: Theta(1)
 */
void MDO::dealoca(int i) {
    urm[i]=primLiber;//Cum acest nod va deveni liber el va deveni prim Liber
    //asa ca noul prim liber va pointa la vechiul prim liber
    primLiber=i;
}
/**
 * CREEAZA UN NOD PT CHEIE SI VALORIILE LUI.
 * Complexitate:Theta(1) - amortizata (din cauza redimensionarii)
 *returns: poz nodului
 */
 int MDO::creeazaNod(TElem el) {
     if(primLiber==-1)//daca nu exista noduri libere
         redim();
     int i=aloca();//alocam spatiul
     SmallList list(el.first);
     elems[i]=list;
     elems[i].creeazaNod(el);
     return i;//poz nod
 }
/**Redimensiune lista principala
@COMPLEXTIY: θ(cp*2/n)*/
 void MDO::redim() {
     int cp_nou=cp*2;
     int *urm_nou=new int[cp_nou];
     SmallList *elems_nou= new SmallList[cp_nou];
     //copiem el
    for (int i = 0; i < cp; ++i)
    {
        urm_nou[i] = urm[i];
        elems_nou[i]=elems[i];
      //  cout<<urm_nou[i]<<"\n";
    }

    //marcam restul de poz ca si goale
    for (int i = cp; i < cp_nou - 1; ++i)
    {
        urm_nou[i] = i + 1;
      //  cout<<urm_nou[i]<<"\n";
    }
    //cout<<"----\n";
    urm_nou[cp_nou-1]=-1;
    primLiber=cp;
    //stergem vectorul vechi
   // delete [] elems;
   int * to_del=urm;
   delete [] elems;
   delete [] urm;
   this->elems=elems_nou;
    this->urm=urm_nou;
    this->cp=cp_nou;
 }
/** Creeare MDO
 * @COMPLEXITY: THETA(1);
 */
MDO::MDO(Relatie r) {
    len=0;
    this->rel=r;
    this->prim=-1;
    this->primLiber=0;
    this->cp=CAPACITY;
    this->elems=new SmallList[cp];//trebuie dealocat. Am construit 2 liste
    urm=new int[cp];
    for(int i=0;i<cp-1;i++)
    {
        urm[i]=i+1;
    }
    urm[cp-1]=-1;// gata nu mai ai unde

}
/**Adding node
 * BC-> MDO empty θ(1)
 * WC->Add at the end of MDO: θ(n)
 * AC-> It is somewhere in the list
@COMPLEXTIY: O(n)*/
void MDO::adauga(TCheie c, TValoare v) {
	//dictionarul este vid-> θ(1) amortizata
    if(prim==-1)
    {
        TElem el;
        el.first=c;
        el.second=v;
        int poz= creeazaNod(el);
        urm[poz]=prim;
        prim=poz;
        len=1;
        //elems[c].len++;
        //printare();
        return;
    }
    //LISTA NU E VIDA.
    //Time complexity: O(n)<- nr el
    int pre=-1;
    int curent=prim;
    while(curent>-1&&rel(elems[curent].cheie,c))
    {
        //daca am gasit elementul cat timp am parcurs eu lista
        if(elems[curent].cheie==c)
        {
            TElem el;
            el.first=c;
            el.second=v;
            //adaugam elementul in lista
            elems[curent].creeazaNod(el);
            //elems[c].len++;
           // elems[curent].len++;
            len++;
            //printare();
            return;

        }
        pre=curent;
        curent=urm[curent];
      //  cout<<"!"<<curent<<"P";
    }
    //daca suntem la sf
    //θ(1)
    if(curent<=-1)
    {
        TElem el;
        el.first=c;
        el.second=v;
        int i=this->creeazaNod(el);
    //    elems[c].len++;
        len++;
        urm[pre]=i;
        urm[i]=-1;
        //printare();
        return;
    }
    //DACA S-A OPRIT DIN CAUZA RELATIEI! θ(1)
    if(!rel(elems[curent].cheie,c))
    {
        TElem element_auxiliar;
        element_auxiliar.first = c;
        element_auxiliar.second = v;
        int i = this->creeazaNod(element_auxiliar);

        if(pre> -1)
        {urm[pre] = i;}
        urm[i] = curent;
        if (pre == -1)
            this->prim = i;
        this->len++;

        //printare();
        //elems[c].len++;
        return;
    }
}
/** Returning values for A KEY
 * @COMPLEXITY: O(lungime lsi princ*lungime lsi pt cheie) deci O(n^2);
 */
vector<TValoare> MDO::cauta(TCheie c) const {
	vector<TValoare> v;
    int curent=prim;
    while(curent!=-1&&rel(this->elems[curent].cheie,c))
    {
        if(this->elems[curent].cheie==c)
        {
            int f_el=elems[curent].prim;
            TElem* vals=elems[curent].vals;
            int* urm_e=elems[curent].urm;
            while(f_el!=-1)
            {
                v.push_back(vals[f_el].second);
                f_el=urm_e[f_el];
            }
            return v;
        }
        curent=urm[curent];
    }


    return v;
}
/** Deletes val from key lsi.
 * @COMPLEXITY: O(len(key_LSI))/O(n);
 */
bool MDO::sterge_val(TCheie c,TValoare v,int poz) {
    TElem* val=this->elems[poz].vals;
    int anterior=-1;
    int prim_v=this->elems[poz].prim;
    int* urm_v=this->elems[poz].urm;
    while(prim_v!=-1)
    {
        if(val[prim_v].second==v)
        {break;}
        anterior=prim_v;
        prim_v=urm_v[prim_v];
    }
    //s-a parcurs dar nu mai ai unde
    if(prim_v==-1)
        return false;
    if(prim_v==elems[poz].prim)
    {
        //daca sunt la primul el doar schimb prim
        elems[poz].prim=elems[poz].urm[prim_v];
        elems[poz].len--;
       // //printare();
    }
    else
    {
        urm_v[anterior]=urm_v[prim_v];
        ////printare();
    }
    elems[poz].dealoca(prim_v);
    elems[poz].len--;
    //printare();
    return true;
}
/** Deleting Value for Key.
 ** If There are no values left for deleting i will just delete the key
 **
 * @COMPLEXITY O(lungime lsi princ*lungime lsi pt cheie) deci O(n^2);
 * Best Case: Theta(1) -> first el
 * WORST CASE: THETA(len(lsi_m)*len(lsi(key)) -> daca nu exista valoarea pt cheia care e pe ult poz
 *
 */
bool MDO::sterge(TCheie c, TValoare v) {
	//stergerea aka cea mai complicata
    if(prim==-1)
        return false;
    int curent=prim;
    int anterior=-1;
    if(c==elems[curent].cheie)
    {
        bool result= sterge_val(c,v,curent);
        if(!result)
            return false;

        if(elems[curent].prim==-1)
        {   prim=urm[prim];
            dealoca(curent);
            this->len--;}
        else
        {
            this->len--;
        }
        //printare();
        return true;
    }
    else{
        while(curent!=-1&&
        rel(elems[curent].cheie,c)
        &&elems[curent].cheie!=c)
        {
            anterior=curent;
            curent=urm[curent];
        }
        if(this->elems[curent].cheie==c)
            {
                bool res=sterge_val(c,v,curent);
                if(!res)
                    return false;
                else
                {
                    if(elems[curent].prim==-1)
                    {
                        if(urm[anterior]==urm[len-2])
                        {
                            //sunt la sf
                            //so i just dealocate it
                            dealoca(curent);
                        }
                        else
                        {
                            urm[anterior]=urm[curent];
                            dealoca(curent);

                        }
                    }
                    len--;
                    //printare();
                    return true;

                }
            }
        return false;
    }
    //daca primul el este 0
	return false;
}
/** DIM
 * @COMPLEXITY: THETA(1)
 */
int MDO::dim() const {
    return this->len;
}
/** Is MDO empty?
 * @COMPLEXITY: THETA(1)
 */
bool MDO::vid() const {
   // cout<<"!!!!"<<len<<"!!!!";
	if(len==0)
        return true;
    else
        return false;
}
/** Iterator for MDO
 * @COMPLEXITY: THETA(1)
 */

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}
/*
 * Function that returns the most frequent value
 * @COMPLEXITY: THETA(len(lsi_main)*len(lsi_cheie))
 */
TValoare MDO::ceaMaiFrecventaValoare() const {
    if(vid())
    {
        return NULL_TVALOARE;
    }
    vector<pair<TValoare,int>> frecvente;
    int curent=prim;
    while(curent!=-1)
    {
        int curent_val=elems[curent].prim;
        while(curent_val!=-1)
        {   bool found=false;
            for(int i=0;i<frecvente.size();i++)
            {
                if(frecvente[i].first==elems[curent].vals[curent_val].second)
                {
                    frecventa t= make_pair(elems[curent].vals[curent_val].second,frecvente[i].second+1);
                    frecvente[i]= t;
                    found=true;
                }
            }
            if(!found)
            {
                frecvente.push_back(make_pair(elems[curent].vals[curent_val].second,1));
            }
            curent_val=elems[curent].urm[curent_val];
        }
        curent=urm[curent];
    }
    int max=-1;
    int maxVal=0;
    for(auto j:frecvente)
    {
        if(j.second>max)
        {
            max=j.second;
            maxVal=j.first;
        }
    }
    return maxVal;

}
/** Destructor
 * @COMPLEXITY: THETA(cp)
 */
MDO::~MDO() {
    for (int p = 0; p < cp; p++) {
        if (elems[p].initialized== 1) {
            delete[] elems[p].vals;
            delete[] elems[p].urm;
        }


        //delete elems[p];
    }
    delete []elems;
    delete[] urm;
}
