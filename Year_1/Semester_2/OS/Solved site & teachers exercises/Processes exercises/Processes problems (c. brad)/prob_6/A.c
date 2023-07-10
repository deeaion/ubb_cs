#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char** argv)
{char *nume_fifo=argv[1];
int cf=mkfifo(nume_fifo,0666);
if(cf==-1)
{perror("mkfifo()");
exit(EXIT_FAILURE);
	}
int fd=open(nume_fifo,O_WRONLY);
if(fd==-1)
{perror("open()");
exit(EXIT_FAILURE);
        }
int pd[2];
int suc=pipe(pd);
if(suc==-1)
{perror("pipe()");
exit(EXIT_FAILURE);
        }
int pid=fork();
if(pid==-1)
{perror("fork()");
exit(EXIT_FAILURE);
        }
if(pid==0)
{//sunt in p copil care doar citeste
  	close(pd[1]);
  	char file_path[100]="\0";
  	read(pd[0],file_path,sizeof(file_path));
  	printf("[COPIL] am citit this file_path %s\n",file_path);
	FILE* file=fopen(file_path,"r");
	if(file==NULL)
	{	perror("fopen()");
		close(pd[1]);
		exit(0);
		exit(EXIT_FAILURE);
        }
  	int vf[5];
  	for(int i=0;i<5;i++)
		{vf[i]=0;}
//A-> 0, E-> 1, I->2,O-> 3 ,U->4
  while(!feof(file))
	{	char c='\0';
		if(fscanf(file,"%c",&c)==-1)
			break;
		if(c=='A')
			vf[0]=vf[0]+1;
		 if(c=='E')
                        vf[1]=vf[1]+1;
		 if(c=='I')
                        vf[2]=vf[2]+1;
		 if(c=='O')
                        vf[3]=vf[3]+1;
		 if(c=='U')
                        vf[4]=vf[4]+1;
	}
	for(int i=0;i<5;i++)
		{write(fd,&vf[i],sizeof(int));
		}
fclose(file);
close(pd[0]);
exit(0);
}
close(pd[0]);
char file_path[100];
printf("Dati file_path:");
scanf("%s",file_path);
printf("\n");
write(pd[1],file_path,sizeof(file_path));
close(pd[1]);
close(fd);
return 0;	}
