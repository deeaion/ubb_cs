#include "../IteratorMDO/IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

MDO::MDO(Relatie r) {
	lsikeys = new KeyNodesLSI();
    lsikeys->head= nullptr;
    lsikeys->tail= nullptr;
    relatie=r;
}

bool MDO::searchForKeyNode(TCheie cheie, KeyNode *&node, KeyNode *&precedent) const {
    KeyNode *prec= nullptr;
    KeyNode *key=lsikeys->head;
    while(key!= nullptr)
    {
        if(key->key==cheie)
        {   node=key;
            precedent=prec;
            return true;}

        prec=key;
        key=key->urm;
    }
    precedent=prec;
    key= nullptr;
    return false;
}
void MDO::adaugaCheieNoua(TCheie cheie, TValoare valoare, KeyNode *precedent) {
    KeyNode *nod_nou= new KeyNode();
    nod_nou->key=cheie;
    ValuesLSI* values= new ValuesLSI();
    ValueNode *valueNodehead=new ValueNode();
    valueNodehead->value=valoare;
    values->head=valueNodehead;
    values->head->urm= nullptr;

    values->tail=values->head;
    nod_nou->values=values;

    if(precedent== nullptr)
    {
        //inseamna ca el e primul nod
        nod_nou->urm= nullptr;
        lsikeys->head=nod_nou;
        lsikeys->tail=nod_nou;
        return;}
    else
    {   precedent= nullptr;
        KeyNode* current= lsikeys->head;
        while(current!=lsikeys->tail&& relatie(current->key,cheie))
        {
            precedent=current;
            current=current->urm;
        }

           if(current==lsikeys->head&&!relatie(current->key,cheie))
           {
               lsikeys->head=nod_nou;
               nod_nou->urm=current;
               return;
           }
           if(current==lsikeys->tail&&relatie(current->key,cheie))
           {
               current->urm=nod_nou;
               lsikeys->tail=nod_nou;
               return;
           }

//             KeyNode* insert=current;
//               nod_nou->urm=current;
//               current=nod_nou;
//               return;

        KeyNode* insert=current;
               nod_nou->urm=current;
               precedent->urm=nod_nou;

               return;

    }

}

void MDO::adaugaValoareLaFinal(ValuesLSI *lsivalues, TValoare valoare) {
    ValueNode *newVal= new ValueNode();
    newVal->value=valoare;
    newVal->urm= nullptr;
//    lsivalues->tail->urm=newVal;
    if(lsivalues->head== nullptr)
    {
        lsivalues->head=newVal;
        lsivalues->tail=newVal;
    }
    else
    {
        lsivalues->tail->urm=newVal;
        lsivalues->tail=newVal;
    }
}
void MDO::adauga(TCheie c, TValoare v) {
	KeyNode* current= lsikeys->head;
    KeyNode* precedent = nullptr;
    if(searchForKeyNode(c,current,precedent)== false)
    {
        //inseamna ca nu exista cheia in MDO
        adaugaCheieNoua(c,v,precedent);
    }
    else
    {
        adaugaValoareLaFinal(current->values,v);
    }
}

vector<TValoare> MDO::cauta(TCheie c) const {
	vector <TValoare> v;
    KeyNode* curent=lsikeys->head;
    KeyNode* prec= nullptr;
    if(searchForKeyNode(c,curent,prec))
    {
            //am ajuns la cheia dorita
            //initializam curentvaloare!
            ValueNode *current_value=curent->values->head;
            //daca nu e la sf
            while(current_value!= nullptr)
            {
                //salvam toate valoriile in vector
                v.push_back(current_value->value);
                current_value=current_value->urm;
            }
        }

	return v;
}
void MDO::deleteKeyElement(KeyNode *pr,KeyNode *current) {
    if(current!= nullptr)
    {   if(current==lsikeys->head&&current==lsikeys->tail)
        {
            KeyNode* deleted=lsikeys->head;
            lsikeys->head= nullptr;
            lsikeys->tail= nullptr;
            delete deleted->values;
            delete deleted;
            return;}
        if(current==lsikeys->head)
        {
            KeyNode* deleted=lsikeys->head;
            lsikeys->head=lsikeys->head->urm;
            delete deleted->values;
            delete deleted;
            return;
        }
        if(current==lsikeys->tail)
        {
            KeyNode* deleted=lsikeys->tail;
            lsikeys->tail=pr;
            lsikeys->tail->urm= nullptr;
            delete deleted->values;
            delete deleted;
            return;
        }


        else
        {
            KeyNode *deleted=pr->urm;
            pr->urm=pr->urm->urm;
            delete deleted->values;
            delete deleted;
        }

    }
}
bool MDO::deleteValueElement(ValuesLSI *lsivalues, TValoare value) {
    ValueNode* currentNode=lsivalues->head;
    ValueNode* precedent= nullptr;
    while(currentNode!= nullptr)
    {
        if(currentNode->value==value)
        {
            if(currentNode==lsivalues->head)
            {
                lsivalues->head=currentNode->urm;
            }

            if(currentNode==lsivalues->tail)
            {
                lsivalues->tail=precedent;
            }

            if(precedent!= nullptr)
            {
                precedent->urm=currentNode->urm;
            }
            delete currentNode;
            return true;
        }
        precedent=currentNode;
        currentNode=currentNode->urm;

    }
    return false;
}
bool MDO::sterge(TCheie c, TValoare v) {
	KeyNode* node=lsikeys->head;
    KeyNode* precedent= nullptr;
    if(searchForKeyNode(c,node,precedent)== false)
    {return false;}
    else
    {
        bool wasRemoved= deleteValueElement(node->values,v);
        if(wasRemoved)
        {
            if(node->values->head== nullptr)
            {
                //daca nu mai exista valori se merita sa stergi
                deleteKeyElement(precedent,node);

            }
            return true;

        }
    }
    return false;
}

int MDO::dim() const {
	int contor=0;
    KeyNode* curent=lsikeys->head;
    while(curent!= nullptr)
    {
        ValueNode* valueNode= curent->values->head;
        while(valueNode!= nullptr)
        {
            contor++;
            valueNode=valueNode->urm;
        }
        curent=curent->urm;
    }
	return contor;
}

bool MDO::vid() const {

	return lsikeys->head== nullptr;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}


MDO::~MDO() {
	KeyNode *node=lsikeys->head;
    while(node!= nullptr)
    {
        //ValueNode *valueNodePrec=node->values->head;
        ValueNode *valueNode=node->values->head;
        while(valueNode!= nullptr )
        {   ValueNode* current= valueNode;
           valueNode=valueNode->urm;
            delete current;

        }

        delete node->values;
        KeyNode *todelete=node;
        node=node->urm;
        delete todelete;

    }

   delete lsikeys;
}
