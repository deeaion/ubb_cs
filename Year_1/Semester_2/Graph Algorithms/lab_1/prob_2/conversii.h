//
// Created by Deea on 3/17/2023.
//
#pragma once
#ifndef INC_2_CONVERSII_H
#define INC_2_CONVERSII_H
//din citirea ca muchii putem astfel salva oricum e mai usor graful

int determinare_vecini_si_numar(int nodul,int muchii [][2],int nr_muchii,int v[]);
void matrice_de_adiacenta(int noduri,int muchii[][2],int numar_muchii,int matrice_adiacenta[1000][100]);
void matrice_de_incidenta(int noduri,int nr_muchii, int muchii[][2], int matrice_incidenta[100][100]);
void lista_de_adiacenta(int noduri,int muchii[][2],int numar_muchii,int lista_adiacenta[100][100]);
void lis_ad_to_mat_ad(int noduri,int lista[][100],int matr_ad[][100]);
void inc_to_mat_ad(int noduri,int muchii,int ma_inc[][100],int matr_ad[][100]);
#endif //INC_2_CONVERSII_H
