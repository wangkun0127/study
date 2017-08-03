#include<stdio.h>
int main()
{
	float a = 0, b = 0;
	char ch ='a';
	printf("请输入要计算的方程式：");
	scanf("%f%c%f",&a,&ch,&b);
	getchar();
	switch(ch)
	{
		case'+':
			printf("你要求的两数之和 %.2f %c %.2f =%.2f\n",a,ch,b,a+b);
			printf("恭喜你运算完成！\n");
			break;
		case'-':
			printf("你要求的两数之和 %.2f %c %.2f =%.2f\n",a,ch,b,a-b);
			printf("恭喜你运算完成！\n");
			break;
		case'*':
			printf("你要求的两数之和 %.2f %c %.2f =%.2f\n",a,ch,b,a*b);
			printf("恭喜你运算完成！\n");
			break;
		case'/':
			switch((int)b)
			{
				case 0:
					printf("你输入的除数为0,请重新输入！\n");
					break;
				default:
					printf("你要求的两数之和 %.2f %c %.2f =%.2f\n",a,ch,b,a/b);
					printf("恭喜你运算完成！\n");
					break;
			}
			break;
		default:
			printf("你输入有误请重新输入！\n");
			break;
	
	}
	return 0;
}
