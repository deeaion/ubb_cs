//
// Created by Deea on 3/19/2023.
//
#include "operatii.h"
#include "printare.h"
int verify_input_graph(int nr_noduri, int matrice [100][100])
{int i,j;

    for(i=0;i<nr_noduri;i++)
            for(j=0;j<nr_noduri;j++)
            {
                if(matrice[i][j]!=0 && matrice[i][j]!=1)
                    return 0;
            }
return 1;
}
void grad_zero(int nr_noduri, int matrice[100][100]) {
    int ok_neor= verify_input_graph(nr_noduri,matrice);
    if (ok_neor==1)
    {int counter = 0;
    int i, j;
    int ok;
    for (i = 0; i < nr_noduri; i++) {
        j = 0;
        ok = 1;
        while (j < nr_noduri && ok == 1) {
            if (matrice[i][j] !=0 )
                ok = -1;
            j++;
        }
        if (ok == 1) {
            cout << "Nodul" << i + 1 << "este izolat!";
            counter++;
        }

    }
    if (counter == 0)
        cout << "There are no isolated nodes";}
    else
        cout<<"The matrix you provided is not oriented ! I can not perform the algorithm correctly for your input. Please input a neoriented graph!";

}

void regular_graph(int nr_noduri, int matrice[100][100]) {
    int ok_neor= verify_input_graph(nr_noduri,matrice);
    if(ok_neor==1)

    {int grad_anterior = 0;
    int grad = 0;
    int i, j;
    j = 0;
    int ok = 1;
    //fac pentru primul nod : cresc eficienta in while ul de jos
    while (j < nr_noduri) {
        if (matrice[0][j] !=0 )
            grad++;
        j++;
    }
    for (i = 1; i < nr_noduri && ok == 1; i++) {
        grad_anterior = grad;
        j = 0;
        grad = 0;
        if (i != 0)
            while (j < nr_noduri && grad <= grad_anterior) {
                if (matrice[i][j] !=0 )
                    grad++;
                j++;
            }
        if (grad != grad_anterior)
            ok = -1;
    }
    if (ok == -1)
        cout << "The graph is not a regular one!" << endl;
    else
        cout << "The graph is regular!" << endl;}
    else
    {
        cout<<"The matrix you provided is not oriented ! I can not perform the algorithm correctly for your input. Please input a neoriented graph!";
    }

}

void matricea_distante(int nr_noduri, int matrice_in[100][100]) {
    int matrice[100][100], i, j, k;
    for (i = 0; i < nr_noduri; i++)
        for (j = 0; j < nr_noduri; j++) {
            if (matrice_in[i][j] == 0 && i != j)
                matrice[i][j] = INF;
            else
                matrice[i][j] = matrice_in[i][j];
        }
    for (k = 0; k < nr_noduri; k++) {
        for (i = 0; i < nr_noduri; i++) {
            for (j = 0; j < nr_noduri; j++) {
                if (matrice[i][k] != INF && matrice[k][j] != INF)
                    if(  matrice[i][j] > matrice[i][k] + matrice[k][j]) {
                    matrice[i][j] = matrice[i][k] + matrice[k][j];
                }
            }
        }
    }
    printare_matrice(nr_noduri, nr_noduri, matrice);
}
void DFS(int x,int viz[],int n,int matrice[100][100])
{
    int i;
    viz[x]=1;
    for(i=0;i<n;i++)
        if(matrice[x][i]==1 && viz[i]==0)
            DFS(i,viz,n,matrice);
}
int conex(int nr_noduri,int matrice[100][100])
{
    int i;
    int viz[nr_noduri];
    for(i=0;i<nr_noduri;i++)
        viz[i]=0;
    DFS(0,viz,nr_noduri,matrice);
    for(i=0;i<nr_noduri;i++)
        if(viz[i]==0)
            return 0;
    return 1;
}
void conex_graph(int nr_noduri,int matrice[100][100])
{
    if(verify_input_graph(nr_noduri,matrice)==1)
    {
        if(conex(nr_noduri,matrice)==1)
            cout<<"The graph is conex!"<<endl;
        else
            cout<<"The graph is not conex"<<endl;
    }
    else
    {
        cout<<"The Graph is not in an undirected form!"<<endl;
    }
}