#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>//errno
typedef struct student
{
	int id;
	char caName[32];
	float score;
}STU;
int main(int argc,char *argv[])
{
	int srcfd=-1;
	//O_CREAT:若文件不存在，则以指定的权限创建文件
	srcfd=open(argv[1],O_RDONLY|O_CREAT,0664);
	if(-1==srcfd)
	{
		printf("errno=%d,err:%s\n",errno,strerror(errno));
		return -1;
	}
	printf("打开文件成功\n");
	STU tmp;
	int ret=-1;
	while(1)
	{
		ret=read(srcfd,&tmp,sizeof(STU));
		if(-1==ret||0==ret)
		{
			break;
		}
		printf("id:%d\tname:%s\tscor:%.2f\n",tmp.id,tmp.caName,tmp.score);
	}
//	write(srcfd,stu,sizeof(stu));
	/*if(-1==ret)
	{
		perror("read");
		return -1;
	}
	else if(0==ret)
	{
		return 0;
	}
	printf("读到%ld字节的数据：%s\n",ret,caBuf);
*/
	close(srcfd);
	return 0;
}
