#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
union semun
{
	int val;
	ushort *array;
};
int data;
struct sembuf sem_lock={0,-1,SEM_UNDO};
struct sembuf sem_unlock={0,1,SEM_UNDO};
key_t key=(key_t)2000;
void *reader(void *arg)
{
	int semid=semget(key,1,0);
	printf("Reader thread aquiring semaphore\n");
	semop(semid,&sem_lock,1);
	printf("Reader thread acquired semaphore\n");
	printf("Value is %d\n",data);
	semop(semid,&sem_unlock,1);
	printf("Reader thread released semaphore\n");
}
int main()
{
	pthread_t thr1;
	int semid=semget(key,1,IPC_CREAT|0666);
	if(semid<0)
	return 1;
	ushort initvalue[]={1,0};
	union semun init;
	init.array=initvalue;
	int ret=semctl(semid,0,SETALL,init);
	printf("Main thread aquiring semaphore\n");
	semop(semid,&sem_lock,1);
	printf("Main thread acquired semaphore\n");
	printf("Main thread creating reader thread");
	if(pthread_create(&thr1,NULL,(void*)&reader,NULL))
	{
		semctl(semid,IPC_RMID,0);
		printf("Error creating reader thread\n");
		return 1;
	}
	sleep(2);
	printf("Main thread changing the value\n");
	data=100;
	semop(semid,&sem_unlock,1);	
	printf("Main thread released semaphore\n");
	pthread_join(thr1,NULL);
	semctl(semid,IPC_RMID,0);
	return 0;
}
