#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv)
{char* nume_fifo=argv[1];
int fd=open(nume_fifo,O_RDONLY);
if(fd==-1)
{       perror("open()");
        exit(EXIT_FAILURE);
        }
int pd[2];
int suc=pipe(pd);
if(suc==-1)
{
	perror("pipe()");
        exit(EXIT_FAILURE);}
int pid=fork();
printf("pid %d\n",pid);
if(pid==-1)
	{perror("fork()");
        exit(EXIT_FAILURE);}
if(pid==0)
{//sunt in p2
  close(pd[1]);
  int s=0;
  read(pd[0],&s,sizeof(int));
  printf("[COPIL] Suma este %d.\n",s);
  close(pd[0]);
  exit(0);
	}
//proc parinte
close(pd[0]);
int s=0;
while(1)
{	int n=0;
 	if(read(fd,&n,sizeof(int))<=0)
		{break;}
	printf("[PROGRAM B] AM CITIT %d\n",n);
	s=s+n;
}
write(pd[1],&s,sizeof(int));
close(pd[1]);


close(fd);
remove(nume_fifo);
return 0;}
