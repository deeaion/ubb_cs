//
// Created by Deea on 3/17/2023.
//
#include "conversii.h"

int determinare_vecini_si_numar(int nodul,int muchii [][2],int nr_muchii,int v[])
{
    int i;
    int nr_vecini=0;
    for (i=0;i<nr_muchii;i++)
    {
        if(muchii[i][0]==nodul)
        {
            v[nr_vecini]=muchii[i][1];
            nr_vecini++;
        }
        if(muchii[i][1]==nodul)
        {
            v[nr_vecini]=muchii[i][0];
            nr_vecini++;
        }
    }
    return nr_vecini;

}

void lis_ad_to_mat_ad(int noduri,int lista[][100],int matr_ad[][100])
{int i,j,vecin;
    for(i=0;i<noduri;i++)
    {
        for(j=2;j<lista[i][1]+2;j++)
        {   vecin=lista[i][j];
            matr_ad[i][vecin-1]=1;
        }
    }
}

void inc_to_mat_ad(int noduri,int muchii,int ma_inc[][100],int matr_ad[][100])
{
    int i,j,k,ok;
    for(i=0;i<noduri;i++)
    {
        for(j=0;j<muchii;j++)
        {
            if (ma_inc[i][j]==1)
            {
                k=0;
                ok=0;
                while(ok==0)
                {
                    if (ma_inc[k][j]==1&&k!=i)
                    {
                        ok=1;
                        matr_ad[i][k]=1;
                    }
                    k++;
                }
            }
        }
    }
}

void matrice_de_adiacenta(int noduri,int muchii[][2],int numar_muchii,int matrice_adiacenta[][100])
{
    int nod, nod_vecin;
    int i;
    for (i=0;i<noduri;i++)
        for (int j=0;j<noduri;j++)
        {
            matrice_adiacenta[i][j]=0;
        }
    for (i=0;i<numar_muchii;i++)
    {
        nod=muchii[i][0]-1;//nod
        nod_vecin=muchii[i][1]-1;
        matrice_adiacenta[nod][nod_vecin]=1;
        matrice_adiacenta[nod_vecin][nod]=1;
    }
}

void matrice_de_incidenta(int noduri,int nr_muchii, int muchii[][2], int matrice_incidenta[100][4950])
{
    int i;//liniile
    int j;//coloanele
    int nod;
    for(j=0;j<nr_muchii;j++) {
        int start=muchii[j][0]-1;
        int end=muchii[j][1]-1;
        matrice_incidenta[start][j]=1;
        matrice_incidenta[end][j]=1;
    }
}

void lista_de_adiacenta(int noduri,int muchii[][2],int numar_muchii,int lista_adiacenta[100][100])
{
    int i,j;
    for(i=0;i<noduri;i++) {
        lista_adiacenta[i][1] = i+1;//aici este numele nodului
        int v[100];
        int nr_vecini;
        nr_vecini=determinare_vecini_si_numar(i+1, muchii, numar_muchii,v);//i-nodul curent, muchii este matricea de muchii
        lista_adiacenta[i][0]=nr_vecini;
        for(j=2;j<nr_vecini+2;j++)
        {
            lista_adiacenta[i][j]=v[j-2];
        }

    }
}