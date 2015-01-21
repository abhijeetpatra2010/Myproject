#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key;
	key=1000;
	int shmid;
	shmid=shmget(key,100,IPC_CREAT|0666);
	if(shmid<0)
	{
		perror("shmget");
	}
	shmat(shmid,NULL,	
