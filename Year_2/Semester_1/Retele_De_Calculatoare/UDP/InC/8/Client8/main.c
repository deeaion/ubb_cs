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
//corectat
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
//get string
char* getSir(int *s,int *size,struct sockaddr_in* client)
{

    socklen_t l = sizeof(*client);  // Set the initial length
    *size= getunsignedInteger(*s,client);
    char* sir= malloc((*size)+1);
    int recvResult= recvfrom(*s,sir,*size,0,(struct sockaddr*)client,&l);
    if(recvResult<0)
    {
        perror("Couldn't connect to the client!\n");
        exit(1);
    }
    return sir;


}
void sendUnsignedByteNumber(int *s,uint8_t *toSend,struct sockaddr_in* client)
{
    int sendToRes= sendto(*s,toSend, sizeof ((*toSend)),0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes<0)
    {
        perror("Couldn't send result!\n");
        exit(1);

    }
}
//corectat
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
uint32_t get4ByteInteger(int c,struct sockaddr_in* server)
{
    uint32_t result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)server,&l);
    if(recvFromRes!=4)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    result= ntohl(result);
    return result;
}
uint8_t getByteUnsigned(int c,struct sockaddr_in* server)
{
    uint8_t result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, 1,0,(struct sockaddr*)server, &l);
    if(recvFromRes!=1)
    {
        perror("Didn't recieve the number!\n");
        return 1;
    }
    return result;
}


char getChar(int c,struct sockaddr_in* server)
{
    char result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)server, &l);
    if(recvFromRes<0)
    {
        perror("Could not get the character!\n");
        exit(1);
    }
    result= ntohs(result);
    return result;
}


//input user
char *readStringFromUser(char* mesaj)
{
    char *string= (char*)malloc(100);
    memset(string,0,100);
    printf("%s",mesaj);
    fgets(string,100,stdin);
    return string;

}
int readNumber(char *mesaj)
{
    int number;
    printf(mesaj);
    scanf("%d",&number);
    return number;
}
int readChar(char  *mesaj)
{
    char c;
    printf(mesaj);
    scanf("%c",&c);
    return c;
}
uint8_t readByte(char *mesaj)
{
    uint8_t numar;
    printf(mesaj);
    scanf("%s",&numar);
    return numar;
}
//sendto
//sending strings
void sendStringToServer(int c,char* string,int *len,struct sockaddr_in *server)
{
    *len=(*len)-1;
    string[*len]=0;
    *len= htons(*len);
    int sendToResult1= sendto(c,len,sizeof ((*len)),0,(struct sockaddr* )server, sizeof((*server)));
    if(sendToResult1<0)
    {
        perror("Could not send String!...\n");
        exit(1);
    }
    *len= ntohs((*len));
    sendToResult1= sendto(c,string,*len,0,server, sizeof(*server));
    if(sendToResult1<0)
    {
        perror("Could not send String!...\n");
        exit(1);
    }
    //schimb inapoi ca nu cumva sa incerc sa fol codat

}
char* getStringFromServer(int s,uint16_t *size,struct sockaddr_in* client)
{

    *size= getunsignedInteger(s,client);
    char *sir=(char *) malloc(*size);
    socklen_t l= sizeof(*client);
    int sendToRes= recvfrom(s,sir, *size,0,(struct sockaddr*)client, &l);

    if(sendToRes<0)
    {
        perror("Couldn't get result!\n");
        exit(1);
    }
    return sir;

}
void sendIntegerVectorToServer(int c,uint16_t numbers[],int*len,struct sockaddr_in *server)
{
    *len= htons(*len);
    int sendToResult1= sendto(c,len,sizeof ((*len)),0,(struct sockaddr* )server, sizeof((*server)));
    if(sendToResult1<0)
    {
        perror("Could not send String!...\n");
        exit(1);
    }
    sendToResult1= sendto(c,numbers, sizeof(numbers),0,(struct sockaddr*) server, sizeof(*server));
    if(sendToResult1<0)
    {
        perror("Could not send String!...\n");
        exit(1);
    }
}
void send4ByteNumber(int s,uint32_t *toSend,struct sockaddr_in* client)
{
    *toSend= ntohl(*toSend);
    int sendToRes= sendto(s,toSend, sizeof ((*toSend)),0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes!=4)
    {
        perror("Couldn't send result!\n");
        exit(1);

    }
}
void sendNumber(int *s,uint16_t *toSend,struct sockaddr_in* client)
{
    *toSend= htons(*toSend);
    int sendToRes= sendto(*s,toSend, sizeof ((*toSend)),0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes!=2)
    {
        perror("Couldn't send result!\n");
        exit(1);

    }
    *toSend= ntohs((*toSend));

}



//print byte
void print(union number itoch)
{
    printf("char[] values: %u.%u.%u.%u\n", itoch.byte[3], itoch.byte[2], itoch.byte[1], itoch.byte[0]);
}
void sendChar(int s,char *c,struct sockaddr_in* socket)
{
    int sendToRes= sendto(s,c, sizeof(char),0,(struct sockaddr*)socket, sizeof(*socket));
    if(sendToRes!=1)
    {
        perror("Couldn't send result!\n");
        exit(1);

    }
}
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
    int size;
    uint16_t *numbers= getNumbers(c,&size,&server);
    for(int i=0;i<size;i++)
    {
        printf("%hu ",numbers[i]);
    }


    close(c);
    return 0;
}
