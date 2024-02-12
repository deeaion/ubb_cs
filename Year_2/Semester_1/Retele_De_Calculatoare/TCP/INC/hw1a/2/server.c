//2.Un client trimite unui server un sir de caractere. 
//Serverul va returna clientului numarul de caractere spatiu din sir.
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
int terminate=0;
void * socketThread(void * arg)
{
    printf("Working with the client...\n");
    int newSocket=*((int*)arg);
    uint16_t nrChar;
    recv(newSocket,&nrChar,sizeof(nrChar),MSG_WAITALL);
    nrChar=ntohs(nrChar);
    printf("Got the nrChar! %hu\n",nrChar);
    char* charString=(char*)malloc(nrChar+1);
    memset(charString, '\0', nrChar + 1);
    if(recv(newSocket,charString,nrChar,MSG_WAITALL)<0)
	{
		printf("Failed read!\n");
	};
    printf("Got the String  %s\n",charString);
    uint16_t count=0;
    for(int i=0;i<nrChar;i++)
    {
        if(charString[i]==' ')
        {
            count++;
        }
    }
    printf("Got the count! %hu\n",count);
    count= htons(count);
    send(newSocket,&count,sizeof(count),0);
    free(charString);
    close(newSocket);
    pthread_exit(NULL);
}
int main(int argv,char** arg) {
    int port=atoi(arg[1]);//port
    //char* ip_address=arg[2];
    int sDesc; //descriptor la socket
    struct sockaddr_in server,client;
    int cDesc;
    uint16_t lenght;

    sDesc=socket(AF_INET,SOCK_STREAM,0);
    //AF_INET-> familia socket
    //SOCK_STREAM-> based on connection
    //treating errors
    if(sDesc<0)
    {
        printf("Error when creating socket of server\n");
        return 1;
    }
    memset(&server,0,sizeof (server));
    server.sin_port=htons(port);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    if(bind(sDesc,(struct sockaddr *) &server,sizeof (server))<0)
    {
        printf("Error when trying to bind\n!");
        return 1;
    }
    //i will have a queue for 5 clients
    listen(sDesc,5);
    lenght=sizeof(client);
    memset(&client,0,sizeof(client));
    pthread_t tid[20];
    int i=0;
    while(1)
    {
        cDesc=accept(sDesc,(struct sockaddr *) &client,&lenght);
        printf("A client has connected to the server.\n");
        if(pthread_create(&tid[i++],NULL,socketThread,&cDesc)!=0)
        {
            printf("Failed to create thread!\n");
        }
        if(i>=20)
        {
            i=0;
            while(i<20)
            {
                pthread_join(tid[i++],NULL);
            }
            i=0;
	close(cDesc);
        }
    }
    close(sDesc);


}
