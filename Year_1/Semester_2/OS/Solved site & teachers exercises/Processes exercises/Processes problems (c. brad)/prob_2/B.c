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
                char *nume_fifo=argv[1];
             
                int fd=open(nume_fifo,O_RDONLY);
                if(fd==-1)
                        {
                        perror("open()");
                                exit(EXIT_FAILURE);}
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
			{
				//sunt in procesul copil eu doar citesc
				close(pd[1]);
				printf("[COPIL] divizorii sunt: \n");
				//prelucrez
				while(1)
				{
					int term=0;
					int n=0;
					read(pd[0],&term,sizeof(int));
					if(!term)
						{
							read(pd[0],&n,sizeof(int));
							printf("%d ",n);
						}
					else
						{
						printf("\n");
						break;
						}
				}
				close(pd[0]);
				exit(0);
			}
		//sunt in parinte
		close(pd[0]);
		int n=0;
		read(fd,&n,sizeof(int));
//		printf("%d",&n);
		
		int term=0;
		for(int d=1;d<=n;d++)
			{
				if(n%d==0)
				{ 	 term=0;
					write(pd[1],&term,sizeof(int));
					write(pd[1],&d,sizeof(int));
				}
			}
		term=1;
		write(pd[1],&term,sizeof(int));
		close(pd[1]);
		wait(NULL);
		close(fd);
		remove(nume_fifo);
		return 0;}
