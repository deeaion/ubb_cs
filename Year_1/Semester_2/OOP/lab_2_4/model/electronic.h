//
// Created by Deea on 3/10/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#pragma once
#ifndef LAB_2_4_ELECTRONIC_H
#define LAB_2_4_ELECTRONIC_H
typedef struct{
    int id;//identificator unic
    char* type;//tipul produsului
    char* producer;//producatorul
    char* model;//modelul produsului
    float price;//pretul produsului
    int quantity;//cantitatea produsului
}Electronic;
/*
 * Create a new electronic product.
 * returns: an object of the type Electronic
 */
Electronic* createElectronic(int id,char* type,char* producer, char* model,float price,int quantity);
/*
 * Dealocate memory occupied by product
 */
void destroyElectronic(Electronic *e);

/*
 * Create a copy for the electronic product
 * Deep copy- copy all the sub-parts
 */
Electronic* copyElectronic(Electronic* e);

/*
 * Validate electronic product
 * It will be valid if:
 *                      -price>0.00
 *                      -id>0
 *                      -type-strlen(type)>0
 *                      -producer-strlen(producer)>0
 *                      -model- strlen(model)>0
 *                      -quantity<0
 */
/*
 * GETTERS!
 */
/*
 * returns: id of the object Electronic
 */
int get_id_electronic(Electronic *e);
/*
 * returns: producer of the object Electronic
 */
char* get_producer_electronic(Electronic *e);
/*
 * returns: char*- model of the object Electronic
 */
char* get_model_electronic(Electronic *e);
/*
 * returns: float- price of the object Electronic
 */
float get_price_electronic(Electronic *e);
/*
 * returns: quantity of the object Electronic
 */
int get_quantity_electronic(Electronic *e);

/*
 * printing format
 */
void toString(Electronic* print_e,char stringToConcatenate[]);
#endif //LAB_2_4_ELECTRONIC_H
