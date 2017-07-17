#include <stdio.h>
int main()
{
	float sum1 = 0.0,sum2 = 0.0,num = 0.0;
	int i = 0;

	printf("请输入10个数:");
	for(i=1;i<11;i++)
	{
		scanf("%f",&num);
		getchar();
		if(num>=0)
			sum1 = sum1 + num;
		else
			sum2 = sum2 + num;
	}
	printf("所有正数之和为：%.2f,所有负数之和为：%.2f\n",sum1,sum2);
	return 0;
}
