#include<stdio.h>
int dimensiune(char);
void litere_mari(char *,int,char *);
void litere_mici(char *,int,char *);
void citire(char *);
int main()
{int opt,n=0,w=0,words[100][50] ;
    opt=0;
    char s[100],m[100],M[100];
    printf("If you want to enter a string without any blankspaces enter 1!\n");
    printf("If you want to enter a string with blankspaces enter 2!\n");
    scanf("%d",&opt);
    if (opt==2)
    {   printf("You have entered option 2. Please enter how many words the string has.");
        citire(&s);
    }
        
    if (opt==1)
    {   printf("You have entered option 1. Please enter the string.");
        
        scanf("%s",&s);
        }
    if (opt!=1 && opt!=2)
        return;
    n=dimensiune(s);
    litere_mari(&s,n,&M);
    litere_mici(&s,n,&m);
    printf("%s\n",m);
    printf("%s\n",M);
return 0;}
    
    
    
    
    
    