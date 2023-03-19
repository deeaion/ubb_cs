//
// Created by Deea on 3/17/2023.
//

#ifndef INC_2_PRINTARE_H
#define INC_2_PRINTARE_H
#define INF 100000
#pragma once
#include <iostream>
using namespace std;
void printare_lista_adiacenta(int lista_adiacenta[100][100], int noduri);
void printare_matrice(int noduri,int nr_muchii,int matrice_incidenta[100][100]);
int menu();
void printare_muchii(int nr_muchii,int muchi[100][2]);
int menu_op();

#endif //INC_2_PRINTARE_H
