#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <signal.h>

pid_t pid;

void waiter(int sig)
{
	if(SIGINT==sig)
	{
		printf("客人来了...\n");
		sleep(1);
		printf("客人点菜...\n");
		sleep(1);
		kill(pid,SIGUSR1);
	}
	else if(SIGUSR2==sig)
	{
		printf("服务员端菜上菜...\n");
	}
	else if(SIGTSTP==sig)
	{
		printf("客人吃完饭...\n");
		sleep(1);
		printf("服务员买单...\n");
		sleep(1);
	}
	else if(SIGQUIT==sig)
	{
		printf("下班时间到啦...\n");
		sleep(1);
		printf("服务员下班...\n");
		sleep(1);
		kill(pid,SIGALRM);
	}
}
void cook(int sig)
{
	if(SIGUSR1==sig)
	{
		printf("厨师做菜...\n");
		sleep(1);
		printf("通知服务员端菜...\n");
		sleep(1);
		kill(getppid(),SIGUSR2);
	}
	else if(SIGALRM==sig)
	{
		printf("厨师下班...\n");
	}
}

int main(void)
{
	pid = fork();
	if(pid>0)
	{
		signal(SIGINT,waiter);
		signal(SIGUSR2,waiter);
		signal(SIGTSTP,waiter);
		signal(SIGQUIT,waiter);
		signal(SIGCHLD,waiter);
		while(1)
		{
			pause();
		}
	}
	else if(0==pid)
	{
		signal(SIGUSR1,cook);
		signal(SIGALRM,cook);
		signal(SIGINT,SIG_IGN);
		signal(SIGQUIT,SIG_IGN);
		signal(SIGTSTP,SIG_IGN);
		//printf("厨师下班\n");
		//sleep(1);
		//kill(getpid(),SIGALRM);
		while(1)
		{
			pause();
		}
	}
	else if(-1==pid)
	{
		perror("fork");
		return -1;
	}



	return 0;
}
