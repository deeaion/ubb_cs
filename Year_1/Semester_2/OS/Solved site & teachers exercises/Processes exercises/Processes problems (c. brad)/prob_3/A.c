#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc,char **argv)
{	char* nume=argv[1];
	char file_name[50];
	int fi=mkfifo(nume,0666);
	if(fi==-1)
		{perror("mkfifo()");
        	exit(EXIT_FAILURE);}
	printf("Dati nume fisier:");
	scanf("%s",file_name);
	printf("\n");
	FILE* file;
	file=fopen(file_name,"r");//to close
	if(file==NULL)
	{perror("fopen()");
	exit(EXIT_FAILURE);}
	int pd[2];
	int fd=open(nume,O_WRONLY);//to close
	if(fd==-1)
	{fclose(file);
	perror("open()");
        	exit(EXIT_FAILURE);}
	int p=pipe(pd);//to close
	if(p==-1)
	{perror("pipe()");
        fclose(file);
        close(fd);
        exit(EXIT_FAILURE);}
	int pid=fork();
	if(pid==-1)
	{perror("fork()");
        fclose(file);
        close(fd);
        exit(EXIT_FAILURE);}
if(pid==0)
{	int gata=0;
	int citite=0;
	int nr=0;
int sum=0;
read(pd[0],&nr,sizeof(int));
int nr_v=nr;
close(pd[1]);//closed write
while(nr)
	{ 
		int n=0;
		read(pd[0],&gata,sizeof(int));
  		if(!gata)
  		{
			read(pd[0],&citite,sizeof(int));
			read(pd[0],&n,sizeof(int));
			if(n%2==1)
			{
				sum+=n;
			}
  		}
  		else
		{break;
			}
  		nr--;
		}
	close(pd[0]);//closed read
	if(nr_v>citite)
		printf("WARNING: found only %d",citite);
	write(fd,&sum,sizeof(int));
	fclose(file);
	exit(0);
}


//sunt in p1 aka proces parinte
close(pd[0]);//incid read
int nr=0;
printf("Dati cate numere sa fie citite din fisier: ");
scanf("%d",&nr);
write(pd[1],&nr,sizeof(int));
int citite=0;
int gata=0;
while(!feof(file))
{	if(citite!=nr)
	{	int n=0;
		int s=fscanf(file,"%d",&n);
//	write(pd[1],&gata,sizeof(int));
		if(s&&!feof(file)&&nr)
			{citite++;
			write(pd[1],&gata,sizeof(int));
			write(pd[1],&citite,sizeof(int));
			write(pd[1],&n,sizeof(int));
			}
		else
		{	gata=1;
			write(pd[1],&gata,sizeof(int));
			break;
			}
	}
	else
	{
	 gata=1;
                        write(pd[1],&gata,sizeof(int));
                        break;}

}

wait(NULL);
close(pd[1]);
close(fd);
fclose(file);
return 0;}
