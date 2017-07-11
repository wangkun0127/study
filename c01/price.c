#include <stdio.h>
int main ()
{
	/*定义变量*/
	float sum,price1,price2,price3;
	/*给出三种商品的价格赋值*/
	price1 = 12.6;
	price2 = 13.2;
	price3 = 14.1;
	/*求出三种价格的和sum*/
	sum = price1 + price2 + price3;
	/*输出sum值*/
	printf("商品的总价为：%.2f\n",sum);
	return 0;
}
