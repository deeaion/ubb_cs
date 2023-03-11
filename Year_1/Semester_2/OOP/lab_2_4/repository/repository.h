//
// Created by Deea on 3/10/2023.
//

#ifndef LAB_2_4_REPOSITORY_H
#define LAB_2_4_REPOSITORY_H
#pragma once
#include "../model/electronic.h"
#include "../my_list/MyList.h"

typedef struct
{
    Electronic * electronics;
    int size, capacity;
}ElectronicsStore;

ElectronicsStore * create_electronics_store();

/*
 * to destroy the store
 */
void destroyStore(ElectronicsStore* store);
/*
 * Adding an electronic to the store
 */
int addElectronic(ElectronicsStore* store,int id, char* type, char* producer, char* model,float price,int quantity);
/*
 * Used for deleting a certain electronic by id!
 * returns: MyList'
 */
int deleteElectronic(int id,MyList *electronic_store);
/*
 * returns: the position of the item in the list
 */
int searchElectronic(int id, MyList* electronic_store);
/*
 * modifies the element of the respective id!
 */
int modifyElectronic(int id, Electronic* modified_electronic);
MyList get_all_electronis(ElectronicsStore* store, MyList *electronic_store);
#endif //LAB_2_4_REPOSITORY_H
