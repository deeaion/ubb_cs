//
// Created by Deea on 3/10/2023.
//
#include <stdlib.h>
#ifndef LAB_2_4_MYLIST_H
#define LAB_2_4_MYLIST_H
#pragma once
#include "../model/electronic.h"
typedef void* GenericElement;
typedef struct
{
    GenericElement* elems;
    int size;//lungimea listei
    int capacity;//capacity
} MyList;


/*
 * Create an empty list
 */

MyList* createList(int capacity);

/*
 * Destroy list
 */
int destroy(MyList* l);
/*
 *adding element to my list
 */
void addToList(MyList* current_list, GenericElement element_to_add);
/*
 * if we want to add and we have already used all of the capacity of the list we will resize it!
 * returns: MyList' <- with a new capacity and size
 */
void resize(MyList* list);

/*
 * return: number of elements in the list
 */
int size(MyList* l);
/*
 * Make a shallow copy of the list
 * return: My list containing the same elements as l
 */
MyList* copyList(MyList* l);
#endif //LAB_2_4_MYLIST_H
