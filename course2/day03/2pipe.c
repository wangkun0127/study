#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>//errno
int main(int argc,char *argv[])
{
	int pipefd[2]={0};
	int ret = -1;
	//创建管道，若成功则会将管道读写接口的文件描述符放入数组
	//写端文件描述符放入pipefd[1]中
	//读端文件描述符放入pipefd[0]中
	ret = pipe(pipefd);
	if(-1==ret)
	{
		perror("pipe");
		return -1;
	}
	//创建子进程
	//通过管道实现父子通信
	pid_t pid = fork();
	if(pid>0)//parent
	{
		char caMsg[64]={'\0'};
		while(1)
		{
			printf("父进程输入：\n");
			memset(caMsg,'\0',sizeof(caMsg));
			read(STDIN_FILENO,caMsg,64);
			write(pipefd[1],caMsg,strlen(caMsg));
		}
	}
	else if(0==pid)//child
	{
		char caMsg[64]={'\0'};
		while(1)
		{
			memset(caMsg,'\0',64);
			read(pipefd[0],caMsg,64);
			printf("子进程显示数据：\n");
			write(STDOUT_FILENO,caMsg,strlen(caMsg));
		}
	}
	else if(-1==pid)//error
	{
		perror("fork");
		return -1;
	}
	printf("Hello World!\n");
	return 0;
}
