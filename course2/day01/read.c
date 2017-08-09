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
	int fd=-1;
	//O_CREAT:若文件不存在，则以指定的权限创建文件
	fd=open(argv[1],O_RDONLY | O_CREAT,0644);
	if(-1==fd)
	{
		printf("errno=%d,err:%s\n",errno,strerror(errno));
		return -1;
	}
	printf("打开文件成功\n");
	
	char caBuf[4096]={'\0'};
	ssize_t ret =-1;
	ret= read(fd,caBuf,sizeof(caBuf));
	if(-1==ret)
	{
		perror("read");
		return -1;
	}
	else if(0==ret)
	{
		return 0;
	}
	printf("读到%ld字节的数据：%s\n",ret,caBuf);

	close(fd);
	return 0;
}
