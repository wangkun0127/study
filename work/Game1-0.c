#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned)time(NULL));
	int i = 0,d =  0;
	char b = '\0';
	int p[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int c[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	while(1)
	{
		system("clear");
		printf("可选择对战方式：\n");
		printf("\t1 --> 进攻\n");
		printf("\t2 --> 撤退\n");

		int life=0;
		printf("玩家请选择对战方式：");

		scanf("%c",&b);
		while(getchar() != '\n');

		switch(b)
		{
			case '1':
				//用户进攻
				for(i=0;i<3;i++)
				{
					d=rand()%15;
					c[d]=0;
				}
				//判断电脑
				life =0;
				for(i=0;i<15;i++)
				{
					life += c[i];
				}
				printf("电脑生命值为：%d\n",life);
				if(life==0)
				{
					printf("玩家获胜！\n");
					exit(1);
				}
				//电脑反击
				for(i=0;i<3;i++)
				{
					d=rand()%15;
					p[d]=0;
				}
				//判断用户
				life =0;
				for(i=0;i<15;i++)
				{
					life += p[i];
				}
				printf("玩家生命值为：%d\n",life);
				if(life==0)
				{
					printf("电脑获胜！\n");
					exit(1);
				}
				break;
			case '2':
				if(rand()%4==0)
				{
					printf("撤退成功！\n");	
				}
				else
				{
					//显示玩家生命值
					life =0;
					for(i=0;i<15;i++)
					{
						life += c[i];
					}
					printf("电脑生命值为：%d\n",life);
					//电脑追击
					for(i=0;i<3;i++)
					{
						d=rand()%15;
						p[d]=0;
					}
					//判断用户
					life =0;
					for(i=0;i<15;i++)
					{
						life += p[i];
					}
					printf("玩家生命值为：%d\n",life);
					if(life==0)
					{
						printf("电脑获胜！\n");
						exit(1);
					}
				}
				break;
			default:
				printf("输入错误！");
		}
		printf("按回车键继续");
		while(getchar() != '\n');
	}
	return 0;
}

