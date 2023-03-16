//
// Created by Deea on 3/10/2023.
//

#ifndef LAB_2_4_UI_H
#define LAB_2_4_UI_H
#include "../service/service.h"
/*
 * prints out the meno for the user
 */
void ui_print_menu();
/*
 * Used to run console
 */
void runConsole(MyList* store);
/*
 * Add a new product. If product already exists only update the quantity of it.
 *
 */
void ui_add_electronic(MyList* store);
/*
 * Modify product by the choice of user.
 */
void ui_modify_electronic(MyList* store);

/*
 * Delete electronics by id
 */
void ui_delete_electronic(MyList* store);

/*
 * Print sorted products by price and if they are equal by quantity
 *
 */
void ui_sort_by_price_and_quantity(MyList* store);
/*
 * List filtered by a criteria
 */
void ui_filter_by_criterea(MyList* store);
/*
 * to print out the items of a list
 */
void print_all(MyList* store);
#endif //LAB_2_4_UI_H
