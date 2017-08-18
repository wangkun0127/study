#include <stdio.h>
int main()
{
	int i = 0,num = 0;
	int sum = 0;
	printf("请输入你想计算的数:");
	scanf("%d",&num);
	getchar();
	num++;
	for(i=1;i<num;i++)
	{
		sum += i;
	}
	printf("sum : %d\n",sum);

	return 0;
}
