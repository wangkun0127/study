#include <stdio.h>
int main()
{
	int num1 = 0,flag = 1,num3 = 0;
	printf("请输入一个任意位数的整数：");
	scanf("%d",&num1);
	getchar();
	while(flag)
	{
		num3=num1%10;
		num1=num1/10;
		printf("%d",num3);
		if(num1==0)
		{
			flag = 0;
			printf("\n");
		}
	}
	return 0;
}
