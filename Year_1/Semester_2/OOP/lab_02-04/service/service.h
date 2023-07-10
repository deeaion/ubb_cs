//
// Created by Deea on 3/10/2023.
//

#ifndef LAB_2_4_SERVICE_H
#define LAB_2_4_SERVICE_H
#pragma once
#include "../repository/repository.h"
#include "../validation/validate.h"
/*
 * Adding an electronic a)
 */

int add_electronic_service(MyList *store, int id, char*type, char*producer, char*model, double price, int quantity);
/*
 * Modifying an electronic by price
 */
int modify_electronic_price_by_id(MyList* store,int id, double price);
/*
 * Modifying an electronic by quantity
 */
int modify_electronic_quantity_by_id(MyList* store,int id, int quantity);
/*
 * Deleting a product by id
 */
int delete_product_by_id(MyList* store, int id);
/*
 * preconditions: the electronic must have the quantity>0
 * returns: a list of sorted electronics by price and quantity
 *                   depending on the wayu the user chooses( ascending or descending order)
 *
 */


MyList* sort_in_stock_electronics(MyList* store, int way);

/*
 * preconditions: user must give a criteria of the filter
 * returns: a list filtered by  the criteria given
 *
 */
MyList* filter_by_criteria(MyList* store, int criteria,char name[],double price,int quantity);
void swap(MyList* list,int index1,int index2);
MyList* get_all_service(MyList* store);
#endif //LAB_2_4_SERVICE_H
