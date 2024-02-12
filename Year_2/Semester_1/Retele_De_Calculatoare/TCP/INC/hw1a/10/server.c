
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
#include <arpa/inet.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int mostCommonChar(char *maxChar, char *sir1, char *sir2, int nrChar1, int nrChar2) {
    struct FreqLetter{
        char caracter;
        int freq;
    }FreqLetter;
    int posToCheck = 0;
    if (nrChar1 > nrChar2) {
        posToCheck = nrChar2;
    } else {
        posToCheck = nrChar1;
    }
    struct FreqLetter letters[nrChar1+nrChar2];
    memset(letters,0,sizeof (FreqLetter));
    int difLetters=0;
    for (int i = 0; i < posToCheck; i++)
    {
        if (sir1[i] == sir2[i])
        {
            int found=0;
            for(int j=0;j<difLetters;j++)
            {
                if(letters[j].caracter==sir1[i])
                {
                    found=1;
                    letters[j].freq++;
                }
            }
            if(found==0)
            {
                struct FreqLetter newFounding;
                newFounding.caracter=sir1[i];
                newFounding.freq=1;
                letters[difLetters]=newFounding;
                difLetters++;

            }
        }
    }
    int max = 0;
    for(int i=0;i<difLetters;i++)
    {
        if(letters[i].freq>max)
        {
            max = letters[i].freq;
            *maxChar = letters[i].caracter;
        }
    }
    return max;
}

void *doWork(void *arg) {
    printf("Working with the client...\n");
    int newSocket = (*(int *) arg);
    uint16_t nrChar1, nrChar2;

    recv(newSocket, &nrChar1, sizeof(nrChar1), MSG_WAITALL);
    nrChar1 = ntohs(nrChar1);
    //printf("Numar de char: %d\n", nrChar1);

    int nrbytesread=recv(newSocket, &nrChar2, sizeof(nrChar2), MSG_WAITALL);
    //convertesc
    nrChar2 = ntohs(nrChar2);
    //printf("Numar de char: %d\n", nrChar2);

    char *sir1 = (char *) malloc(nrChar1);
    memset(sir1, '\0', nrChar1);
    nrbytesread=recv(newSocket, sir1, nrChar1-1, MSG_WAITALL);
    printf("Got the first string %s\n", sir1);
    char *sir2 = (char *) malloc(nrChar2+1);
    //ma asigur ca spatiul e gol
    memset(sir2, '\0', nrChar2);
    recv(newSocket, sir2, nrChar2-1, MSG_WAITALL);
    printf("Got the second string %s\n", sir2);


    char maxChar;
    int max = mostCommonChar(&maxChar, sir1, sir2, nrChar1-1, nrChar2-1);
    printf("The most found common letter on same position is %c appearing %d times\n", maxChar, max);
   // maxChar = htons(maxChar);
    send(newSocket, &maxChar,1, 0);
    max = htons(max);
    send(newSocket, &max, sizeof(max), 0);
    close(newSocket);
    pthread_exit(NULL);


}

int main(int argc, char **argv) {

    int port = atoi(argv[1]);
    int s;
    struct sockaddr_in server, client;
    int c;
    int l;

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("ERROR WHEN CREATING THE SOCKET\n");
        exit(EXIT_FAILURE);

    }
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(port);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("ERROR WHEN BINDING TO PORT\n");
        exit(EXIT_FAILURE);

    }
    listen(s, 5);
    l = sizeof(client);
    memset(&client, 0, sizeof(client));
    pthread_t tid[20];
    int i = 0;
    while (1) {
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("A client has connected to the server...\n");
        if (pthread_create(&tid[i++], NULL, doWork, &c) != 0) {
            perror("ERROR WHEN CREATING THE THREAD\n");
            exit(EXIT_FAILURE);


        }
        if (i >= 20) {
            i = 0;
            while (i < 20) {
                pthread_join(tid[i++], NULL);

            }
            i = 0;
        }


    }
    close(s);
    return 0;


}
