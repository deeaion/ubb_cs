#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
int cmmdc(int a,int b)
	{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
	}
int main(int argc,char** argv)
	{
		char * nume_fifo=argv[1];
		int f=mkfifo(nume_fifo,0666);
		if(f<-1)
			{
				perror("mkfifo()");
				exit(EXIT_FAILURE);
			}
		int fd=open(nume_fifo,O_WRONLY);
		if(fd==-1)
			{
			perror("open()");
                                exit(EXIT_FAILURE);}
		int a,b;
		printf("Dati primul nr: ");
		scanf("%d",&a);
//		 write(fd,&a,sizeof(int));
		 printf("Dati al doilea nr: ");
                scanf("%d",&b);
		int d=cmmdc(a,b);
		 write(fd,&d,sizeof(int));
		close(fd);
	return 0;
	}
