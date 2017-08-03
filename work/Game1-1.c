#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void regi();
void mygets(char *str,int size);
void judge(char *n1,char *n2,char *na1,char *na2);
void cycle(int *p4,int *c4);
char interface();
void change(int *p5,int *c5,char cha);
void userAttack(int *c1);
void comAttack(int *p2);
void userRetreat(int *p3,int *c3);

int main()
{
	srand((unsigned)time(NULL));
	int p[15] = {0},c[15] = {0};
	regi();
	cycle(p,c);
	return 0;
}

void regi()
{
	char num1[10] = {'\0'},num2[10] = {'\0'},name1[20] = {'\0'},name2[20] = {'\0'};
	printf("用户请注册：\n\t姓名：");
	mygets(name1,20);
	printf("\t密码：");
	mygets(num1,10);
	judge(num1,num2,name1,name2);
}
void judge(char *n1,char *n2,char *na1,char *na2)
{
	while(1)
	{
		printf("用户请登录：\n\t姓名：");
		mygets(na2,20);
		printf("\t密码：");
		mygets(n2,10);
		if(strlen(na1)==strlen(na2)&&strlen(n1)==strlen(n2)&&strcmp(na1,na2)==0&&strcmp(n1,n2)==0)
		{
		
			printf("确认登录！");
			break;
		}
		else{
			printf("密码或姓名错误，请重新登录！\n");
		}
	}
}
void mygets(char * str,int size)
{
	int i=0;
	for(i=0;i<size-1;i++)
	{
		str[i]=getchar();
		if(str[i]=='\n')
		{
			break;
		}
	}
	str[i]='\0';
	if(i==size-1)
	{
		while(getchar() != '\n');
	}
}
void cycle(int *p4,int *c4)
{
	while(1)
	{
		system("clear");
		char chan=interface();
		printf("******************************\n");
		change(p4,c4,chan);
		printf("******************************\n");
		printf("按回车继续！");
		while(getchar() != '\n');
	}
}
char interface()
{
	char change='\0';
	printf("可选择对战方式：\n\t1-->进攻\n\t2-->撤退\n玩家请选择对战方式：");
	scanf("%c",&change);
	while(getchar() != '\n');
	return change;
}
void change(int *p5,int *c5,char cha)
{
	switch(cha)
	{
		case '1':
			userAttack(c5);
			comAttack(p5);
			break;
		case '2':
			userRetreat(p5,c5);
			break;
		default:
			printf("输入错误！\n");
	}
}
void userAttack(int *c1)
{
	int i=0,index=0,life=0;
	//用户进攻
	for(i=0;i<3;i++)
	{
		index=rand()%15;
		c1[index]=1;
	}
	//判断电脑
	life =0;
	for(i=0;i<15;i++)
	{
		life += c1[i];
	}
	life = 15-life;
	printf("电脑生命值为：%d\n",life);
	if(life==0)
	{
		printf("玩家获胜！\n******************************\n");
		exit(1);
	}
}
void comAttack(int *p2)
{
	int i=0,index=0,life=0;
	//电脑反击
	for(i=0;i<3;i++)
	{
		index=rand()%15;
		p2[index]=1;
	}
	//判断用户
	life =0;
	for(i=0;i<15;i++)
	{
		life += p2[i];
	}
	life = 15-life;
	printf("玩家生命值为：%d\n",life);
	if(life==0)
	{
		printf("电脑获胜！\n******************************\n");
		exit(1);
	}
}
void userRetreat(int *p3,int *c3)
{
	int i=0,life=0;
	if(rand()%2==0)
	{
		printf("撤退成功！\n");
	}
	else
	{
		//显示玩家生命值
		life =0;
		for(i=0;i<15;i++)
		{
			life += c3[i];
		}
		printf("电脑生命值为：%d\n",life);
		comAttack(p3);
	}
}
