#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>//errno
int main(int argc,char *argv[])
{
	int num = 0;
	char caMsg[32] = {'\0'};
	
	pid_t pid= -1;
	pid=fork();

	if(pid>0)//父进程
	{
		num=2;
		strcpy(caMsg,"this is parent");
	}
	else if(pid==0)//子进程
	{
		num=6;
		strcpy(caMsg,"this is sun");
	}
	else if(pid==-1)//程序出错
	{
		
	}
	for(;num>=0;num--)
	{
		printf("msg:%s\n",caMsg);
		sleep(1);
	}
	//printf("创建%s成功\n",argv[1]);

	return 0;
}
