#include<stdio.h>
int main()
{
	int i,count;
	char ch;
	count = 0;
	ch = 'a';
	for(i=40;i<=127;i++)
	{
		ch = i;
		if(count%10!=9)
			printf("%c %d\t",ch,i);
		else
			printf("%c %d\n",ch,i);
		count++;
	}
	return 0;
}
