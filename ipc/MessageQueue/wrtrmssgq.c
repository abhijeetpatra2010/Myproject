#include<sys/typesh>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf
{
	long int mtype;
	char rdbuf[128];
}
int main()
{
	char rdbuf[128];
	int id;
	int key=1;
	id=msgget(key,0666|IPC_CREAT|IPC_EXCL);
	printf("Enter the message:");
	scanf("%s",rdbuf);
	if(msgsnd(id,&msgbuf,sizeof(rdbuf)-1,0))
	{
		perror("msgsnd");
	}
	if(msgctl(id,IPC_RMID,0)==-1)
	{
		perror("msgctl");
	}
	return 0;
}
	
