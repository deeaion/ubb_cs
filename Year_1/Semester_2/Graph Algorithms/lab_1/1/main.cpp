#include <iostream>
using namespace std;

#include <fstream>
ifstream f("C:\\Users\\Deea\\Desktop\\DOCUMENTS\\UNI\\First year\\Semester 2\\Graphs Algorithmic\\lab_1\\1\\date.txt");

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
void printare_matrice_de_incidenta(int noduri,int nr_muchii,int matrice_incidenta[100][4950])
{
    int i;//liniile
    int j;//coloanele
    for (i=0;i<noduri;i++)
    {
        for(j=0;j<nr_muchii;j++)
        {
            cout<<matrice_incidenta[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
 * transforma in matrice de adiacenta rezultatul
 */
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

void printare_lista_adiacenta(int lista_adiacenta[100][100], int noduri)
{
    int i,j;
    int nr_vecini;
    for (i=0;i<noduri;i++)
    {
        nr_vecini=lista_adiacenta[i][0];
        cout<<i+1<<": ";
        for (j=2;j<nr_vecini+2;j++)
        {
            cout<<lista_adiacenta[i][j]<<", ";

        }
        cout<<endl;
    }
}
int main() {
    int numar_noduri;
    f>>numar_noduri;
    int nr_muchii;
    int max_muchii;
    max_muchii=(numar_noduri*(numar_noduri-1))/2;
    int muchii[max_muchii][2];
    int nod, nod_vecin;// pentru salvarea muchiilor
    int i=0;
    while(f>>nod>>nod_vecin)
    {muchii[i][0]=nod;
        muchii[i][1]=nod_vecin;
    i++;}
    int numar_muchii;
    numar_muchii=i;
    cout<<"Muchiile introduse"<<endl;
    for (int j=0;j<i;j++)
        cout<<muchii[j][0]<<" "<<muchii[j][1]<<endl;
    cout<<endl;
    // am salvat si muchiile
    //acum putem apela functiile pentru a face matricele


    int matrice_adiacenta[100][100];
    int j;
    matrice_de_adiacenta(numar_noduri,muchii,numar_muchii,matrice_adiacenta);
    for (i=0;i<numar_noduri;i++)
    {for(j=0;j<numar_noduri;j++)
            cout<<matrice_adiacenta[i][j]<<" ";
        cout<<endl;}
    int lista_adiacenta [100][100];
    cout<<endl;
    lista_de_adiacenta(numar_noduri,muchii, numar_muchii,lista_adiacenta);
    printare_lista_adiacenta(lista_adiacenta,numar_noduri);

    int matrice_incidenta[100][4950];

    matrice_de_incidenta(numar_noduri,numar_muchii, muchii, matrice_incidenta);
    cout<<endl;
    printare_matrice_de_incidenta(numar_noduri,numar_muchii,matrice_incidenta);
    return 0;
}