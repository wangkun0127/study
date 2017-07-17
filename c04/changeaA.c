#include <stdio.h>
int main()
{
	char ch = '\0';
	printf("请输入一个英文字母：");
	scanf("%c",&ch);
	getchar();
	if(ch <= 'z' && ch >= 'a')
		printf("你所输入的小写字母%c对应的大写字母为：%c\n",ch,ch-32);
	else if(ch <= 'Z' && ch >= 'A')
		printf("你所输入的大写字母%c对应的小写字母为：%c\n",ch,ch+32);
	else
		printf("你输入错误，请重新输入！\n");
	return 0;
}
