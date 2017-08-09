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
	int fd=open("myfifo",O_RDWR);
	char caMsg[64]={'\0'};
	int ret=-1;
	int sign = 0;
	while(1)
	{
		if(0==sign)
		{
			memset(caMsg,'\0',sizeof(caMsg));
			ret=read(fd,caMsg,64);
			if(0==ret)
			{
				break;
			}
			printf("收到数据：\n");
			write(STDOUT_FILENO,caMsg,strlen(caMsg));
			sign=1;
		}
		else if(1==sign)
		{
			memset(caMsg,'\0',sizeof(caMsg));
			printf("请输入数据：\n");
			read(STDIN_FILENO,caMsg,64);
			write(fd,caMsg,strlen(caMsg));
			sign=0;
		}
		sleep(1);
	}
	printf("Hello World!\n");
	return 0;
}
