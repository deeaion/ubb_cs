#include <iostream>
#include "printare.h"
#include "citiri_fisier.h"
#include "conversii.h"
#include "operatii.h"
using namespace std;
int main() {
    int nr_noduri,nr_muchii;
    int matr_adiacenta[100][100],matr_inc[100][100],muchi[100][2];
    int l_ad[100][100];
    int opt=-1;
    while (opt!=0)
    {
            opt=menu();

        if(opt==1)
        {
            matrice_adiacenta(matr_adiacenta,nr_noduri);

           cout<<"Adjaency Matrix, this is your matrix: "<<endl;
            printare_matrice(nr_noduri,nr_noduri,matr_adiacenta);

       }
        else if (opt==2)
        {
            lista_adiacenta(l_ad,nr_noduri);
            cout<<"Adjaency List, this is your list:"<<endl;
            printare_lista_adiacenta(l_ad,nr_noduri);
            lis_ad_to_mat_ad(nr_noduri,l_ad,matr_adiacenta);

        }
        else if (opt==3)
        {
            matrice_incidenta(matr_inc,nr_muchii,nr_noduri);
            cout<<"Incidence Matrix, this is your matrix"<<endl;
            printare_matrice(nr_noduri,nr_muchii,matr_inc);
            inc_to_mat_ad(nr_noduri,nr_muchii,matr_inc,matr_adiacenta);
        }
        else if (opt==4)
        {
            muchii(muchi,nr_noduri,nr_muchii);
            cout<<"The list of muchii is :"<<endl;
            printare_muchii(nr_muchii,muchi);
            matrice_de_adiacenta(nr_noduri,muchi,nr_muchii,matr_adiacenta);

        }
        else if (opt==5)
        {
            int optiune_2=menu_op();
            if (optiune_2==1)
            {
                grad_zero(nr_noduri,matr_adiacenta);
            }
            if(optiune_2==2)
            {
                regular_graph(nr_noduri,matr_adiacenta);
            }
            if(optiune_2==3)
            {
                matricea_distante(nr_noduri,matr_adiacenta);
            }
            if(optiune_2==4)
            {
                conex_graph(nr_noduri,matr_adiacenta);
            }

        }

   }
        return 0;

}
