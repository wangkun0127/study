#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	int index = 0;
	printf("1-->黄山菜饭\n");
	printf("2-->河南拉面\n");
	printf("3-->沙县国际\n");
	printf("4-->东北水饺\n");
	printf("5-->不吃饭\n");
	
	index = rand()%5 + 1;
	switch(index)
	{
		case 1:
			printf("系统已帮您选择：1-->黄山菜饭\n");
			break;
		case 2:
			printf("系统已帮您选择：2-->河南拉面\n");
			break;
		case 3:
			printf("系统已帮您选择：3-->沙县国际\n");
			break;
		case 4:
			printf("系统已帮您选择：4-->东北水饺\n");
			break;
		case 5:
			printf("系统已帮您选择：5-->不吃饭\n");
			break;
	}
	return 0;
}
