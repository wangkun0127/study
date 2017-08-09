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
	int fd =open(argv[1],O_RDWR|O_CREAT,0664);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	char caBuf[4096]={'\0'};
	pid_t pid= -1;
	pid=fork();

	if(pid>0)//父进程
	{
		while(1)
		{
			memset(caBuf,'\0',siaeof(caBuf));
			getStrFromSTIDIN(caBuf,4096);
			write(fd,caBuf,strlen(caBuf));
			if(0==strcmp("exit",caBuf))
			{
				break;
			}
		}
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
