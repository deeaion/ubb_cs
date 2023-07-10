#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv)
{char* nume_fifo=argv[1];
int cf=mkfifo(nume_fifo,0666);
if(cf==-1)
{	perror("mkfifo()");
	exit(EXIT_FAILURE);
	}
int fd=open(nume_fifo,O_WRONLY);
if(fd==-1)
{       perror("open()");
        exit(EXIT_FAILURE);
        }
int n=0;
printf("Dati nr: ");
scanf("%d",&n);
//printf("\n");
int i;
for(i=1;i<=n;i++)
{	if(n%i==0)
		{write(fd,&i,sizeof(int));
		sleep(1);		}
}

close(fd);

return 0;}
