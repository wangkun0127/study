#include<stdio.h>
int main()
{
	/*
	//定义变量并赋初值
	float grade = 0;
	//输入参数
	printf("请输入成绩：");
	scanf("%f",&grade);
	getchar();
	//判断成绩并输出结果
	if(grade>=60)
	{
		printf("及格\n");
	}
	else
		printf("不及格\n");
	*/
	int num = 0;
	printf("请输入一个数字：");
	scanf("%d",&num);
	getchar();
	
	if(num % 3 ==0 ||num % 5 ==0 )
	{
		printf("这个数既能被3整除又能被5整除\n");
	}
	else if(num % 3 ==0)
	{
		printf("这个数能被3整除\n");
	}
	else if(num % 5 ==0)
	{
		printf("这个数能被5整除\n");
	}
	else
	{
		printf("这个数不能被整除\n");
	}
	return 0;
}
