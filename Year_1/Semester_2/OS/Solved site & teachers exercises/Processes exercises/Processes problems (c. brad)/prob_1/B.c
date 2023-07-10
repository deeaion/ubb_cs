 #include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char* argv[])
{       if(argc<1)
                {
                        perror("Fifo name not given");
                        exit(0);
                }
        char* name=argv[1];
        
        int fd=open(name,O_RDONLY);
        if(fd==-1)
        {
                 perror("open()");
                exit(EXIT_FAILURE);
        }
	int pd[2];
	int res=pipe(pd);
	if(res==-1)
	{
	 perror("pipe()");
                exit(EXIT_FAILURE);}
        int pid=fork();
	if(pid==-1)
	{
	 perror("fork()");
                exit(EXIT_FAILURE);}
	if(pid==0)
	{//procesul copil
	close(pd[1]);
	int d=2;
	int n=0;
	read(pd[0],&n,sizeof(int));
	printf("SUMA %d, DIVIZORI:",n);
	for(d=2;d<=n/2;d++)
	{
	if(n%d==0)
	printf("%d ",d);
	}
	printf("\n");
	close(pd[0]);
	exit(0);
	}
	//parinte
	close(pd[0]);
	int suma=0;
	while(1)
	{
		int n=0;
		int f=1;
		f=read(fd,&n,sizeof(int));
		 if(f==0)
                        { break;}
		printf("[PARINTE] AM CITI %d\n",n);
		suma+=n;
	
	}
	write(pd[1],&suma,sizeof(int));
    close(pd[1]);
	wait(NULL);


	close(fd);
	remove(name);
return 0;}
