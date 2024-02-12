#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
union
{
    unsigned int integer;
    unsigned char byte[4];
} itoch;
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
    char *name= malloc(100);
    memset(name,0,100);
    printf("Dati hostname: \n");
    fgets(name,100,stdin);
    int sizeofString= strlen(name)-1;
    name[sizeofString]=0;
    sizeofString= htons(sizeofString);

    int sendToResult1= sendto(c,&sizeofString,sizeof(sizeofString),0,(struct sockaddr* )&server, sizeof(server));
    sizeofString= ntohs(sizeofString);
    int sendToResult2= sendto(c,name,sizeofString,0,(struct sockaddr* )&server, sizeof(server));
    if(sendToResult1<0)
    {
        perror("Could not send message!\n");
        exit(1);
    }
    uint32_t result=-1;
    int l=sizeof (server);
    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)&server, &l);
    if(recvFromRes<0)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    itoch.integer = result;
    if(result==0)
    {
        printf("Could not find id adress of given hostname!\n");
    } else
    printf("char[] values: %u.%u.%u.%u\n", itoch.byte[0], itoch.byte[1], itoch.byte[2], itoch.byte[3]);
    return 0;
}
