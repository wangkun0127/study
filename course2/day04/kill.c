#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
int main(void)
{
	int i=0;
	pit_t pid=atoi(argv[1]);
	while(1)
	{
		sleep(1);
		i++;
		if(5==i)
		{
			kill(pid,SIGKILL);
		}
	}
}
