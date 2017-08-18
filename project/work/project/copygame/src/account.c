#include <stdio.h>
#include <string.h>
#include "../include/supports.h"
#include "../include/game.h"
#include "../include/include.h"
void registe(char * name , char * passwd)
{
	char tmp1[NAME_NUM] = {'\0'};
	char tmp2[NAME_NUM] = {'\0'};
	printf("请输入用户名:");
	myGets(name,NAME_NUM);
	while(1)
	{
		printf("请输入密码:");
		myGets(tmp1,NAME_NUM);
		printf("请重新输入密码:");
		myGets(tmp2,NAME_NUM);
		if(strcmp(tmp1,tmp2) == 0)
		{
			strncpy(passwd,tmp1,strlen(tmp1));
			break;
		}else{
			printf("两次密码不一致，请重新输入\n");
		}
	}
}
void login(char * name , char * passwd)
{
	char newName[NAME_NUM] = {'\0'};
	char newPasswd[NAME_NUM] = {'\0'};
	printf("请输入用户名:");
	myGets(newName,NAME_NUM);
	printf("请输入密码:");
	myGets(newPasswd,NAME_NUM);
	
	if(strcmp(name,newName) != 0 || strcmp(passwd , newPasswd) != 0){
		printf("登录失败,请重新登录\n");
		printf("按下回车键继续");
		while(getchar() != '\n');
	}else{
		//进入游戏
		gameMenu();
	}
}
