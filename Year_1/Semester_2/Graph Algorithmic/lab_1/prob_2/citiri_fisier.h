//
// Created by Deea on 3/18/2023.
//
#pragma once
#ifndef INC_2_CITIRI_FISIER_H
#define INC_2_CITIRI_FISIER_H
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void matrice_incidenta(int matrice[100][100], int &nr_muchii, int &nr_noduri);
void matrice_adiacenta(int matrice[100][100], int &nr_noduri);
void muchii(int muchii[][2], int &nr_noduri, int &nr_muchii);
void lista_adiacenta(int matrice[100][100],int &nr_noduri);
#endif //INC_2_CITIRI_FISIER_H
