/*

   Using PIPE channels create and implement the following scenario:
   Process A reads N integer numbers from the keyboard and sends them another process named B.
   Process B will add a random number, between 2 and 5, to each received number from process A and will send them to another process named C.
   Process C will add all the received numbers and will send the result back to process A. All processes will print a debug message before sending and after receiving a number.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
int main(int argc,char **argv)
{
    int pc[2],ps[2];
    if(pipe(pc)==-1)
    {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }
    if(pipe(ps)==-1)
    {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }
    int pid=fork();
    if(pid==-1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if(pid==0)
    {   close(ps[1]);
        close(pc[0]);
        int min=1000;
        int max=10000;

        while(1)
        {
            int g=0;
          //  srand(time(NULL));
            g=rand()%(max-min+1)+min;
            //printf("Here\n");
            write(pc[1],&g,sizeof(int));
            char c='\0';
            read(ps[0],&c,sizeof(char));
            //printf("%c\n",c);
            if(c=='=')
            {  printf("[COPIL] n=%d\n",g);
                break;
            }
            if(c=='>')
            {
                printf("[COPIL] n<%d\n",g);
                max=g;

            }
            if(c=='<')
            {
                printf("[COPIL] n<%d\n",g);
               min=g;
            }

        }
        close(ps[0]);
        close(pc[1]);
        exit(0);

    }
    //sunt in parinte
    close(pc[1]);
    close(ps[0]);
    int n=0;
    srand(time(NULL));
    n=rand()%(9000+1)+1000;
    printf("[PARINTE] Nr generat: %d\n",n);
    while(1)
    {
        int g=0;
        read(pc[0],&g,sizeof(int));
        printf("[PARINTE] Am primit %d\n",g);
        char c='\0';
        if(g==n)
        {   c='=';
            //printf("%c\n",c);
            write(ps[1],&c,sizeof(char));
            break;
        }
        if(g>n)
        {
            c='>';
            //printf("%c\n",c);

        }
        if(g<n)
        {
            c='<';
            //printf("%c\n",c);
        }
        write(ps[1],&c,sizeof(char));
        sleep(1);

    }
    close(pc[0]);
    close(ps[1]);
    wait(NULL);
    return 0;

}