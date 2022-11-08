#include<stdio.h>
float average(int nr_1,int nr_2)
{float average;
average=((float)nr_1+(float)nr_2)/2;
return average;}

int sum(int nr_1,int nr_2)
     {int sum;
      sum=nr_1+nr_2;
      return sum;}

int  sum_of_squares(int nr_1,int nr_2)
    {int sum_of_squares;
     sum_of_squares=nr_1*nr_1+nr_2*nr_2;
     return sum_of_squares;}
int main()
{int nr_1,nr_2;
printf("Dati primul numar\n");
scanf("%d",&nr_1);
printf("Dati al doilea numar\n");
scanf("%d",&nr_2);
printf("Suma numerelor este: %d\nMedia numerelor este: %f\nSuma patratelor numerelor este: %d\n",sum(nr_1,nr_2),average(nr_1,nr_2),sum_of_squares(nr_1,nr_2));
return 0;}
