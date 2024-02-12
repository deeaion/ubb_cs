#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#define n 100
#include <arpa/inet.h>
int main(int argc,char** argv)
{
    //client
    int port=atoi(argv[1]);
    char *ip=argv[2];
    struct sockaddr_in server;
    uint16_t c=socket(AF_INET,SOCK_STREAM,0);
    if(c<0)
    {
        perror("Error when creating client\n");
        exit(EXIT_FAILURE);
    }
    memset(&server,0,sizeof(server));
    server.sin_port=htons(port);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(ip);

    //connecting
    if(connect(c,(struct sockaddr*)&server,sizeof(server))<0)
    {
        printf("Error connecting to the server!\n");
        return 1;
    }
    //trimitere strings
    char *str1=(char*)malloc(sizeof(char)*n);
    uint16_t n1;
    fgets(str1,n,stdin);
    printf("Read %s with %d letters\n",str1,strlen(str1));
    n1=strlen(str1);
    n1=htons(n1);
    send(c,&n1,sizeof(n1),0);
    str1[n1]='\0';
    send(c,str1,n1,0);
    char *str2=(char*)malloc(sizeof(char)*n);
    uint16_t toget1;
    recv(c,&toget1,sizeof(toget1),0);
    toget1=ntohs(toget1);
    printf("Got %d\n",toget1);
    uint16_t n2;
    fgets(str2,n,stdin);
    printf("Read %s with %d letters\n",str2,strlen(str2));
    n2=strlen(str2);
    n2=htons(n2);
    send(c,&n2,sizeof(n2),0);
    str2[n2]='\0';
    send(c,str2,n2,0);
    uint16_t toget;
    recv(c,&toget,sizeof(toget),0);
    toget=ntohs(toget);
    printf("%hu\n",toget);
    close(c);
}