#include <stdio.h>
int main()
{
	int i = 0,sum = 0;
	for(i=1;i<101;i++)
	{
		if(i%10==6||i/10==6)
			sum = sum + i;
	}
	printf("1-100以内所有所有含6的数之和为：%d\n",sum);
	return 0;
}
