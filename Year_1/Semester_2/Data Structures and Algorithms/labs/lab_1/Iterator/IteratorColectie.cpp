#include "IteratorColectie.h"
#include "../Colectie/Colectie.h"

/*
 * returns: -
 * sets: current->0
 * Complexity: Θ(1)
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    //seteaza iteratorul pe prima pozitie din vector
    this->curent = 0;

}
/*
 * returns: -
 * sets: element of current position
 * Complexity: Θ(1)
 */
TElem IteratorColectie::element() const{
    return col.p[curent].e;
}
/*
 * returns: false -> if iterator not valide
 *          else true
 *
 * Complexity: Θ(1)
 */
bool IteratorColectie::valid() const {
    return curent<col.n;
}
/*
 * returns: -
 *increments current
 * Complexity: Θ(1)
 */
void IteratorColectie::urmator() {
	curent++;
}
/*
 * returns: -
 * sets: the iterator to 0
 * Complexity: Θ(1)
 */
void IteratorColectie::prim() {
	curent=0;
}
