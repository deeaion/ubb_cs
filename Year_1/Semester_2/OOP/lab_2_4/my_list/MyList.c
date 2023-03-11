//
// Created by Deea on 3/11/2023.
//
#include "../my_list/MyList.h"
MyList* createList(int capacity)
{
    MyList* List=(MyList*)malloc(sizeof(MyList));
    List->capacity=capacity;
    List->size=0;
    List->elems=(ElemType*)malloc(capacity*sizeof(ElemType));
    return List;
}
void destroy(MyList* l)
{// daca lista este deja goala nu are rost sa dealoci=> dangling pointer
    if(l==NULL)
        return;
    for(int i=0;i<l->size;i++)
    {
        destroyElectronic(&l->elems[i]);
    }
    free(l->elems);
    free(l);
}

void addToList(MyList* current_list, ElemType element_to_add)
{   //verifying if the size is equal to the capacity. If it is we need to resize the list
    if(current_list->size==current_list->size++){
        resize(current_list);
    }
    //else we just need to add it
    current_list->elems[current_list->size]=element_to_add;
    current_list->size++;
}
void resize(MyList* list)
{
    int newCapacity=list->capacity+10;
    ElemType *newElements=malloc(sizeof(ElemType)*newCapacity);
    for(int i=0;i<list->size;i++)
    {
        newElements[i]=list->elems[i];
    }
    //dealocate new vector
    free(list->elems);
    list->elems=newElements;
    list->capacity=newCapacity;
}
int size(MyList* l)
{
    return l->size;
}