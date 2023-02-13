#include<stdio.h>
int citire_numere(int sir[100])
{   File *fp;
    fp=fopen("numere.txt","r");
    if(!fp)
    {printf("File was not open correctly");}
    
    
int numere_pare(int,int,int);
int numere_impare(int,int);
void print(int v[],int n)
{for(i=0;i<n;i++)
printf("%d",v[i])}
int main()
{   int sir[100],n_p[100],n_i[100];
    int n_el=0,el_p=0,el_i=0;
    n_el=citire_numere(sir);
    el_p=numere_pare(sir,n_el,n_p);
    el_i=numere_impare(sir,n_el,n_i);
    printf("Sirul de numere pare: ");
    print(n_p,el_p);
    printf("\nSirul de numere impare: ");
    print(n_i,el_i);
return 0;}
    
    
    