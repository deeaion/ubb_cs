#include "IteratorMDO.h"
#include "../MDO/MDO.h"
/** INITIALIZER
 * @COMPLEXITY: THETA(1)
 */
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	prim();
}
/** FIRST ELEMENT OF MDO
 * @COMPLEXITY: THETA(1)
 */
void IteratorMDO::prim(){
	i_l=dict.prim;
    if(i_l!=-1)
        i_m=this->dict.elems[i_l].prim;
}
/** NEXT ELEMENT TO POINT AT AT.
 * @COMPLEXITY: THETA(1)
 */
void IteratorMDO::urmator(){
    if (!this->valid())
    {
        throw exception();

    }

    i_m = this->dict.elems[i_l].urm[i_m];

    if (i_m == -1 || i_m == this->dict.elems[i_l].primLiber) // daca ajungem la finalul listei mici
    {
        i_l = this->dict.urm[i_l];
        if(i_l != -1)
            i_m = this->dict.elems[i_l].prim;
    }
}
/** is iterator valid?
 * @COMPLEXITY: THETA(1)
 */
bool IteratorMDO::valid() const{
	/* de adaugat */
    if(i_l==-1||i_m==-1)
	return false;
    if(i_l>=0&&i_m>=0 &&dict.cp>i_l&&dict.elems[i_l].cp>i_m
                    &&i_l!=dict.primLiber&&i_m!=dict.elems[i_l].primLiber)
        return true;
    return false;
}
/** Element found at iterator
 * @COMPLEXITY: THETA(1)
 */
TElem IteratorMDO::element() const{
    if (!this->valid())
        throw exception();

    return this->dict.elems[i_l].vals[i_m];
	//return pair <TCheie, TValoare>  (-1, -1);
}


