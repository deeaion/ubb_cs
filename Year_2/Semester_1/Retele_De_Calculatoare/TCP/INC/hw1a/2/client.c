#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
 #include <arpa/inet.h>
int main(int argv,char **arg)
{
    uint16_t ap;
    int port=atoi(arg[1]);
    char* ip=arg[2];
    struct sockaddr_in server;
    uint16_t c=socket(AF_INET,SOCK_STREAM,0);
    if(c<0)
    {
        printf("Error when creating the client's socket!\n");
        return 1;
    }
    memset(&server,0,sizeof (server));
    server.sin_port=htons(port);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(ip);
    if(connect(c,(struct sockaddr*)&server,sizeof(server))<0)
    {
        printf("Error connecting to the server!\n");
        return 1;
    }
    printf("Please enter the string:\n");
    char* string=malloc(sizeof(char)*100);
    memset(string,'\0',100);
    fgets(string,100,stdin);
    printf("String is: %s\n",string);
    uint16_t numar=strlen(string);
    numar=htons(numar);
    send(c,&numar,sizeof (numar),0);
    send(c,string,sizeof(char)*numar,0);
    recv(c,&ap,sizeof(ap),0);
    ap=ntohs(ap);
    free(string);
    printf("Ap este %hu\n",ap);
    close(c);
}
