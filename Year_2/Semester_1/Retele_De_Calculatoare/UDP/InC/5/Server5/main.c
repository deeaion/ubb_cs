#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
int isdigit(char c)
{
    if(c>='0'&&c<='9')
        return 1;
    return 0;
}
//transform ip to number
int stohi(char *ip){
    char c;
    c = *ip;
    unsigned int integer=-1;
    int val;
    int i,j=0;
    for (j=0;j<4;j++)
    {
        if (!isdigit(c))
        {  //first char is 0
            return (0);
        }
        val=0;
        for (i=0;i<3;i++)
        {
            if (isdigit(c)) {
                val = (val * 10) + (c - '0');
                c = *++ip;
            } else
                break;
        }
        if(val<0 || val>255){
            return -1;
        }
        if (c == '.') {
            integer=(integer<<8) | val;
            c = *++ip;
        }
        else if(j==3 && c == '\0'){
            integer=(integer<<8) | val;
            break;
        }

    }
    if(c != '\0'){
        return -1;
    }
    return integer;
}
//Creating a socket
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


//FOR ERROR HANDLING
typedef struct errorHandling
{
    int succes;
    char str[400];
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






uint8_t getByteUnsigned(int c,struct sockaddr_in* server,errorHandle * errorH)
{
    uint8_t result;
    socklen_t l = sizeof(*server);  // Set the initial length

    int recvFromRes= recvfrom(c,&result, 1,0,(struct sockaddr*)server, &l);
    if(recvFromRes!=1)
    {
        changeError(errorH,"Didn't recieve the number!\n");
        return 1;
    }
    return result;
}


void sendNumber(int s,uint16_t *toSend,struct sockaddr_in *client,errorHandle *errorH)
{
    *toSend= htons(*toSend);
    int sendToRes= sendto(s,toSend, 2,0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes!=2)
    {
        changeError(errorH,"Couldn't send result!\n");

    }
    *toSend= ntohs((*toSend));

}

void sendIntegerVectorToServer(int c,uint16_t *numbers,uint16_t *len,struct sockaddr_in *server,errorHandle *errorH)
{
    sendNumber(c,len,server,errorH);
    if(!errorH->succes)
        return;
    int lT= sizeof(uint16_t)*(*len);
    int sendToResult= sendto(c,numbers, lT,0,(struct sockaddr*) server, sizeof(*server));
    if(sendToResult<0)
    {
        changeError(errorH,"Could not send String!...\n");
        return;
    }
}
void sendUnsignedByteNumber(int *s,uint8_t *toSend,struct sockaddr_in* client,errorHandle *errorH)
{
    int sendToRes= sendto(*s,toSend, sizeof ((*toSend)),0,(struct sockaddr* )client,sizeof (*client));
    if(sendToRes<0)
    {
        changeError(errorH,"Couldn't send result!\n");

    }
}



uint16_t * handleClient(uint8_t number,uint16_t *nrFound)
{
    uint16_t *difuzori=(uint16_t*) malloc(sizeof(uint16_t)*(number/2));
    memset(difuzori,0,sizeof (difuzori));
    int count=0;
    for(int  i=1;i<=number;i++)
    {
        if(number%i==0)
        {
            difuzori[count++]=i;
        }
    }
    for (int i = 0; i < count; ++i) {
        printf("%d",difuzori[i]);
    }
    *nrFound=count;
    return difuzori;
}
errorHandle newClient(int s,struct sockaddr_in serverin,int port,struct sockaddr_in *client,int l)
{
    printf("Handling client!....\n");
    //making sure i have errors handled
    errorHandle errorH=getInitialError();
    uint8_t number= getByteUnsigned(s,client,&errorH);
    uint16_t nrDifFound;
    uint16_t *difuzori= handleClient(number,&nrDifFound);
    sendIntegerVectorToServer(s,difuzori,&nrDifFound,client,&errorH);



    if(!errorH.succes)
    {
        return errorH;
    }



    printf("Closing client!\n...",port);
    close(l);
    return errorH;
}
int main(int argc,char** argv) {
    int s=0;
    int port= atoi(argv[1]);
    printf("Port: %d\n",port);
    struct sockaddr_in server;
    server= get_socket_addr(&s,port,server);
    printf("%d\n",s);
    while (1)
    {
        printf("Astept clienti pe port %d!...\n",port);
        struct sockaddr_in client;
        int l =sizeof (client);
        memset(&client,0,sizeof (client));
        errorHandle error=newClient(s,server,port,&client,l);

        if(error.succes==0)
        {
            perror(error.str);
            exit(1);
        } else
        {
            printf("Handled the client without any errors!\n");
        }

    }
    return 0;
}
