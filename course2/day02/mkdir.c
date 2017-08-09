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
	int ret=-1;
	char *p=argv[1];
	char caPathName[64]={'\0'};
	while(1)
	{
		p=strstr(p,"/");
	}
	printf("创建%s成功\n",argv[1]);

	return 0;
}
