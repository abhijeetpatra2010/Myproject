#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{	
	int fd;
	if(mkfifo("fifo1",0666)==-1)
		perror("mkfifo");
	fd=open("fifo1",O_RDWR);
	while(1)
	{
		char wrbuf[128];
		printf("Enter a message to communicate\n");
		scanf("%s",wrbuf);
		write(fd,wrbuf,128);
	}
}
		
