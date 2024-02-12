#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
struct sockaddr_in get_socket_addr(int *s,int newPort,struct sockaddr_in server1)
{
    struct sockaddr_in server=server1;
    int socketReturn;
    socketReturn=socket(AF_INET,SOCK_DGRAM,0);
    if(socketReturn<0)
    {
        perror("Eroare la creearea socketului!...\n");
        exit(1);
    }
    memset(&server,0,sizeof (server));
    server.sin_port= htons(newPort);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    if(bind(socketReturn,(struct sockaddr *) &server,sizeof (server))<0)
    {
        perror("Eroare la bind...\n");
        exit(1);
    }
    *s=socketReturn;
    return server;
}
typedef struct errorHandling
{
    int succes;
    char str[200];
}errorHandle;
errorHandle getInitialError()
{
    errorHandle error;
    error.succes=1;
    return error;
}
void changeError(errorHandle* modify,char* error)
{
    strcat(modify->str,error);
    modify->succes=0;
}

int handleClient(uint16_t number)
{
    if(number==0||number==1)
    {
        return 0;
    }
    if(number==2)
    {
        return 1;
    }
    if(number%2==0)
    {
        return 0;
    }
    int difuzor=3;
    while (difuzor<number/2)
    {
        if(number%difuzor==0)
        {
            return 0;
        }
        difuzor+=2;
    }
    return 1;
}
errorHandle newClient(int s,struct sockaddr_in serverin,int *port)
{
    printf("Handling client!....\n");
    errorHandle errorH=getInitialError();
    uint16_t number=-1;


    struct sockaddr_in client;
    int l =sizeof (client);
    memset(&client,0,sizeof (client));

    int recvResult=
            recvfrom(s,&number,sizeof (number),MSG_WAITALL,
                     (struct sockaddr* )&client,&l);
    if(recvResult<0)
    {
        changeError(&errorH,"Couldn't connect to the client!\n");

        return errorH;

    }
    number= ntohs(number);
    int result=handleClient(number);
    result= htons(result);
    int sendToRes= sendto(s,&result, sizeof (result),0,(struct sockaddr* )&client,sizeof (client));
    if(sendToRes<0)
    {
        changeError(&errorH,"Couldn't send result!\n");

    }

    return errorH;
}
int main(int argc,char** argv) {
    int s=0;
    int port= atoi(argv[1]);
    printf("Port: %d\n",port);
    struct sockaddr_in server;
    server= get_socket_addr(&s,port,server);
    printf("%d\n",s);
    int newPort=3000;
    while (1)
    {

            printf("Astept clienti pe port %d!...\n",port);

            newClient(s,server,&port);


    }
    return 0;
}
