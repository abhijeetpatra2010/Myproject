#include<stdio.h>
#include<pthread.h>

int g=0;
void *thread1(void *p)
{
	g++;
	printf("sachin");
	sleep(2);
	printf("Value of G after incrment operation is:%d\n",g);
	pthread_exit((int*)1);
}
void *thread2(void *p)
{
	g++;
	pthread_exit((int *)2);
}
int main()
{	
	int ret1,ret2;
	pthread_t thr1,thr2;
	ret1=pthread_create(&thr1,NULL,(void *)&thread1,NULL);
	ret2=pthread_create(&thr2,NULL,(void *)&thread2,NULL);
	//phtrad_exit(0);
	pthread_join(thr1,NULL);
	pthread_join(thr2,NULL);
	printf("Thread1 returns :%d\n",ret1);
	printf("Thread2 returns :%d\n",ret2);
}

	
	
