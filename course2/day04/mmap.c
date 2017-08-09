#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>//errno
int main(int argc,char *argv[])
{
	void *addr=NULL;
	int fd=-1;
	fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	//1:NULL表示让系统自动映射到内存的合适位置
	//2：存储空间的大小
	addr=mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(MAP_FAILED==addr)
	{
		perror("mmap");
		return -1;
	}
	char *pData="北京欢迎你";
	sprintf((char *)addr,"%s",pData);
	close(fd);
	munmap(addr,1024);
	printf("Hello World!\n");
	return 0;
}
