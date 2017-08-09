#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>//errno
void cpRegFile(const char *dest,const char *src)
{
	if(NULL==dest||NULL==src)

}
void cpDirFile(const char *destDir,const char *srcDir)
{
	if(NULL==destDir||NULL==srcDir)
	{
		return;
	}
	mkdir(destDir,0777);

	DIR *pdir=opendir(srcDir);
	if(NULL==pdir)
	{
		perror("opendir");
		return;
	}
	char caSrcPathname[64]={'\0'};
	char caDestPathame[64]={'\0'};
	struct dirent *pdirent=NULL;
	while(1)
	{
		pdirent-readdir(pdir);
		if(NULL==pdirent)
		{
			break;
		}
		if(0==strcmp(".",pdirent->d_name)||0==strcmp("..",pdirent->d_name))
		{
			continue;
		}
		memset(caSrcPathname,'\0',64);
		memset(caDestPathname,'\0',64);
		strcpy(caSrcPathname,srcDir);
		strcat(caSrcPathname,"/");
		strcat(caSrcPathname,pdirent->d_name);
		strcpy(caDestPathname,destDir);
		strcat(caDestPathname,"/");
		strcat(caDestPathname,pdirent->d_name);
		printf("src:%s,deat:%s\n",caSrcPathname,caDestPathname);
		switch(pdirent->d_name)
		{
			case DT_REG:
				cpRegFile(caDestPathname,caSrcPathname);
				break;
			default:
				break;
		}

	}
}
int main(int argc,char *argv[])
{
	if(3!=argc)
	{
		printf("main arg is error\n");
		return -1;
	}
	char *p= strrchr(argv[1],'/');
	char caDestPathname[64]={'\0'};
	strcpy(caDestPathname,argv[2]);
	strcpy(caDestPathname,'/');
	if(NULL==p)
	{
		strcpy(caDestPathname,argv[1]);
	}
	else
	{
		p++;
		strcpy(caDestPathname,p);
	}
	cpDirFile(caDestPathname,argv[1]);

	printf("Hello World!\n");
	return 0;
}
