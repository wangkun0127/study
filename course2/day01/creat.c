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
	//argv[1]:pathname
	//设置文件的访问权限
	fd=creat(argv[1],0664);
	if(-1==fd)
	{
		//将错误编号代表的错误信息返回
		printf("errno=%d,err:%s\n",errno,strerror(errno));
	}
	printf("创建%s成功\n",argv[1]);

	return 0;
}
