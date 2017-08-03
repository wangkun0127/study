#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	int index = 0,flag=0,num = 0;

	printf("1-->剪刀\n");
	printf("2-->石头\n");
	printf("3-->布\n");
	
	printf("请输入你的选择：");
	scanf("%d",&num);
	getchar();

	index = rand()%3 + 1;
	flag = num - index;
	switch(index)
	{
		case 1:
			printf("计算机选择了：1-->剪刀\n");
			break;
		case 2:
			printf("计算机选择了：2-->石头\n");
			break;
		case 3:
			printf("计算机选择了：3-->布\n");
			break;
	}
	switch(flag)
	{
		case -2:
			printf("你赢了\n");
			break;
		case -1:
			printf("计算机赢了\n");
			break;
		case 0:
			printf("比赛平局\n");
			break;
		case 1:
			printf("你赢了\n");
			break;
		case 2:
			printf("计算机赢了\n");
			break;
	}
	return 0;
}
