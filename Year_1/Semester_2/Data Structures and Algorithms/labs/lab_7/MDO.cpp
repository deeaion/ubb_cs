#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

void MDO::resize() {
    int newCapacity=capacity*2;
    TElem *aux=new TElem[newCapacity];
    int *auxSt=new int[newCapacity];
    int *auxDr=new int[newCapacity];
    for(int i=0;i<capacity;i++)
    {
        aux[i]=nodes[i];
        auxSt[i]=left[i];
        auxDr[i]=right[i];
    }
    for(int i=capacity;i<newCapacity;i++)
    {
        aux[i]=nullValue;
        auxSt[i]=null;
        auxDr[i]=null;
    }
    newFirstEmpty();
    capacity=newCapacity;
    delete[]nodes;
    delete[]left;
    delete[]right;
    nodes=aux;
    left=auxSt;
    right=auxDr;
}

void MDO::newFirstEmpty() {
    while(nodes[firstEmpty]!=nullValue)
    {
        firstEmpty++;
    }
}

MDO::MDO(Relatie r) {
	this->r=r;
    capacity=cap;
    size=0;
    root=0;
    firstEmpty=0;
    nodes=new TElem [capacity];
    left=new int[capacity];
    right=new int[capacity];
    for(int i=0;i<cap;i++)
    {
        nodes[i]=nullValue;
        left[i]=null;
        right[i]=null;
    }
}

int MDO::adauga_rec(int node, TElem e) {
    if(node==null)
    {
        nodes[firstEmpty]=e;
        int old=firstEmpty;
        newFirstEmpty();
        return old;
    }
    if(!r(nodes[node].first,e.first))
    {
        left[node]= adauga_rec(left[node],e);

        return node;

    }
    else
    {
        right[node]= adauga_rec(right[node],e);
        return node;
    }
}

int MDO::remove_rec(int node, TElem e, bool &found) {
    //cout<<"IN REMOVE:\n";
    //cout<<"---"<<nodes[node].first<<" "<<nodes[node].second<<"---\n";
    if(node==null)
    {
        return node;
    }
    if(nodes[node].first==e.first&&nodes[node].second==e.second)
    {
        found= true;
        if(left[node]==null&&right[node]==null)
        {
            return null;
        }
        if(left[node]==null)
        {   //cout<<"r"<<nodes[right[node]].first<<" "<<nodes[right[node]].second<<"l\n";
            return right[node];}

        if(right[node]==null)
        { //cout<<"l"<<nodes[left[node]].first<<" "<<nodes[left[node]].second<<"l\n";
            return left[node];}
        else
        {
            //cout<<"r"<<nodes[right[node]].first<<" "<<nodes[right[node]].second<<"l\n";
            //cout<<"l"<<nodes[left[node]].first<<" "<<nodes[left[node]].second<<"l\n";
            int min = minimum(right[node]);
            //cout<<nodes[min].first<<nodes[min].second;
            nodes[node]= nodes[min];
            right[node]= remove_rec(right[node], nodes[min], found);
            return node;
        }


    }
    if(!r(nodes[node].first,e.first))
    {
        left[node]= remove_rec(left[node],e,found);
        return node;
    }
    else
    {
        right[node]= remove_rec(right[node],e,found);
        return node;
    }
}
bool MDO::sterge(TCheie c, TValoare v) {
    bool found=false;
    int newRad=remove_rec(root,{c,v},found);
    if(!found)
        return false;
    root=newRad;
    size--;
    return true;
}
int MDO::minimum(int node) {
    int curent=node;
    while(left[curent]!=null)
    {
        curent=left[curent];
    }
    return curent;
}
void MDO::adauga(TCheie c, TValoare v) {
	//daca e chiar primul nod
    if(vid())
    {
        nodes[0]={c,v};
        firstEmpty=1;
        size++;
        return;
    }
    //altfel tre sa il insrez tehnic
    //verific capacitatea firstly
    if(size==capacity-1)
        resize();
    adauga_rec(root,{c,v});
    size++;
}

vector<TValoare> MDO::cauta(TCheie c) const {
	vector<TValoare > valori;
    int current=root;
    while (current!=null)
    {
        if(r(nodes[current].first,c))
        {
            if(c==nodes[current].first)
            {
                valori.push_back(nodes[current].second);
                //continui pe ramura dr


            }
            current=right[current];
        }
        else
        {
            current=left[current];
        }
    }
	return valori;
}




//facute
int MDO::dim() const {
    return size;
}

bool MDO::vid() const {
    return size==0;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	delete []nodes;
    delete[]left;
    delete[]right;
}
