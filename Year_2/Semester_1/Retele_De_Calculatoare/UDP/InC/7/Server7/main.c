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
char* getSir(int *s,uint16_t *size,struct sockaddr_in* client,errorHandle *errorH)
{
    socklen_t l = sizeof(*client);  // Set the initial length

    int recvResult=
            recvfrom(*s,size,sizeof (size),MSG_WAITALL,
                     (struct sockaddr* )client,&l);
    if(recvResult<0)
    {
        changeError(errorH,"Couldn't connect to the client!\n");

        return NULL;

    }
    *size= ntohs(*size);
    char* sir= malloc((*size)+1);
    recvResult= recvfrom(*s,sir,*size,0,(struct sockaddr*)client,&l);
    if(recvResult<0)
    {
        changeError(errorH,"Couldn't connect to the client!\n");

        return NULL;
    }
    return sir;


}


char* handleClient(char* sir,uint16_t i,uint16_t l,uint16_t size,uint16_t *pos)
{
    //verificare validitate
    if(size<=i+l)
    {
        return "Parametrii invalizi\n";
    }
    char* result=(char*) malloc(sizeof(char)*l);
    uint16_t count=0;
    for(int j=i;j<l+i;j++)
    {
        result[count++]=sir[j];
    }
    *pos=count;
    return result;


}
//send
void sendStringToServer(int c,char* string,uint16_t *len,struct sockaddr_in *server,errorHandle *errorH)
{
    *len=(*len)-1;
    *len= htons(*len);
    int sendToResult1= sendto(c,len, sizeof(*len),0,(struct sockaddr* )server, sizeof(*server));
    if(sendToResult1<0)
    {
        changeError(errorH,"Could not send String!...\n");
        return;
    }
    *len= ntohs((*len));
    size_t lenToSend= sizeof(char)*(*len);
    sendToResult1= sendto(c,string, lenToSend,0,(struct sockaddr*) server,
            sizeof(*server));
    if(sendToResult1<0)
    {
        changeError(errorH,"Could not send String!...\n");
        return;
    }
    //schimb inapoi ca nu cumva sa incerc sa fol codat

}
errorHandle newClient(int s,struct sockaddr_in serverin,int port,struct sockaddr_in *client,int l)
{
    printf("Handling client!....\n");
    //making sure i have errors handled
    errorHandle errorH=getInitialError();
    uint16_t size;
    char *sir= getSir(&s,&size,client,&errorH);
    uint16_t i= getunsignedInteger(s,client,&errorH);
    uint16_t lSir= getunsignedInteger(s,client,&errorH);
    uint16_t pos;

    char *result= handleClient(sir,i,lSir,size,&pos);
    pos+=1;

    sendStringToServer(s,result,&pos,client,&errorH);

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