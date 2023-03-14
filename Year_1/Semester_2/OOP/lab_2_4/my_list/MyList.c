//
// Created by Deea on 3/11/2023.
//
#include "../my_list/MyList.h"
MyList* createList(int capacity)
{
    MyList* List=(MyList*)malloc(sizeof(MyList));
    List->capacity=capacity;
    List->size=0;
    List->elems=(Electronic*)malloc(capacity*sizeof(Electronic));
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

void addToList(MyList* current_list, Electronic* element_to_add)
{   //verifying if the size is equal to the capacity. If it is we need to resize the list
    if(current_list->size==current_list->capacity){
        resize(current_list);
    }
    //else we just need to add it
    current_list->elems[current_list->size]=*element_to_add;
    current_list->size+=1;
}
void resize(MyList* list)
{
    int newCapacity=list->capacity+10;
    Electronic *newElements=malloc(sizeof(Electronic)*newCapacity);
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
Electronic get(MyList* lista, int pozitie)
{
    return lista->elems[pozitie];
}
MyList* copyList(MyList* l)
{   MyList * new_list=(MyList*)malloc(sizeof(MyList));
    new_list->capacity=l->capacity;
    new_list->size=l->size;
    new_list->elems=(Electronic*)malloc(sizeof(Electronic)*new_list->capacity);
    for (int i=0; i<l->size;i++)
    {
        new_list->elems[i]= *copyElectronic(&l->elems[i]);
        }

    return new_list;
}

Electronic set(MyList*l ,int poz,Electronic e)
{
    Electronic rez=l->elems[poz];
    l->elems[poz]=e;
    return rez;
}