#include<stdio.h>
int main()
{
	float a = 0, b = 0;
	char ch ='a';
	printf("请输入要计算的方程式：");
	scanf("%f%c%f",&a,&ch,&b);
	getchar();
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
	{

	if(ch == '+')
	{
		printf("你要求的两数之和 %.2f %c %.2f =%.2f\n",a,ch,b,a+b);
		printf("恭喜你运算完成！\n");
	}
	else if(ch == '-')
	{
		printf("你要求的两数之差 %.2f %c %.2f =%.2f\n",a,ch,b,a-b);
		printf("恭喜你运算完成！\n");
	}
	else if(ch == '*')
	{
		printf("你要求的两数之积 %.2f %c %.2f =%.2f\n",a,ch,b,a*b);
		printf("恭喜你运算完成！\n");
	}
	else if(ch == '/')
	{
		if(b == 0)
		{
			printf("你输入的除数不能为零，请重新运行程序输入！\n");
		}
		else if(b!=0)
		{
		printf("你要求的两数之商 %.2f %c %.2f =%.2f\n",a,ch,b,a/b);
		printf("恭喜你运算完成！\n");
		}
	
	}
	}
	else
	{
		printf("你输入的有误，请重新运行程序！");
	}
	return 0;
}
