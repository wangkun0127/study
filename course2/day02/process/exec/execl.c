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
	//参数一：执行文件的路径
	//参数二：要执行的文件名
	//后续参数为文件执行时的参数
	//最后一个参数设置为NULL
	execl("/usr/bin/gedit","gedit","./execl.c",NULL);
	printf("hello world\n");
	return 0;
}
