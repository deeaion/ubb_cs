//
// Created by Deea on 3/17/2023.
//

#include "citiri_fisier.h"
#define INF  100000
#define citire_matr "../matrice_adiacenta.txt"
void matrice_incidenta(int matrice[100][100], int &nr_muchii, int &nr_noduri) {
    ifstream file("../matrice_incidenta.txt");
    file >> nr_noduri;
    file >> nr_muchii;
    int j, i;
    for (i = 0; i < nr_noduri; i++)
        for (j = 0; j < nr_muchii; j++)
            file >> matrice[i][j];
    file.close();


}

void matrice_adiacenta(int matrice[100][100], int &nr_noduri) {
    ifstream file(citire_matr);
    file >> nr_noduri;
    int i, j;
    char value[5];
    for (i = 0; i < nr_noduri; i++)
        for (j = 0; j < nr_noduri; j++)
        {file >>value;
            if(strcmp(value,"inf")==0)
            {matrice[i][j]=INF;}
            else
    {matrice[i][j]=strtol(value,NULL,10);}}
    file.close();
}

void muchii(int muchii[][2], int &nr_noduri, int &nr_muchii) {
    ifstream file("../muchii.txt");
    file >> nr_noduri;
    int i = 0;
    int nod, nod_vecin;// pentru salvarea muchiilor
    while (file >> nod >> nod_vecin) {
        muchii[i][0] = nod;
        muchii[i][1] = nod_vecin;
        i++;
    }
    nr_muchii = i;
}
void lista_adiacenta(int matrice[100][100],int &nr_noduri)
{
    FILE* file=fopen("../lista_adiacenta.txt","r");
    int i=0;
    int nod;
    int vecin;
    char nod_linie[100];
    char nod_s[100];
    char vecini[100];
    fgets(nod_linie,100,file);
    nr_noduri=strtol(nod_linie,NULL,10);

    while(fgets(nod_linie,100,file)!=NULL)
    {if(strcmp(nod_linie,"")!=0)
        {nod=-1;
        i=0;
        char* p;
        p=strtok(nod_linie,"-,");
        int j=2;
        while(p)
        {   if(nod==-1)
            {
            nod=strtol(p,NULL,10);
            p= strtok(NULL,"-,");
            }
            else
            {vecin=strtol(p,NULL,10);
            matrice[nod-1][j]=vecin;
            i++;
            j++;
            p= strtok(NULL,"-,");}
        }
        matrice[nod-1][1]=i;
        matrice[nod-1][0]=nod;
    }
    }
    fclose(file);
}
