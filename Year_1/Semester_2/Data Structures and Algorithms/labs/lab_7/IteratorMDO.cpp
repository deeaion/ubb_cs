#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	int node=d.root;
    while(node!=null)
    {
        stack1.push(node);
        node=d.left[node];
    }
    if(!stack1.empty())
    {
        index=stack1.top();
    }
    else
    {
        node=null;
    }
}

void IteratorMDO::prim(){
	while(!stack1.empty())
        stack1.pop();
    int node=dict.root;
    while(node!=null)
    {
        stack1.push(node);
        node=dict.left[node];
    }
    if(!stack1.empty())
    {
        index=stack1.top();
    }
    else
        index=null;
}

void IteratorMDO::urmator(){
	if(!valid())
        throw std::exception();
    int node=stack1.top();
    stack1.pop();
    if(dict.right[node]!=null)
    {
        node=dict.right[node];
        while(node!=null)
            {
                this->stack1.push(node);
                node=dict.left[node];
            }
    }
}

bool IteratorMDO::valid() const{
	if(stack1.empty())
        return false;
    return dict.nodes[index]!=nullValue;
}

TElem IteratorMDO::element() const{
	if(!valid())
        throw std::exception();
	return  dict.nodes[index];
}


