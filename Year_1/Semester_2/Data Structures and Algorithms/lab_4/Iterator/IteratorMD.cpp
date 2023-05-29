#include "IteratorMD.h"
#include "../MD/MD.h"
#include <exception>
#include <stdexcept>
using namespace std;
/* Time Complexity: O(n + m)
   Initializing index and lungime takes constant time.
 Cautam prima cheie nenula (O(m)).
*/
IteratorMD::IteratorMD(const MD& _md): md(_md) {
index=0;
lungime=md.dim();
if(md.vid())
    return;
index_keys=0;
index_val=0;
while(md.keys[index_keys]== nullptr||md.keys[index_keys]== nullptr)
{
    index_keys++;
}
prim_index_keys=index_keys;

}
/* Time Complexity: theta(1)
 Return : val de la it curent

*/
TElem IteratorMD::element() const{
    return md.keys[index_keys]->vals[index_val];
}
/* Time Complexity: theta(1)
 Return : verify if index si valid

*/
bool IteratorMD::valid() const {
	return this->index<this->lungime;

}
/* Time Complexity: O(1) amortized
 Sunt intr un hash multi map deci este amortizata.
Cautam urmatoarea poz valida. Si setam indexi corespunzand ei

*/
void IteratorMD::urmator() {
	if(!valid())
        throw std::exception();
    this->index++;
    if(md.keys[index_keys]->vals.size()==index_val+1)
    {   index_keys++;
        while(md.keys[index_keys]== nullptr)
        {
            index_keys++;
            if(index_keys==md.m)
                break;
        }
        if(index_keys==md.m)
            return;
        this->index_val=0;
    }
    else
    {
        this->index_val++;
    }
}
/* Time Complexity: theta(1)
 Setting elements to initial values
*/
void IteratorMD::prim() {
	index=0;
    index_keys=prim_index_keys;
    index_val=0;
}
void IteratorMD::revinoKPasi(int k)
{
    if(k<=0||k>index)
    {
        throw std::invalid_argument("Invalid number");
    }
    if(index_val>=k-1)
    {
        index_val=index_val-k;
        index=index-k;
        return;
    }
    int vals_counted=0;
    vals_counted=index_val;
    index_keys--;
    while(1)
    {   //caut urmatoarea cheie din hash table
        while(md.keys[index_keys]== nullptr)
        {
           index_keys--;
        }
        //sunt la un index care are elemente
        index_val=md.keys[index_keys]->vals.size()-1;
        if(index_val>=k-1)
        {
            index_val=index_val-k+1;
            index=index-k;
            break;
        }

    }


}
