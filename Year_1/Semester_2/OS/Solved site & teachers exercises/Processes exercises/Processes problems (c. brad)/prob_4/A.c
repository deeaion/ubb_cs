#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char** argv)
    {
    char* nume_fifo=argv[1];
    int res=mkfifo(nume_fifo,0666);
    if(res==-1)
	    {perror("mkfifo()");
	    exit(EXIT_FAILURE);}
    int fd=open(nume_fifo,O_WRONLY);
    if(fd<1)
	    {perror("open()");
        exit(EXIT_FAILURE);
	    }

    //printf("%d",pid);
    char nume[50];
    printf("Dati nume file:");
    scanf("%s",nume);
    printf("\n");
    FILE* file=fopen(nume,"r");
    if(file==NULL)
    {perror("fopen()");
        exit(EXIT_FAILURE);
    }
    int pd[2];
    int f=pipe(pd);
    int pid=fork();
    if(pid==-1)
     {perror("fork");
        exit(EXIT_FAILURE);}
    if(f==-1)
	    {perror("pipe");
        exit(EXIT_FAILURE);}

	if(pid==0)
	{//sunt in p2
	//p2 doar citeste
		close(pd[1]);
		char c='\0';
        read(pd[0],&c,sizeof(char));
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
        {	printf("[CHILD] %c is a letter.\n",c);
        }
        else if(c>='0'&&c<='9')
        {       printf("[CHILD] %c is a digit.\n",c);
        }
        else
        {       printf("[CHILD] %c is neither a digit nor a letter.\n",c);
        }
        write(fd,&c,sizeof(char));
        close(pd[0]);
        fclose(file);
        exit(0);}
//sunt in p1
	//printf("AAAAAAAAAAAAAAAAAAAAAAAA");
    close(pd[0]);
    int n;
    printf("Dati nr: ");
    scanf("%d",&n);
    int count=0;
    char c='\0';
    while(!feof(file))
    {
        int suc=fscanf(file,"%c",&c);
        if(suc==-1)
            break;
        count++;
        if(count==n)
            break;
    }
    if(count<n)
        printf("[PARENT] THERE WHERE only %d characters found. So the last one was given\n",count);
    write(pd[1],&c,sizeof(char));
    close(pd[1]);
    wait(NULL);
    close(fd);
    fclose(file);
    return 0;}
