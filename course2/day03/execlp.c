#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>//errno
int main(int argc,char *argv[])
{
	execlp("gedit","gedit","./execlp.c",NULL);

	//printf("Hello World!\n");
	return 0;
}
