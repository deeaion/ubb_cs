#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char** argv)
{char *nume_fifo=argv[1];
int fd=open(nume_fifo,O_RDONLY);
if(fd==-1)
{perror("open()");
exit(EXIT_FAILURE);
        }
char vocale[]={'A','E','I','O','U'};
int i=0;
while(i<5)
	{	int n=0;
		read(fd,&n,sizeof(int));
		printf("Vowel %c is found %d.\n",vocale[i],n);
		i++;
	}
close(fd);
remove(nume_fifo);
return 0;}
