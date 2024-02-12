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

uint16_t getunsignedInteger(int c,struct sockaddr_in* server,errorHandle *errorH)
{
    uint16_t result;
    socklen_t len = sizeof(*server);  // Set the initial length
    int recvFromRes;
    recvFromRes=recvfrom(c, &result, sizeof(result), 0, (struct sockaddr*)server, &len);
    if(recvFromRes!=2)
    {
        changeError(errorH,"Didn't recieve the number!\n");
        return 1;
    }
    result= ntohs(result);
    return result;
}
void sendNumber(int s,uint16_t *toSend,struct sockaddr_in *client,errorHandle *errorH)
{
    *toSend= htons(*toSend);
    int sendToRes= sendto(s,toSend, sizeof(uint16_t),0,
                          (struct sockaddr* )client,sizeof (struct sockaddr_in));
    if(sendToRes!=2)
    {
        changeError(errorH,"Couldn't send result!\n");

    }
    *toSend= ntohs((*toSend));

}
uint16_t cmmdc(int a,int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
uint16_t cmmmc(int a,int b)
{
    return (a*b)/ cmmdc(a,b);
}
uint16_t handleClient(int a,int b)
{

    return cmmdc(a,b);
}
errorHandle newClient(int s,struct sockaddr_in serverin,int port,struct sockaddr_in *client,int l)
{
    printf("Handling client!....\n");
    //making sure i have errors handled
    errorHandle errorH=getInitialError();
    uint16_t a,b;
    a= getunsignedInteger(s,client,&errorH);
    b= getunsignedInteger(s,client,&errorH);
    uint16_t gcd= handleClient(a,b);
    uint16_t lcm= cmmmc(a,b);
    sendNumber(s,&gcd,client,&errorH);
    sendNumber(s,&lcm,client,&errorH);
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
