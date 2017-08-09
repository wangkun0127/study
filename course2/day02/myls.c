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
	int ret = -1;
	DIR *dir=opendir(argv[1]);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	struct dirent *pdirent=NULL;
	while(1)
	{
		pdirent=readdir(dir);
		if(NULL!=pdirent)
		{
			if(0==strncmp(".",pdirent->d_name,1))
			{
				continue;
			}
			printf("%s\t",pdirent->d_name);
			switch(pdirent->d_type)
			{
				case DT_DIR:
					printf("is a directory\n");
					break;
				case DT_REG:
					printf("is a reguler file\n");
					break;
				default:
					printf("is a unknow type\n");
					break;
			}
		}
		else
			break;
	}
	putchar('\n');
	printf("Hello World!\n");
	return 0;
}
