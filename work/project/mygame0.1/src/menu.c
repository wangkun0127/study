
#include <stdio.h>
#include <stdlib.h>
#include "../include/account.h"
#include "../include/include.h"


void menu()
{
	char name[NAME_NUM] = {'\0'};
	char passwd[NAME_NUM] = {'\0'};
	while(1)
	{
		system("clear");
		printf("******************************\n"
				"**￥￥*欢迎来到我的游戏*￥￥**\n"
				"*\n*\t1-->注册\n"
				"*\t2-->登录\n"
				"*\tq-->退出\n"
				"*\n*    请输入你的选择:");
		char ch = '\0';
		scanf("%c",&ch);
		while(getchar() != '\n');
		switch(ch)
		{
			case '1':
				registe(name,passwd);
				break;
			case '2':
				login(name,passwd);
				break;
			case 'q':
				exit(1);
				break;
			default:
				printf("输入错误，请重新输入\n");
	
		}
	}
}
