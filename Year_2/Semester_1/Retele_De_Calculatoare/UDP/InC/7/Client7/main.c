#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
/*
 * Un client trimite unui server un sir de lungime cel mult 100 de
 * caractere si doua numere (fie acestea s, i, l). Serverul va returna
 * clientului subsirul de lungime l a lui s care incepe la pozitia i.
 */
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
void sendStringToServer(int c,char* string,uint16_t *len,struct sockaddr_in *server)
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
int main(int argc, char **argv) {
    int c;
    int port= atoi(argv[1]);
    char * ipAddress=argv[2];
    struct sockaddr_in server= get_socket_addr(&c,port,ipAddress);

    //sir
    uint16_t size;
    char *sir= readStringFromUser("Dati sir: \n");
    size= strlen(sir);
    sendStringToServer(c,sir,&size,&server);

    //nr 1 <-i
    uint16_t i;
    i= readNumber("Dati i: \n");
    sendNumber(&c,&i,&server);

    //nr 2<-l
    uint16_t l;
    l= readNumber("Dati l: \n");
    sendNumber(&c,&l,&server);

    //geting result

    uint16_t sizeR;
    char *result=getStringFromServer(c,&sizeR,&server);
    printf(result);



    return 0;
}
