#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char** argv)
{char* nume_fifo=argv[1];
int fd=open(nume_fifo,O_RDONLY);
if(fd<1)
        {perror("open()");
        exit(EXIT_FAILURE);
        }
char c;
read(fd,&c,sizeof(char));
printf("THE ASCII OF %c is %d\n",c,c);
close(fd);
remove(nume_fifo);
return 0;}
