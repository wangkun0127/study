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
	//参数一：要打开的文件
	//参数二：O_RDONLY表示以只读的方式打开文件
	//参数二：O_WRONLY表示以只写的方式打开文件
	//参数二：O_RDWR表示以可读可写的方式打开文件
	fd=open(argv[1],O_RDONLY);
	//fd=open(argv[1],O_WRONLY);
	//fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		printf("errno=%d,err:%s\n",errno,strerror(errno));
		return -1;
	}
	printf("打开文件成功\n");
	close(fd);
	return 0;
}
