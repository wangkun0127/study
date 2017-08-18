#include <stdio.h>
int main()
{
	//定义变量
	int intSize = sizeof(int);
	int floatSize = sizeof(float);
	int doubleSize = sizeof(double);
	int charSize = sizeof(char);
	//输出变量值
	printf("基本数值类型在内存所占空间：\n int: %d, float: %d, double: %d, char: %d\n",intSize,floatSize,doubleSize,charSize);
	return 0;
}
