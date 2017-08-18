#include <stdio.h>
int main()
{
	int year = 0;
	printf("请输入一个年份：");
	scanf("%d",&year);
	getchar();

	if((year % 4 == 0 && year % 100 != 0)||year % 400 ==0)
		printf("你输入的%d年是一个闰年\n",year);
	else
		printf("你输入的%d年是一个平年\n",year);

	return 0;
}
