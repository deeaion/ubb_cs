#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
struct sockaddr_in get_socket_addr(int *c,int newPort,char * ipAddress)
{
    struct sockaddr_in client;
    int socketReturn;
    socketReturn=socket(AF_INET,SOCK_DGRAM,0);
    if(socketReturn<0)
    {
        perror("Eroare la creearea socketului!...\n");
        exit(1);
    }
    memset(&client,0,sizeof (client));
    client.sin_port= htons(newPort);
    client.sin_family=AF_INET;
    client.sin_addr.s_addr=inet_addr(ipAddress);
    *c=socketReturn;
    return client;
}
int main(int argc,char **argv) {
    int c;
    int port= atoi(argv[1]);
    char * ipAddress=argv[2];
    struct sockaddr_in server= get_socket_addr(&c,port,ipAddress);
    uint16_t number=-1;
    printf("Dati numarul: \n");
    scanf("%hu",&number);
    number= htons(number);
    int sendToResult= sendto(c,&number,sizeof (number),0,(struct sockaddr* )&server, sizeof(server));
    if(sendToResult<0)
    {
        perror("Could not send message!\n");
        exit(1);
    }
    uint16_t result=-1;
    int l=sizeof (server);
    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)&server, &l);
    if(recvFromRes<0)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    result= ntohs(result);
    if(result)
    {
        printf("Numarul %d este prim!\n", ntohs(number));
    } else
    {
        printf("Numarul %d nu este prim!\n", ntohs(number));
    }
    return 0;
}
