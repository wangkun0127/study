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
	pid_t pid = -1;
	char caRealCommand[16]={'\0'};
	char caCommand[128]={'\0'};
	char caArg[32]={'\0'};
	char caProject[64]={'\0'};
	char *p=NULL;
	char *q=NULL;
	char *m=NULL;
	while(1)
	{
		memset(caCommand,'\0',32);
		memset(caRealCommand,'\0',16);
		memset(caArg,'\0',32);
		memset(caProject,'\0',64);
		
		printf("MYTERM $ \n");
		read(STDIN_FILENO,caCommand,128);
		p=strchr(caCommand,'\n');
		if(NULL!=p)
		{
			*p='\0';
		}
		else
		{
			while('\n'!=getchar());
			{}
		}
		p=strchr(caCommand,' ');
		if(NULL!=p)
		{
			strncpy(caRealCommand,caCommand,p-caCommand);
		}
		while(1)
		{
			p=strchr(caCommand,'-');
			if(NULL!=p)
			{
				q=strchr(p,' ');
				if(NULL!=q)
				{
					strncat(caArg,p,q-p);
					strcat(caArg," ");
				}
				else if(NULL==q)
				{
					strcat(caArg,p);
				}
				else
				{
					break;
				}
				p++;
			}
		}
		p=strchr(caCommand,' ');
	//	q=strchr(caCommand,'-');
		if(NULL!=p)
		{
			while(1)
			{
				q=p+1;
				if(' '==*p&&'-'!=*q)
				{
					m=strchr(q,' ');
					if(NULL!=m)
					{
						strncat(caProject,q,m-q);
						strcat(caProject," ");
						p=m;
					}
					else
					{
						strcat(caProject,q);
					}
				}
				else
				{
					p++;
				}
				if('\0'==*p)
				{
					break;
				}
			}
			
		}
		/*if(0==strcmp("exit",caCommand))
		{
			break;
		}
		pid=fork();
		if(pid>0)
		{
			wait(NULL);
		}
		else if(0==pid)
		{
			execlp(caCommand,caCommand,NULL);
			break;
		}
		else if(-1==pid)
		{
			perror("fork");
			break;
		}*/
	}

	printf("Hello World!\n");
	return 0;
}
