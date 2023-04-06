#include <iostream>
#include <fstream>
#define INF 10000

using namespace std;
void citire_muchii(int muchii[][2], int &nr_noduri, int &nr_muchii) {
    ifstream file("../graf.txt");
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
void printare_muchii(int nr_muchii, int muchi[100][2]) {
    cout << "Muchiile introduse" << endl;
    for (int j = 0; j < nr_muchii; j++)
        cout << muchi[j][0] << " " << muchi[j][1] << endl;
    cout << endl;
}
void menu(int &opt)
{
    cout<<"\n\t1->Show Matrix.\n\t0->Exit\n";
    cin>>opt;
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

void matricea_distante(int nr_noduri, int matrice_in[100][100]) {
    int matrice[100][100], i, j, k;
    for (i = 0; i < nr_noduri; i++)
        for (j = 0; j < nr_noduri; j++) {
            matrice[i][j]=matrice_in[i][j];
        }

        for (i = 0; i < nr_noduri; i++) {
            for (j = 0; j < nr_noduri; j++){
                for (k = 0; k < nr_noduri; k++){
                {
                    matrice[i][j]=matrice[i][j]||(matrice[i][k]&&matrice[k][j]);
                    }
            }
        }}
    printare_matrice(nr_noduri, nr_noduri, matrice);
}

int main() {
    int nr_noduri,nr_muchii;
    int muchii[100][2];
    int opt=-1;
    citire_muchii(muchii,nr_noduri,nr_muchii);
    printare_muchii(nr_muchii,muchii);
    while(true)
    {
        opt=-1;
        menu(opt);
        if(opt==1)
        {
//            int node;
//            cout<<"Introduce node: ";
//            cin>>node;
            cout<<endl;
            int matrice_ad[100][100];
            matrice_de_adiacenta(nr_noduri,muchii,nr_muchii,matrice_ad);
            printare_matrice(nr_noduri,nr_noduri,matrice_ad);
            cout<<endl;
            matricea_distante(nr_noduri,matrice_ad);

        }
        if (opt==0)
            return 0;
    }

    return 0;
}
