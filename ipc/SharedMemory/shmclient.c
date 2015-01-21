#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
int main()
{
	void *addr;
	key_t key;
	key=(key_t)2000;
	int shmid;
	shmid=shmget(key,1000,0666);
	if(shmid<0)
	{
		perror("shmget");
	}
	addr=shmat(shmid,NULL,0);
	char *val=(char*)addr;
	strcpy(val,"RESPONSE");
	
	printf("PID for shmclient:%d\n",getpid());
	shmdt(&addr);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
	
	
