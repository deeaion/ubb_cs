#include<stdio.h>
#include<string.h>
int main()
{
int n,firstn,ultn,penn,last_two;
n=-1;
while(n<0||n>=1000)
{	printf("\nPlease enter a number with maximum 3 digits!\n");
	printf("number= ");
	scanf("%d",&n);
			}
int nr_c=0;
int nr_m=n;
     while(nr_m)
    {
        nr_m/=10;
        nr_c++;
    }
ultn=n%10;
penn=(n/10)%10;
last_two=n%100;
firstn=n/100;
char first[10],pen[10],ult[10],lastc[10];
switch (firstn)
{ case 1:
       strcpy(first,"one");
		break;
 case 2:
	strcpy(first,"two");
		break;
 case 3:
	strcpy(first,"three");
		break;
 case 4:
	strcpy(first,"four");
		break;
 case 5:
	strcpy(first,"five");
		break;
 case 6:
	strcpy(first,"six");
		break;
 case 7:
	strcpy(first,"seven");
		break;
 case 8:
	strcpy(first,"eight");
		break;
 case 9:
	strcpy(first,"nine");
		break;}
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
else
	{
	switch(penn)
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
	switch(ultn)
{
case 1:
       strcpy(ult,"one");
		break;
 case 2:
	strcpy(ult,"two");
		break;
 case 3:
	strcpy(ult,"three");
		break;
 case 4:
	strcpy(ult,"four");
		break;
 case 5:
	strcpy(ult,"five");
		break;
 case 6:
	strcpy(ult,"six");
		break;
 case 7:
	strcpy(ult,"seven");
		break;
 case 8:
	strcpy(ult,"eight");
		break;
 case 9:
	strcpy(ult,"nine");
		break;}
						}
if(n==0)
    printf("Number %d reads as:\nzero",n);

if(nr_c==1&&n!=0)
        printf("Number %d reads as:\n%s",n,ult);
if(nr_c==2)
   {if(n<13)
        printf("Number %d reads as:\n%s",n,lastc);
    if (n<20&&n>=13)
        printf("Number %d reads as:\n%steen",n,lastc);
    if(n>=20)
        printf("Number %d reads as:\n%sty-%s",n,pen,ult);
    }

if(nr_c==3)
{   if(last_two>=10 && last_two<20)
                {if(last_two>=10 && last_two<13)
                    printf("Number %d reads as:\n%s hundred and %s",n,first,lastc);
                if(last_two>=13 && last_two<20)
                    printf("Number %d reads as:\n%s hundred and %steen",n,first,lastc);}
    if(last_two>=20||last_two<10)
            {if(n%100==0)
                    printf("Number %d reads as:\n%s hundred",n,first);
            else{
            if(penn==0)
                    printf("Number %d reads as:\n%s hundred and %s",n,first,ult);
            if(n%10==0)
                    printf("Number %d reads as:\n%s hundred and %sty",n,first,pen);
            if(n%10!=0&&penn!=0)
                    printf("Number %d reads as:\n%s hundred and %sty- %s",n,first,pen,ult);} }
}
return 0;}
