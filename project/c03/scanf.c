#include <stdio.h>
int main()
{
	//定义变量
	float Chinese = 0 ,Math = 0,English = 0,sum = 0,avg = 0;
	//输入成绩
	printf("please input three classes of Chinese,Math,English:\n");
	scanf("%f%f%f",&Chinese,&Math,&English);
	//求出总分和平均分
	sum = Chinese + Math + English;
	avg = sum / 3.0;
	//输出结果
	printf("This sum :%.2f and avg : %.2f\n",sum,avg);
	return 0;
}
