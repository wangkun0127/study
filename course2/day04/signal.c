#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void handle(int sig)
{
	if(SIGINT==sig)
	{
		printf("catched sigint\n");
	}
}
int main(void)
{
	//ctrl+c:SIGINT
	//设置信号的处理动作
	signal(SIGINT,handle);
	while(1)
	{
		printf("this is main while\n");
		sleep(1);
	}
	return 0;
}
