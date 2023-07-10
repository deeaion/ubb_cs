//
// Created by Deea on 3/19/2023.
//
#pragma once
#include <iostream>
using namespace std;

#ifndef PROB_2_OPERATII_H
#define PROB_2_OPERATII_H
int verify_input_graph(int nr_noduri, int matrice [100][100]);
void grad_zero(int nr_noduri,int matrice [100][100]);
void regular_graph(int nr_noduri,int matrice[100][100]);
void matricea_distante(int nr_noduri,int matrice[100][100]);
void conex_graph(int nr_noduri,int matrice[100][100]);
void DFS(int x,int viz[],int n,int matrice[100][100]);
int conex(int nr_noduri,int matrice[100][100]);
#endif //PROB_2_OPERATII_H
