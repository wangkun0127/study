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
	int ret=mkfifo("./myfifo",0664);
	printf("%d",ret);
	if(-1==ret)
	{
		perror("mkfifo");
		return -1;
	}
	printf("create named pipe ok\n");
	printf("Hello World!\n");
	return 0;
}
