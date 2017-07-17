#include <stdio.h>
int main()
{
	int i = 0,j = 0,temp = 0,flag = 1;
	for(i=2;i<100;i++)
	{
		flag = 1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag = 0;
			}
			
		}
		if(flag==1)
		{
			printf("%d\t",i);
			temp++;
		}
		if(temp%10==0)
		{
			printf("\n");
		}
	}
	return 0;
}
