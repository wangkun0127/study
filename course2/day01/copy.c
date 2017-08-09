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
	int srcfd=-1;
	//O_CREAT:若文件不存在，则以指定的权限创建文件
	srcfd=open(argv[1],O_RDONLY);
	int destfd=-1;
	destfd=open(argv[2],O_WRONLY | O_CREAT,0664);
	if(-1==srcfd)
	{
		printf("errno=%d,err:%s\n",errno,strerror(errno));
		return -1;
	}
	printf("打开文件成功\n");
	
	char caBuf[4096]={'\0'};
	ssize_t ret =-1;
	while(1)
	{
		ret= read(srcfd,caBuf,sizeof(caBuf));
		if(-1==ret)
		{
			perror("read");
			break;
		}
		else if(0==ret)
		{
			printf("拷贝完成\n");
			break;
		}
		write(destfd,caBuf,ret);
	}

	close(srcfd);
	close(destfd);
	return 0;
}
