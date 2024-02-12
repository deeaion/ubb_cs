#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

union number
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

//recv from items

void sendUnsignedByteNumber( int *s,uint8_t *toSend,struct sockaddr_in* client)
{
    int sendToRes= sendto(*s,toSend, 1,0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes<0)
    {
        perror("Couldn't send result!\n");
        exit(1);

    }
}
uint16_t getunsignedInteger(int c,struct sockaddr_in* server)
{
    uint16_t result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)server, &l);
    if(recvFromRes!=2)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    result= ntohs(result);
    return result;
}
uint16_t* getNumbers(int s,uint16_t *size,struct sockaddr_in* socket)
{
    socklen_t l = sizeof(*socket);  // Set the initial length
    *size= getunsignedInteger(s,socket);
    uint16_t * sir= (uint16_t *)malloc((*size+1)*sizeof (uint16_t));
    int recvResult= recvfrom(s,sir,sizeof (uint16_t)*(*size),0,(struct sockaddr*)socket,&l);
    if(recvResult<0)
    {
        perror("Couldn't connect to the client!\n");
        exit(1);
    }
    return sir;
}
//read 4 byte integer

uint8_t readByte(char *mesaj)
{
    uint8_t numar;
    printf(mesaj);
    char numarc[2];
    scanf("%s",&numarc);
    numar= atoi(numarc);
    return numar;
}
//sendto
//sending strings

int main(int argc, char **argv) {
    int c;
    int port= atoi(argv[1]);
    char * ipAddress=argv[2];
    struct sockaddr_in server= get_socket_addr(&c,port,ipAddress);
    //read number
    uint8_t number=readByte("Dati numarul :");
    //send
    sendUnsignedByteNumber(&c,&number,&server);
    //get result
    uint16_t size;
    uint16_t *numbers= getNumbers(c,&size,&server);
    for(int i=0;i<size;i++)
    {
        printf("%hu ",numbers[i]);
    }


    close(c);
    return 0;
}
