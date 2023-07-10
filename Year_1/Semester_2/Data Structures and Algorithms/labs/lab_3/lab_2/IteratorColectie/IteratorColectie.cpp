#include "IteratorColectie.h"
#include "../Colectie/Colectie.h"

/*
 * Initialize iterator
 * Time Complexity:
 *                  Θ(1)
 *
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	curent=col.prim;
    current_freq=1;
}
/*
 * Initialize first element
 * Time Complexity:
 *                  Θ(1)
 *
 */
void IteratorColectie::prim() {
	curent=col.prim;
    current_freq=1;
}

/*
 * Make the iterator point to the next element. We are in a collection so the iterator will stay on the current node if we have a valid frequency.
 * Time Complexity:
 *                  Θ(1)
 *
 */
void IteratorColectie::urmator() {
    //daca suntem inca in range ul frecventei atunci ramanem pe nodul asta
	if(curent->get_frecventa()>current_freq)
        current_freq++;
    else
    {
        curent=curent->urmator();
        current_freq=1;
    }
}

/*
 * Sees if iterator is valid
 * Time Complexity:
 *                  Θ(1)
 *
 */
bool IteratorColectie::valid() const {
    if (curent== nullptr)
        return false;
    if(curent->get_frecventa()>=current_freq)
        return true;
    return false;
}


/*
 * Returns element on current position!
 * Time Complexity:
 *                  Θ(1)
 *
 */
TElem IteratorColectie::element() const {
	return curent->element();
}
