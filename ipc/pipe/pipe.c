#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int p[2];
	pipe(p);
	if(fork())
	{
		char buf[128];
		printf("Enter a message:\n");
		scanf("%s",buf);
		write(p[1],buf,strlen(buf));
//		wait(0);
	}
	else
	{
		char rdbuf[128];
		printf("Waiting for response:\n");
		read(p[0],rdbuf,strlen(rdbuf));
		printf("%s",rdbuf);
	}
}
