#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
	void *addr;
	key_t key;
	key=(key_t)2004;
	int shmid;
	shmid=shmget(key,1000,0666);
	if(shmid<0)
	{
		perror("shmget");
	}
	addr=shmat(shmid,NULL,0);
	char *val=(char*)addr;
	printf("Value for shmclient:%d is %s\n",getpid(),val);
	strcpy(val,"response");
	shmdt(&addr);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
	
	
