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
	char *pMsg="AABBCC";
	ret = write(pipefd[1],pMsg,strlen(pMsg));
	if(ret==-1)
	{
		perror("write");
		return -1;
	}
	char caMsg[64]={'\0'};
	ret = read(pipefd[0],caMsg,64);
	if(ret>0)
	{
		//将数据显示在标准输出
		write(STDOUT_FILENO,caMsg,ret);
		putchar('\n');
	}

	printf("Hello World!\n");
	return 0;
}
