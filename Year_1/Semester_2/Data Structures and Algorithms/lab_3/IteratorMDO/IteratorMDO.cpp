#include "IteratorMDO.h"
#include "../MDO/MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	keylist=d.lsikeys;
    currentKey=d.lsikeys->head;
    if(currentKey!= nullptr)
        currentValue=currentKey->values->head;
}

void IteratorMDO::prim(){
	currentKey=dict.lsikeys->head;
    if(currentKey!= nullptr)
        currentValue=currentKey->values->head;
}

void IteratorMDO::urmator(){
	if(!valid())
    {
        throw exception();
    }
    if(currentValue->urm!= nullptr)
    {
        currentValue=currentValue->urm;
    }
    else
    {
        currentKey=currentKey->urm;
        if(currentKey!= nullptr)
        {
            currentValue=currentKey->values->head;
        }
    }
}

bool IteratorMDO::valid() const{
	return currentKey!= nullptr;
}

TElem IteratorMDO::element() const{
	if(!valid())
    {
        throw exception();
    }
    return TElem (currentKey->key,currentValue->value);
}


