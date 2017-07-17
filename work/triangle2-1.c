#include <stdio.h>
int main()
{
	int i = 0,j = 0;
	for(i=1;i<8;i++)
	{
		for(j=7;j>i;j--)
		{
			printf(" ");
		}
		for(j=0;j<(i*2-1);j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
