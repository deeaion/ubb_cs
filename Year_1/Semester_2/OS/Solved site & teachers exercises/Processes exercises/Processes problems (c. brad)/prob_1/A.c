 #include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{ 	if(argc<1)
		{
			perror("Fifo name not given");
			exit(0);
		}
	char* name=argv[1];
	int created=mkfifo(name,0666);
	if(created<0)
	{
		perror("mkfifo()");
		exit(EXIT_FAILURE);
		}
	char fisier_name[50];
        printf("Dati nume fisier:");
	scanf("%s",fisier_name);
	FILE* file=fopen(fisier_name,"r");
	if(file==NULL)
	{
		perror("fopen()");
                exit(EXIT_FAILURE);
	}
	int fd=open(name,O_WRONLY);
	if(fd==-1)
	{
		 perror("open()");
                exit(EXIT_FAILURE);
	}
	while(!feof(file))
	{
		int n=0;
		int succ=fscanf(file,"%d",&n);
		if(succ&&!feof(file))
			write(fd,&n,sizeof(int));
	}
	fclose(file);
	close(fd);
	wait(0);
return 0;}
