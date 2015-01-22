#include<stdio.h>
#include<signal.h>
void isr(int n)
{
	printf("Interrupt Signal generated:\n");
}
int main()
{
	printf("Press CTRL-C:\n");
	signal(SIGINT,isr);
	while(1);
}

