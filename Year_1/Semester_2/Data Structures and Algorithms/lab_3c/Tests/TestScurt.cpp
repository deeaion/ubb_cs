#include <assert.h>

#include "../MDO/MDO.h"
#include "../Iterator/IteratorMDO.h"

#include <exception>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	MDO dictOrd = MDO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
//   dictOrd.adauga(2,4);
//    dictOrd.adauga(2,5);
    dictOrd.adauga(1,3);
    //dictOrd.adauga(1,4);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());

    vector<TValoare> v= dictOrd.cauta(1);
 //   cout<<"AAAAAAAAA";
    assert(v.size()==2);
    v= dictOrd.cauta(3);
    assert(v.size()==0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    //cout<<"UH";
    while (it.valid()){
    	TElem e = it.element();
       // cout<<e.first<<":"<<e.second<<" \n";
    	it.urmator();
    }
   // cout<<"F";
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());

}
void testFrecventaValoare()
{
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.ceaMaiFrecventaValoare()==-100);
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    assert(dictOrd.ceaMaiFrecventaValoare()==3);
    dictOrd.adauga(2,2);
    assert(dictOrd.ceaMaiFrecventaValoare()==2);
    dictOrd.sterge(1,2);
    assert(dictOrd.ceaMaiFrecventaValoare()==3);
    dictOrd.sterge(1,3);
    assert(dictOrd.ceaMaiFrecventaValoare()==2);
    dictOrd.sterge(2,2);
    assert(dictOrd.ceaMaiFrecventaValoare()==-100);
}
