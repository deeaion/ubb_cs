//
// Created by Deea on 3/17/2023.
//

#include "printare.h"



void printare_lista_adiacenta(int lista_adiacenta[100][100], int noduri) {
    int i, j;
    int nr_vecini;
    for (i = 0; i < noduri; i++) {
        nr_vecini = lista_adiacenta[i][1];
        cout << lista_adiacenta[i][0] << ": ";
        for (j = 2; j < nr_vecini + 2; j++) {
            cout << lista_adiacenta[i][j] << ", ";

        }
        cout << endl;
    }
}

void printare_matrice(int noduri, int nr_muchii, int matrice_incidenta[100][100]) {
    int i;//liniile
    int j;//coloanele
    for (i = 0; i < noduri; i++) {
        for (j = 0; j < nr_muchii; j++) {
            if (matrice_incidenta[i][j] >= INF)
                cout << "inf"<<" ";
            else
                cout << matrice_incidenta[i][j] << " ";
        }
        cout << endl;
    }
}

void printare_muchii(int nr_muchii, int muchi[100][2]) {
    cout << "Muchiile introduse" << endl;
    for (int j = 0; j < nr_muchii; j++)
        cout << muchi[j][0] << " " << muchi[j][1] << endl;
    cout << endl;
}

int menu_op() {
    int optiune;
    cout << "Please choose what result you want:" << endl;
    cout
            << "\t1.Determine izolated nodes from the graph.\n\t2.Determine if the graph is regular\n\t3.Distance matrix\n\t4.Is the graph conex?"
            << endl;
    cin >> optiune;
    return optiune;

}

int menu() {
    cout << "Please enter your option\n";
    cout << "\tWhat type of graph input will you use:\n"
         << "\t\t1. Adjacency Matrix\n\t\t2.Adjaceny List\n\t\t3.Incidence Matrix\n\t\t4.List of muchii\n\t\t5.Operations on your matrix\n\t\t0.End"
         << endl;
    cout << "Please enter the corresponding number:";
    int nr;
    cin >> nr;

    cout << endl;
    return nr;
}