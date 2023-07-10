//Scrieti un program C care primeste doua numere, N si M, ca argumente la linia de comanda.
// Programul creeaza N thread-uri "generator" care genereaza litere mici ale alfabetului aleator si le adauga unui
// sir de caractere cu 128 de pozitii. Programul mai creeaza un thread "printer" care asteapta ca toate pozitiile sirului
// de caractere sa fie ocupate, moment in care afiseaza sirul si apoi seteaza toate pozitiile sirului la NULL. Cele N thread-uri
// "generator" vor genera M astfel de string-uri iar thread-ul "printer" va afisa fiecare string imediat ce ajunge la lungimea 128.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
int N=0;//generatori
char buffer[129];
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cg=PTHREAD_COND_INITIALIZER;//asta trezeste gen
pthread_cond_t cp=PTHREAD_COND_INITIALIZER;//trezeste printerul cand pos=size.
int pos=0;
int string_count;
int M=0;//nr siruri
void* generator(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mtx);
        if(string_count==0)
            break;
        while(pos==128)
        {
            pthread_cond_signal(&cp);
            pthread_cond_wait(&cg,&mtx);
        }
        char c='a'+rand()%('z'-'a'+1);
        buffer[pos]=c;
        pos++;
        pthread_cond_broadcast(&cg);
        pthread_mutex_unlock(&mtx);
    }
    pthread_mutex_unlock(&mtx);
    return NULL;
}

void* print(void* arg)
{
    while(1)
    {   pthread_mutex_lock(&mtx);
        if(string_count==0)
            break;

        while(pos!=128)
        {
            pthread_cond_signal(&cg);
            pthread_cond_wait(&cp,&mtx);
        }
        //inseamna ca gata am umplut buffer
        printf("%s\n",buffer);
        printf("GATA? WTF\n");
        memset(buffer,0,128);
        string_count--;
        pos=0;
        pthread_cond_broadcast(&cg);
        pthread_mutex_unlock(&mtx);

    }
    pthread_mutex_unlock(&mtx);

    return NULL;
}

int main(int argc,char** argv)
{
    if(argc<3)
    {
        exit(1);
    }
    N=atoi(argv[1]);
    M=atoi(argv[2]);
    string_count=M;
    srand(time(0));
    pthread_t gid[N+1];
   // pthread_t pid;//pentru printeri
    int i;
    //join la gid
    for(i=0;i<N;i++)
    {
      //  int* arg=(int* )malloc(sizeof(int));
        //*arg=i;
        pthread_create(&gid[i],NULL,generator,NULL);
    }
    pthread_create(&gid[N],NULL,print,NULL);
    for(i=0;i<N+1;i++)
    {
        pthread_join(gid[i],NULL);
    }

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cg);
    pthread_cond_destroy(&cp);

    return 0;
}