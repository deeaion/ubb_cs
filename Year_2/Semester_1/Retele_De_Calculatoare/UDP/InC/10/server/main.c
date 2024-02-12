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
int stohi(char *ip){
    char c;
    c = *ip;
    unsigned int integer=0;
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
            return 0;
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
        return 0;
    }
    return integer;
}
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

uint32_t handleClient(char* hostname)
{
   struct hostent *hostinfo;
   hostinfo=gethostbyname(hostname);
    if(hostinfo!=NULL)
    {char* IPbuffer=inet_ntoa(*((struct  in_addr*)hostinfo->h_addr_list[0]));
    //printf(IPbuffer);

    uint32_t put=1;
    uint32_t number;
    number=stohi(IPbuffer); return number;}
    return 0;
}
errorHandle newClient(int s,struct sockaddr_in serverin,int port)
{
    printf("Handling client!....\n");
    errorHandle errorH=getInitialError();
    uint16_t size;
    struct sockaddr_in client;
    int l =sizeof (client);
    int rez= accept(s,(struct sockaddr*)&client,&l);
    printf("%d",rez);
    memset(&client,0,sizeof (client));


    int recvResult=
            recvfrom(s,&size,sizeof (size),0,
                     (struct sockaddr* )&client,&l);
    if(recvResult<0)
    {
        changeError(&errorH,"Couldn't connect to the client!\n");

        return errorH;

    }
    size= ntohs(size);
    char* sir= malloc(size+1);
    memset(sir,0,size);
    recvResult= recvfrom(s,sir,size,0,(struct sockaddr*)&client,&l);
    uint32_t result=handleClient(sir);
    result= ntohl(result);

      int sendToRes= sendto(s,&result, sizeof (result),0,(struct sockaddr* )&client,sizeof (client));
    if(sendToRes<0)
    {
        changeError(&errorH,"Couldn't send result!\n");

    }
    printf("Closing port %d!\n...",port);
    free(sir);

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


        errorHandle error=newClient(s,server,port);
        if(error.succes==0)
        {
            perror(error.str);
        } else
        {
            printf("Handled the client without any errors!\n");
        }

    }
    return 0;
}
