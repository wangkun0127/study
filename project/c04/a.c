#include <stdio.h>
int main()
{
	int num1 = 0,num2 = 0,num3 = 0,i = 0;
	printf("请输入一个五位数的整数：");
	scanf("%d",&num1);
	getchar();
	for(i=0;i<5;i++)
	{
		num3=num1%10;
		num1=num1/10;
		num2=num2*10+num3;
		/*printf("%d",num3);
		if(num1==0)
		{
			flag = 1;
			printf("\n");
		}*/
	}
	printf("%d\n",num2);
	return 0;
}
