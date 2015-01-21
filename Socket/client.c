#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netinet/ip.h>

int main()
{
	int sockid;
	char wrbuf[128];int len;
	struct sockaddr_in serv_addr,client_addr;
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	if(sockid<0)
	{
		perror("socket");
	}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(2345);
	/*if((bind(sockid,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))<0)
	{
		perror("bind");
	}*/
	len=sizeof(client_addr);
	while(1)
	{
		printf("Enter a message to send:\n");
		scanf("%s",wrbuf);
		sendto(sockid,&wrbuf,len,0,(struct sockaddr*)&serv_addr,len);
		//printf("%s\n",rdbuf);
	}
}
	
	
		
