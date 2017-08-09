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
typedef struct stu
{
	int id;
	char name[20];
	float score;
}STU;

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
	STU stu[5]={{1001,"小明",85},{1002,"小华",95},{1003,"小林",92},{1004,"小海",83},{1005,"小龙",76}};
	while(1)
	{
		memcpy(addr,stu,sizeof
				(stu));
		printf("id:%d,name:%s,score:%.2f\n",stu.id,stu.name,stu.score);
		adrr++;
		stu++;
	}
	shmdt(addr);
	printf("Hello World!\n");
	return 0;
}
