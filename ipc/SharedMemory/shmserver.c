#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

int main()
{
	void *addr;
	key_t key=(key_t)2004;
	int shmid;
	shmid=shmget(key,2000,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("shmget");
	}
	addr=shmat(shmid,NULL,0);
	char *val=(char*)addr;
	strcpy(val,"REQUEST");
	system("./shmclient");
	printf("PID for shmserver:%d\n",getpid());
	shmdt(&addr);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
	
	
