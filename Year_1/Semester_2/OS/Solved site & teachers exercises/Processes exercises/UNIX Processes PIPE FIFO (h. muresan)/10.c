#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
int main(int arg,char** argv)
{
    int ps[2],pc[2];
    if(pipe(ps)==-1)
    {
        perror("pipe()");
        exit(EXIT_FAILURE);
    }
    if(pipe(pc)==-1)
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
    {
        //sunt in procesul copil
        close(ps[1]);
        close(pc[0]);
        while(1)
        {
            int n=0;
            read(ps[0],&n,sizeof(int));
            printf("[COPIL] Am citit %d\n",n);
            n=n/2;
            write(pc[1],&n,sizeof(int));
            if(n<5)
                break;
        }
        close(ps[0]);
        close(pc[1]);
        exit(0);
    }
    //aici sunt in procesul parinte
    close(ps[0]);
    close(pc[1]);
    //inchid acum si restul
    //generez n
    srand(time(0));
    int n=0;
    n=rand()%(200-50)+50;
    while(1)
    {   if(n%2==0)
            write(ps[1],&n,sizeof(int));
        else
        {
            n--;
            write(ps[1],&n,sizeof(int));
        }
        read(pc[0],&n,sizeof(int));
        printf("[PARINTE] Am citit %d\n",n);
        if(n<5)
            break;
        sleep(1);
    }
    close(ps[1]);
    close(pc[0]);
    wait(NULL);

    return 0;
}