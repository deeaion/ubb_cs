#include<stdio.h>
int main()
{float cm,inches;
int feet;
printf("Introduceti cati cm doriti sa convertiti:\n");
scanf("%f",&cm);
inches=cm/2.54;
if(inches==1)
printf("%f cm sunt 1 inch",cm);
else
printf("%f cm sunt %0.1f inches",cm,inches);
feet=inches/12;
if(feet==1)
printf(", %f cm sunt 1 foot\n",cm);
else
printf(", %f cm sunt %d feet\n",cm,feet);
return 0;}
