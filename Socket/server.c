#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netinet/ip.h>
int main()
{
	int sockid;
	char rdbuf[128];int len;
	struct sockaddr_in serv_addr,client_addr;
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	if(sockid<0)
	{
		perror("socket");
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("0.0.0.0");
	serv_addr.sin_port=htons(2345);
	if((bind(sockid,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))<0)
	{
		perror("bind");
	}
	printf("Waiting\n");
	len=sizeof(serv_addr);
	while(1)
	{
		printf("Message returned from client:\n");
		recvfrom(sockid,&rdbuf,sizeof(rdbuf)-1,0,(struct sockaddr*)&serv_addr,0);
		printf("Received:%s\n",rdbuf);
	}
}

	
	
		
