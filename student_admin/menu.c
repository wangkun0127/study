#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//***********************************

		/*用户登录菜单*/

//***********************************
void login_menu(void)
{
	while(1)
	{
		system("clear");
		char ch='\0';int ch1=0;
		printf("\t*欢迎使用学生管理系统*\n");
		printf("    ****************************\n");
		printf("    |\t  LOGIN OPTIONS\t       |\n");
		printf("    |\t\t \t       |\n");
		printf("    |\t  1、管理员登录\t       |\n");
		printf("    |\t  2、教 师 登录\t       |\n");
		printf("    |\t  3、学 生 登录\t       |\n");
		printf("    |\t  4、退 出 登录\t       |\n");
		printf("    |\t\t \t       |\n");
		printf("    ****************************\n");
		printf("\t\t    *by:wangkun*\n");
		printf("   请输入你的选择：");
		scanf("%c",&ch);
		switch(ch)
		{
			case '1':
				adm_login();
				break;
			case '2':
				change_teach();
				break;
			case '3':
				student_login();
				break;
			case '4':
				printf("确定是否出登录：\n");
				printf("1-->确认\n");
				printf("2-->取消\n");
				printf("请选择：");
				scanf("%d",&ch1);
				while(getchar()!='\n');
				if(ch1==2)
				{
					break;
				}
				system("clear");
				printf("\n \t谢谢您的使用，再见！！！\n");
				sleep(2);
				exit(1);
				break;
			default:
				printf("\t  没有这个选项，请重新选择！");
				break;
		}
		while(getchar()!='\n');	
		printf("输入回车继续！\n");
		while(getchar()!='\n');
	}
	
}
