#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int size=100;
int main(int argv, char **argc) {
    int port = atoi(argc[1]);
    char *ip = argc[2];
    struct sockaddr_in server;
    uint16_t c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0)
    {
        perror("ERROR WHEN CREATING THE CLIENT\n");
        exit(EXIT_FAILURE);
    }
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(port);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    if (
            connect(c, (struct sockaddr *) &server, sizeof(server)) < 0
                    ) {
        printf("Error connecting to the server!\n");
        return 1;
    }




    //NOW CODE IMPLEMENTATION

    uint16_t aparitii;
    char maxChar;

    printf("Please enter the first string:\n");
    char *string1=(char*) malloc(100);
    memset(string1, '\0', 100);
    uint16_t numar1;
    if (fgets(string1,100,stdin)) {
        numar1= strlen(string1);
        if (string1[numar1-1] == '\n') {
           // printf("I am here!\n");
            string1[numar1-1] = '\0'; // Remove the newline
        }}
    numar1 = htons(numar1);


    printf("Please enter the second string:\n");
    char *string2=(char *)malloc(100);
    uint16_t numar2;
    memset(string2, '\0', 100);
    if (fgets(string2,100,stdin)) {
            // Remove the trailing newline character if it exists
            numar2= strlen(string2);
            if (string2[numar2-1] == '\n') {
             //   printf("I am here!\n");
                string2[numar2-1] = '\0'; // Remove the newline
            }}
    numar2 = htons(numar2);

    send(c, &numar1, sizeof(numar1), 0);
    send(c, &numar2, sizeof(numar2), 0);
    send(c, string1, strlen(string1), 0);
    send(c, string2, strlen(string2), 0);
    recv(c, &maxChar, sizeof(maxChar), 0);
    recv(c, &aparitii, sizeof(aparitii), 0);
    aparitii = ntohs(aparitii);
    printf("The character that appears the most on the same postion is %c with a frequency of %d\n", maxChar, aparitii);
    close(c);
}
