#include <stdio.h>
int main()
{
	int i = 0,j = 0,num = 0,num1 = 0;
	printf("请输入要打印菱形的奇行数（n>2）:");
	scanf("%d",&num);
	getchar();
	num = (num + 3)/2;
	num1 = num - 1;
	for(i=1;i<num;i++)
	{
	/*	for(j=num1;j>i;j--)
		{
			printf(" ");
		}*/
		for(j=0;j<(i*2-1);j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	num = num1-1;
	for(i=num;i>0;i--)
	{
	/*	for(j=num1;j>i;j--)
		{
			printf(" ");
		}*/
		for(j=0;j<(i*2-1);j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}
