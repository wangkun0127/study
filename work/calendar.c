#include <stdio.h>
int main()
{
	int year = 1900,month = 1,day = 0;
	int i = 0,num = 0,j = 0,median = 0,sum = 0;
	char ch = '*';

	printf("请输入年，月：");
	scanf("%d%d",&year,&month);
	getchar();
	num = year + 1;
	for(i=1900;i<num;i++)
	{
		if(i!=year)
		{
			if((i%4==0 && i%100!=0)||i%400==0)
				sum += 366;
			else
				sum += 365;
		}
		else
		{
				for(j=0;j<month;j++)
				{
					if(j==0||j==2||j==4||j==6||j==7||j==9||j==11)
					{
						sum += 31;
						day = 31;
					}
					else if(j==1)
					{
						if((i%4==0 && i%100!=0)||i%400==0)
						{
							sum += 29;
							day = 29;
						}
						else
						{
							sum += 28;
							day = 28;
						}
					}
					else
						sum += 30;
						day = 30;
				}
		}
	}
	/*printf("%d",sum);*/
	printf("-------------------------------------------------------------------\n");
	printf("%30c万年历%c\n\n",ch,ch);
	printf("%12d 年 %d 月\n\n",year,month);
	printf("\tSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	printf("-------------------------------------------------------------------\n");
	sum -= day;
	median = (sum+1) % 7;
	switch(month)
	{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
	 	case 10 :
		case 12 :
			for(i=1;i<32;i++)
			{
				if(i==1){
					for(j=0;j<median+1;j++)
					{
						printf("\t");
					}
					printf("%d",i);
					median++;
				}else
				{
					printf("\t%d",i);
					median++;
				}
				if(median%7==0)
					printf("\n");
			}
			break;
		case 4 :
		case 6 :
		case 9 :
		case 11 :
			for(i=1;i<31;i++)
			{
				if(i==1){
					for(j=0;j<median+1;j++)
					{
						printf("\t");
					}
					printf("%d",i);
					median++;
				}else
				{
					printf("\t%d",i);
					median++;
				}
				if(median%7==0)
					printf("\n");
			}
			break;
		case 2:
			if((year%4==0 && year%100!=0)||year%400==0)
			{
			for(i=1;i<30;i++)
			{
				if(i==1){
					for(j=0;j<median+1;j++)
					{
						printf("\t");
					}
					printf("%d",i);
					median++;
				}else
				{
					printf("\t%d",i);
					median++;
				}
				if(median%7==0)
					printf("\n");
			}
			}
			else
			{
			for(i=1;i<29;i++)
			{
				if(i==1){
					for(j=0;j<median+1;j++)
					{
						printf("\t");
					}
					printf("%d",i);
					median++;
				}else
				{
					printf("\t%d",i);
					median++;
				}
				if(median%7==0)
					printf("\n");
			}
			}
			break;
		}
	printf("\n");
	return 0;
}
