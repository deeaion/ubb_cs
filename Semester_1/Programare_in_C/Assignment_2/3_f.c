#include<stdio.h>
#include<string.h>




char first_last(int c,char number[])
{switch (c)
{ case 1:
       strcpy(number,"one"); 
		break;
 case 2:
	strcpy(number,"two");
		break;
 case 3:
	strcpy(number,"three");
		break;
 case 4:
	strcpy(number,"four");
		break;
 case 5:
	strcpy(number,"five");
		break;
 case 6:
	strcpy(number,"six");
		break;
 case 7:
	strcpy(number,"seven");
		break;
 case 8:
	strcpy(number,"eight");
		break;
 case 9:
	strcpy(number,"nine");
		break;}
                         }


char special(int last_two,char lastc[])
{
if(last_two==10)
	strcpy(lastc,"ten");
else if(last_two==11)
	strcpy(lastc,"eleven");
else if(last_two==12)
	strcpy(lastc,"twelve");
else if(13<=last_two&&last_two<=19)
	switch(last_two)
		{ 
		case 13:
        		strcpy(lastc,"thir");
                	break;
 		case 14:
        		strcpy(lastc,"four");
                		break;
 		case 15:
        		strcpy(lastc,"fifth");
                		break;
 		case 16:
        		strcpy(lastc,"six");
        		        break;
 		case 17:
        		strcpy(lastc,"seven");
                		break;
 		case 18:
        		strcpy(lastc,"eigh");
                		break;
 		case 19:
        		strcpy(lastc,"nine");
               		        break;}
                                               }



char zec(int zec, char pen[])
{
switch(zec)
		{
 case 0:
	strcpy(pen,"");
			break;
 case 2:
        strcpy(pen,"twen");
                break;
 case 3:
        strcpy(pen,"thir");
                break;
 case 4:
        strcpy(pen,"four");
                break;
 case 5:
        strcpy(pen,"fif");
                break;
 case 6:
        strcpy(pen,"six");
                break;
 case 7:
        strcpy(pen,"seven");
                break;
 case 8:
        strcpy(pen,"eigh");
                break;
 case 9:
        strcpy(pen,"nine");
                break;		}
}


int enter_number()
{
int n;
n=0;
while(n<=0||(n>=0&&n<=99)||n>=1000)
{	printf("\nPlease enter a 3 digit number!\n");
	printf("number= ");
	scanf("%d",&n);
			}
return n;}


int main()
{
int n,firstn,ultn,penn,last_two;
char first[10],pen[10],ult[10],lastc[10];


n=enter_number();

firstn=n/100;
first_last(firstn,first);


last_two=n%100;
special(last_two,lastc);

penn=(n/10)%10;
zec(penn,pen);


ultn=n%10;
first_last(ultn,ult);



if(last_two>=10 && last_two<20)
	{if(last_two>=10 && last_two<13)
		printf("Number %d reads as:\n %s hundred and %s",n,first,lastc);
	if(last_two>=13 && last_two<20)
		printf("Number %d reads as:\n %s hundred and %steen",n,first,lastc);}
if(last_two>=20||last_two<10)
      {if(penn==0)
	printf("Number %d reads as:\n %s hundred and %s",n,first,ult);
      else
       printf("Number %d reads as:\n %s hundred %sty- %s",n,first,pen,ult); }

return 0;}