#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	alarm(5);
	while(1)
	{
		printf("aaaaaaaaa\n");
		sleep(1);
	}
}
