//Scrieti un program C care primeste un numar N ca argument la linia de comanda.
//Programul creeaza N thread-uri care vor genera numere aleatoare intre 0 si 111111
//(inclusiv) pana cand un thread va genera un numar divizibil cu 1001. Thread-urile vor afisa
//numerele generate, iar ultimul numar afisat trebuie sa fie cel divizibil cu 1001. Niciun
//thread nu va incepe sa genereze numere pana cand toate celelalte thread-uri au fost create.
//Nu se vor folosi variabile globale.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_barrier_t barr;
pthread_mutex_t mtx;
int flag;
int N;
void* doWork(void* arg)
{   int id=*(int *)arg;
    pthread_barrier_wait(&barr);

    while(1)
    {
       pthread_mutex_lock(&mtx);
        if(!flag)
        {
            int gen=rand()%111112;
            printf("Sunt threadul %d si am gen %d\n",id,gen);
            if(gen%1001==0)
            {
                printf("!!!!!!!!!!!Sunt threadul %d si am gASIT %d\n",id,gen);
                flag=1;
                break;

            }
        }
        else
        {
            break;
        }
        pthread_mutex_unlock(&mtx);
    }
    pthread_mutex_unlock(&mtx);
   free(arg);

    return NULL;
}
int main(int argc,char** argv)
{
    if(argc<2)
    {
        printf("Not enough args!\n");
        exit(1);
    }
    N=atoi(argv[1]);
    pthread_t tid[N];
    int i=0;
    pthread_barrier_init(&barr,NULL,N);
    for(i=0;i<N;i++)
    {
        int *arg=(int*) malloc(sizeof(int));
        *arg=i;
        pthread_create(&tid[i],NULL,doWork,arg);
    }

    for(i=0;i<N;i++)
    {
        pthread_join(tid[i],NULL);
    }
    pthread_mutex_destroy(&mtx);

    pthread_barrier_destroy(&barr);
    return 0;
}