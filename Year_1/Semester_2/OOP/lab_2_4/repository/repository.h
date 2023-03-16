//
// Created by Deea on 3/10/2023.
//

#ifndef LAB_2_4_REPOSITORY_H
#define LAB_2_4_REPOSITORY_H
#pragma once
#include "../model/electronic.h"
#include "../my_list/MyList.h"



/*
 * to destroy the store
 */

/*
 * Adding an electronic to the store
 */
int addElectronic(MyList* store,Electronic* electronic,int position);
/*
 * Used for deleting a certain electronic by id!
 * returns: MyList'
 */
int deleteElectronic(int id,MyList * electronic_store);
/*
 * returns: the position of the item in the list
 */
int searchElectronic(int id, MyList * electronic_store);
/*
 * modifies the element of the respective id!
 */
int modifyElectronic(int id, Electronic* modified_electronic, MyList* store);
MyList * get_all_electronics(MyList *electronic_store);
#endif //LAB_2_4_REPOSITORY_H
