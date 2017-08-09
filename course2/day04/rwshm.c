#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>//errno
int main(int argc,char *argv[])
{
	int shmid=-1;
	shmid=shmget(0x1024,4096,IPC_CREAT|0664);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}
	printf("shmid=%d\n",shmid);
	void *addr = NULL;
	addr = shmat(shmid,NULL,0);
	if((void *)-1==addr)
	{
		perror("shmat");
		return -1;
	}
	char *pMsg="欢迎来到上海";
	//sprintf((char *)addr,"%s",pMsg);
	//strcpy((char *)addr,pMsg);
	//memcpy(addr,pMsg,strlen(pMsg));
	char caMsg[64]={'\0'};
//	strcpy(caMsg,(char *)addr);
	sscanf((char *)addr,"%s",pMsg);
	printf("msg:%s\n",caMsg);
	while(1)
	{}

	shmdt(addr);
	printf("Hello World!\n");
	return 0;
}
