/*INCLUDES*/
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
//threads do this
void *doWork(void * arg)
{
    printf("Entered the function to work...\n");
    int newSocket=(*(int*) arg);
    uint16_t nr1,nr2;

    //string 1
    if(recv(newSocket,&nr1,sizeof(nr1),MSG_WAITALL)!=sizeof(nr1))
    {
        printf("Failed to read!\n");
    }
    nr1=ntohs(nr1);
    printf("Got nr1: %d\n",nr1);
    char *sir1=(char*)malloc(sizeof(char)*(nr1+1));
    memset(sir1,'\0',nr1);
    int nrbytesread=recv(newSocket,sir1,nr1,MSG_WAITALL);
    if(nrbytesread<0)
    {
        printf("Failed to read!\n");
    }
    printf("Got the first string: %s , with length: %d\n",sir1,nr1);
    if(recv(newSocket,&nr2,sizeof(nr2),MSG_WAITALL)!=sizeof(nr2))
    {
        printf("Failed to read!\n");
    }
    //string 2
    //trimit ceva de confirmare
    sleep(1000);
    uint16_t nr=3;
    nr=htons(nr);
    send(newSocket,&nr,sizeof(nr),0);
    if(recv(newSocket,&nr2,sizeof(nr2),MSG_WAITALL)!=sizeof(nr2))
    {
        printf("Failed to read!\n");
    }
    nr2=ntohs(nr2);
    printf("Got nr1: %d\n",nr2);

    char *sir2=(char*)malloc(sizeof(char)*nr2);
    memset(sir2,'\0',nr2);

    nrbytesread=recv(newSocket,sir2,nr2,MSG_WAITALL);

    if(nrbytesread<=0)
    {
        printf("Failed to read!\n");
    }
    printf("Got the first string: %s , with length: %d\n",sir2,nr2);
    if(recv(newSocket,&nr2,sizeof(nr2),MSG_WAITALL)<=0)
    {
        printf("Failed to read!\n");
    }
    uint16_t nra=3;
    nra=htons(nra);
    send(newSocket,&nra,sizeof(nra),0);

    close(newSocket);
    pthread_exit(NULL);
}

int main(int argc,char **argv)
{
    //getting all the data for socket
    int port=atoi(argv[1]);
    //socket and client descriptors
    int s,c;
    //socket server and client
    struct sockaddr_in server,client;
    //lenght of struct client
    int l;
    s=socket(AF_INET,SOCK_STREAM,0);
    if(s<0)
    {
        perror("Error when creating the server!\n");
        exit(EXIT_FAILURE);
    }
    //giving attributes
    memset(&server,0,sizeof(server));
    server.sin_port=htons(port);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    //trying to bind to port
    if(bind(s,(struct sockaddr *) &server, sizeof(server))<0)
    {
        perror("Error when trying to bind to port!\n");
        exit(EXIT_FAILURE);
    }
    listen(s,5);
    l=sizeof(client);
    memset(&client,0,sizeof(client));
    //acum creez threads for clients
    pthread_t tid[5];
    int i=0;
    while(1)
    {
        c=accept(s,(struct sockaddr*)&client,&l);
        printf("A client has connected to the server...\n");
        if(pthread_create(&tid[i++],NULL, doWork,&c)!=0)
        {
            perror("Error when creating thread\n.");
            exit(EXIT_FAILURE);
        }
        if(i>=1)
        {
            i=0;
            while(i<5)
            {
                pthread_join(tid[i++],NULL);
            }
            i=0;
        }
    }
}