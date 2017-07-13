#include<stdio.h>
int main()
{
	int a = 2;
	int b = 8;
	int c = 0;
	c = a+ (b+=2);
	printf("b= %d\nc= %d\n",b,c);

	return 0;
}
