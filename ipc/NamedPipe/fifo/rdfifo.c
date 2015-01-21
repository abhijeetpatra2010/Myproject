#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{	
	int fd;
	if(mkfifo("fifo1",0666)==-1)
		perror("mkfifo");
	fd=open("fifo1",O_RDWR);
	while(1)
	{
		char rdbuf[128];
		printf("Writing to read\n");
		read(fd,rdbuf,128);
		printf("%s\n",rdbuf);
	}
}
		
