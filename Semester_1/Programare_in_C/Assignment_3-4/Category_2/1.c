/*Using dynamic memory allocation where is the case,
 solve one of the following:
1. Multiply 2 matrices of integers.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    //declaram pointerii pentru matrice
    int **ptr1,**ptr2,**ptrf;
    //cerem nr randuri si coloane
    int row1,row2,col1,col2;
    //indexes
    int i,j,k;
    //prima matrice
    printf("\nFirst matrix:");
    printf("\nRow:");
    scanf("%d",&row1);
    printf("\nColumn:");
    scanf("%d",&col1);
    printf("\nSecond matrix:");
    printf("\nRow:");
    scanf("%d",&row2);
    printf("\nColumn:");
    scanf("%d",&col2);
    if(col1!=row2)
    {
        printf("\nYou can't multiply two matrices.");
        return 0;
    }
    int rowf,colf;
    rowf=row1;
    colf=col1;
    //alocare de memorie pentru:matrice 1,matrice 2, si rezultat
    //Matrice 1
    ptr1=(int **)malloc(sizeof(int *)*row1);
    for (i=0;i<row1;i++)
        ptr1[i]=(int *)malloc(sizeof(int)*col1);
    //Matrice 2
    ptr2=(int **)malloc(sizeof(int *)*row2);
    for (i=0;i<row2;i++)
        ptr2[i]=(int *)malloc(sizeof(int)*col2);
    //Matrice 3
    ptrf=(int **)malloc(sizeof(int *)*rowf);
    for (i=0;i<rowf;i++)
        ptrf[i]=(int *)malloc(sizeof(int)*colf);
    //prima matrice
    printf("Matrix 1\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
            {printf("\tA[%d][%d]=",i,j);
                scanf("%d",&ptr1[i][j]);
            }
         }
    printf("\nMatrix 2\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
            {printf("\tA[%d][%d]=",i,j);
                scanf("%d",&ptr2[i][j]);
            }
         }
    //Calcul matrice inmultire
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            ptrf[i][j]=0;
            for(k=0;k<col1;k++)
                ptrf[i][j]=ptrf[i][j]+ptr1[i][k]*ptr2[k][j];
        }
    }
    printf("\n Matrice rezultata:\n");
    for(i=0;i<rowf;i++)
    {printf("\n\t\t");
        for(j=0;j<colf;j++)
        {
            printf("%d ",ptrf[i][j]);
        }


    }


return 0;


}


