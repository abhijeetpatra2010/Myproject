/* Program which will execute date and calender */

#include<unistd.h>
#include<stdio.h>
int main()
{
	if(fork()==0)
	{
		printf("Child PID: %d\n",getpid());
		printf("Executing date:.............\n");
		system("date");		
	}
	else
	{
		wait(0);
		printf("\n");
		printf("Parent PID: %d\n",getpid());
		printf("Executing calender:...............\n");
		system("cal");
	}
	return 0;
}
