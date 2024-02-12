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
//get string
char* getSir(int *s,int *size,struct sockaddr_in* client)
{

    socklen_t l = sizeof(*client);  // Set the initial length

    int recvResult=
            recvfrom(*s,size,sizeof (size),MSG_WAITALL,
                     (struct sockaddr* )client,&l);
    if(recvResult<0)
    {
        perror("Couldn't connect to the client!\n");
        exit(1);

    }
    *size= ntohs(*size);
    char* sir= malloc((*size)+1);
    recvResult= recvfrom(*s,sir,*size,0,(struct sockaddr*)client,&l);
    if(recvResult<0)
    {
        perror("Couldn't connect to the client!\n");
        exit(1);
    }
    return sir;


}
uint16_t* getNumbers(int s,int *size,struct sockaddr_in* socket)
{
    socklen_t l = sizeof(*socket);  // Set the initial length

    int recvResult=
            recvfrom(s,size,sizeof (size),MSG_WAITALL,
                     (struct sockaddr* )socket,&l);
    if(recvResult<0)
    {
        perror("Couldn't connect to the client!\n");
        exit(1);

    }
    *size= ntohs(*size);
    uint16_t * sir= (uint16_t *)malloc(((*size)+1)*sizeof (uint16_t));
    recvResult= recvfrom(s,sir,*size,0,(struct sockaddr*)socket,&l);
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

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)&server,&l);
    if(recvFromRes!=4)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    return result;
}
uint16_t getunsignedInteger(int c,struct sockaddr_in* server)
{
    uint16_t result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)&server, &l);
    if(recvFromRes!=2)
    {
        perror("Could not get the result!\n");
        exit(1);
    }
    return result;
}
char getChar(int c,struct sockaddr_in* server)
{
    char result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, sizeof(result),0,(struct sockaddr*)&server, &l);
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
int main(int argc, char **argv) {
    int c;
    int port= atoi(argv[1]);
    char * ipAddress=argv[2];
    struct sockaddr_in server= get_socket_addr(&c,port,ipAddress);


    //get sir
    char* sirToMirror= readStringFromUser("Give the string you want to mirror:\n");
    //sending it
    int len= strlen(sirToMirror);
    sendStringToServer(c,sirToMirror,&len,&server);
    //gettting result
    char* result= getSir(&c,&len,&server);
    printf("Mirrored string of %s is : %s ",sirToMirror,result);
    close(c);
    return 0;
}
