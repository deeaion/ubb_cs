#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
int main(int argc,char **argv)
{char* nume=argv[1];
int fd=open(nume,O_RDONLY);
if(fd==-1)
{perror("open()");
        exit(EXIT_FAILURE);}
	int sum=0;
	read(fd,&sum,sizeof(int));
	close(fd);
printf("Sum is %d\n",sum);
remove(nume);
return 0;
}
