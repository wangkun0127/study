#include<stdio.h>
int main()
{
	//定义变量
	char ch,ch1;
	//输入参数
	printf("请输入一个字母：");
	scanf("%c",&ch);
	//求值
	if('a'<=ch&&ch<='z')
		ch1 = ch - 32;
	else
		ch1 = ch + 32;
	//输出结果
	printf("对应的字母为：%c\n",ch1);
	return 0;
}
