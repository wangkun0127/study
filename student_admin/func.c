#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
/*****************************

		管理员函数

*****************************/
//管理员登录
void adm_login(void)
{
	char name[100]={'r','o','o','t','\0'};
	char passwd[20]={'2','0','1','\0'};
	if(vali_login_info(name,passwd)==-1)
	{
		printf("密码或用户名或验证码错误请重新输入！\n");
		return;
	}
	adm_menu();
}
//管理员菜单
void adm_menu(void)
{
	system("clear");
	printf("正在跳转管理员菜单界面\n请稍候！\n");
	sleep(2);
	int flag=0;
	while(1)
	{
		system("clear");
		int ch=0;int ch1 = 0;
		printf("\t    *管 理 员 菜 单*\n");
		printf("\t*************************\n");
		printf("\t|\t\t\t|\n");
		printf("\t| 1、录入教师信息\t|\n");
		printf("\t| 2、修改教师信息\t|\n");
		printf("\t| 3、查看教师信息\t|\n");
		printf("\t| 4、删除教师信息\t|\n");
		printf("\t| 5、注销登录    \t|");
		printf("\n\t|\t\t\t|\n");
		printf("\t*************************\n");
		printf("请输入你的选择：");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				add_teacher_info();
				break;
			case 2:
				update_by_id();
				break;
			case 3:
				print_teach_list();
				break;
			case 4:
				delete_teacher_info(flag);
				break;
			case 5:
				//销毁单链表
				printf("确定是否返回登录界面：\n");
				printf("1-->确认\n");
				printf("2-->取消\n");
				printf("请选择：");
				scanf("%d",&ch1);
				while(getchar()!='\n');
				if(ch1==2)
				{
					break;
				}
				/*printf("确定返回登录界面（y/n）：");
				scanf("%c",&ch1);
				while(getchar()!='\n');
				if(ch1=='n')
					break;*/
				destery_list();
				login_menu();
				break;
			default:
				printf("\n输入有误，请重新输入！");
		}
		flag++;
		printf("按回车键继续！\n");
		while(getchar()!='\n');
	}
	return;
}
//验证登录信息
int vali_login_info(char *ch,char *num)
{
	char a[37]="0123456789qwertyuioplkjhgfdsazxcvbnm";
	int i,j;char output[5]={'\0'};
	srand((int)time(0));
	for(i=0;i<4;i++)
	{
		j=rand()%36;
		output[i]=a[j];
	}
	char ch1[10]={'\0'};
	char num1[20]={'\0'};
	char *p=num1;
	system("clear");
	printf("请输入用户名:");
	scanf("%s",ch1);
	while(getchar()!='\n');
	char out[5]={'\0'};
	int count=0;
	while(1)
	{
		if(count<3)
		{
			p=getpass("请输入密码：");
			if(strncmp(p,num,3)!=0)
			{
				printf("密码输入错误，请重新输入！\n");
			}
			else if(strncmp(p,num,3)==0)
			{
				break;
			}
		}
		else if(count==3)
		{
			printf("\n您输入的密码已错误三次，3秒钟后返回登录界面！\n");
			sleep(3);
			login_menu();
			break;
		}
		count++;
	}
	printf("------\n");
	printf("|%s|\n",output);
	printf("------\n");
	printf("请输入验证码：");
	scanf("%s",out);
	while(getchar()!='\n');
	if(strncmp(out,output,4)!=0||strncmp(p,num,3)!=0||strncmp(ch,ch1,4)!=0)
		return -1;
	return 0;
}
//处理辞职信息
int resign_info()
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	char ch='\0';
	int count=0;
	printf("辞职信息：\n");
	while(temp->next!=NULL)
	{
		if(temp->next->tdata.flag==1)
		{
			count++;
			printf("帐号:%d\t姓名：%s\n辞职原因:\n%s\n",temp->next->tdata.id,temp->next->tdata.name,temp->next->tdata.resign);
			printf("是否同意辞职（y/n）:");
			scanf("%c",&ch);
			while(getchar()!='\n');
			if(ch=='y')
			{
				temp->next->tdata.flag=2;
				printf("您已同意该老师的辞职请求！\n");
			}
			else if(ch=='n')
			{
				temp->next->tdata.flag=4;
				printf("您已拒绝该老师的辞职请求！\n");
			}
		}
		temp=temp->next;
	}
	if(count!=0)
	{
		writefile(head);
		printf("您已处理完所有老师的辞职请求！\n");
	}
	else
	{
		printf("暂未收到任何老师的辞职信息");
	}
	while(getchar()!='\n');
	return 1;
}
//添加教师信息
void add_teacher_info()
{
	link_teach_t *head=readfile();
	link_teach_t *temp1=head;
	link_teach_t *temp=(link_teach_t *)malloc(sizeof(link_teach_t));
	if(temp==NULL)
	{
		printf("fail\n");
		return;
	}
	temp->next=NULL;
	int flag=1,n=0;
	while(flag)
	{
		temp1=head;
		n=0;
		printf("请输入帐号:");
		scanf("%d",&temp->tdata.id);
		if(temp->tdata.id<100||temp->tdata.id>199)
		{
			printf("对不起，请输入100～199以内的id！\n");
			continue;
		}
		else
		{
			while(temp1->next!=NULL)
			{
				if(temp1->next->tdata.id==temp->tdata.id)
				{
					n++;
				}
				temp1=temp1->next;
			}
			if(n==0)
			{
				flag=0;
			}
			else
			{
				printf("对不起，您输入的id已存在，请重新输入！\n");
			}
		}
	}
	printf("请输入用户名:");
	scanf("%s",temp->tdata.name);
	printf("请输入性别：");
	scanf("%s",temp->tdata.man);
	printf("请输入 密 码:");
	scanf("%s",temp->tdata.passwd);
	printf("请输入 职 位:");
	scanf("%s",temp->tdata.position);
	printf("请输入 科 目:");
	scanf("%s",temp->tdata.subject);
	printf("请输入 备 注:");
	scanf("%d",&temp->tdata.flag);
	printf("请输入辞职信息:");
	scanf("%s",temp->tdata.resign);
	if(head->next!=NULL)
	{
		temp->next=head->next;
		head->next=temp;
	}
	else
	{
		head->next=temp;
	}
	writefile(head);
	return;
}
//删除教师信息
void delete_teacher_info(int flag)
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	int id=0,flag1=1,ch=0,flag2=1;
	if(flag==0)
	{
		flag=resign_info();
		return;
	}
	printf("请输入你想删除的用户帐号:");
	scanf("%d",&id);
	while(temp->next!=NULL&&flag1==1)
	{
		if(temp->next->tdata.id==id)
		{
			flag1=0;
		}
		else
		{
			temp=temp->next;
		}
	}
	link_teach_t *temp1=NULL;
	printf("帐号\t姓名\t\t性别\t密码\t职位\t科目\t备注\t辞职\n");
	print_data_info(temp->next->tdata);
	printf("请检查教师信息，确认是否删除：\n");
	while(flag2)
	{
		printf("1-->删除\n");
		printf("2-->退出\n");
		printf("请输入你的选择：");
		scanf("%d",&ch);
		if(ch==1)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			writefile(head);
			free(temp1),temp1=NULL;
			flag2=0;
		}
		else if(ch==2)
			flag2=0;
		else
			printf("输入有误，请重新选择");
	}
}
//遍历打印信息
void print_teach_list()
{
	link_teach_t *head=readfile();
	if(head->next==NULL)
		return;
	printf("您好，您要查看的教师信息如下：\n");
	printf("帐号\t姓名\t性别\t密码\t职位\t科目\t备注\t辞职\n");
	while(head->next!=NULL)
	{
		print_data_info(head->next->tdata);
		head=head->next;
	}
	printf("\n");
	return;
}
//打印指定节点数据
static void print_data_info(teacher_t data)
{
	printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n",data.id,data.name,data.man,data.passwd,data.position,data.subject,data.flag,data.resign);
}
//写入文件
void writefile(link_teach_t *head)
{
	if(NULL==head)
	{
		printf("no mesage to save\n");
		return;
	}
	FILE *fp;
	fp=fopen("teacher.txt","w");
	while(head->next!=NULL)
	{
		fwrite(head->next,sizeof(link_teach_t),1,fp);
		head=head->next;
	}
	fclose(fp);
	return;
}
//读到内存
link_teach_t * readfile()
{
	FILE *fp=fopen("teacher.txt","r");
	link_teach_t *temp=(link_teach_t *)malloc(sizeof(link_teach_t));
	link_teach_t *head=(link_teach_t *)malloc(sizeof(link_teach_t));
	head->next=NULL;
	while(fread(temp,sizeof(link_teach_t),1,fp))
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(link_teach_t *)malloc(sizeof(link_teach_t));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;
}
//修改指定id的信息节点
void update_by_id()
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	int id=0,flag=1;
	char ch='\0';
	printf("请输入你想修改的用户帐号:");
	scanf("%d",&id);
	while(getchar()!='\n');
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->tdata.id==id)
		{
			link_teach_t *temp1=NULL;
			printf("帐号\t姓名\t性别\t密码\t职位\t科目\t备注\t辞职\n");
			print_data_info(temp->next->tdata);
			while(flag)
			{
				printf("请检查教师信息，确认是否修改(y/n)：");
				scanf("%c",&ch);
				while(getchar()!='\n');
				if(ch=='y'||ch=='Y')
				{
					temp1=temp->next;
					temp->next=temp1->next;
					writefile(head);
					add_teacher_info();
					free(temp1),temp1=NULL;
					flag=0;
				}
				else if(ch=='n'||ch=='N')
					flag=0;
				else
					printf("输入有误，请重新选择");
			}
			flag=0;
		}
		else
		{
			temp=temp->next;
		}
	}
}

//清空单链表
link_teach_t *clear_list()
{
	link_teach_t *head=readfile();
	link_teach_t *temp=NULL;
	while(head->next!=NULL)
	{
		temp=head->next;
		head->next=temp->next;
		free(temp);
		temp=NULL;
	}
	return head;
}
//销毁单链表
void destery_list()
{
	free(clear_list());
	
}
/******************************

		班主任函数

******************************/
//班主任登录界面
void teach_login(int ch)
{
	int id=vali_login_teach_info();
	if(id==-1)
	{
		printf("密码或用户名错误请重新输入！\n");
		return;
	}
	if(ch==1)
	{
		teach_menu(id);
	}
	else if(ch==2)
	{
		teach2_menu(id);
	}

}
//检查密码错误
int vali_login_teach_info()
{
	link_teach_t *head=readfile();
	int id=0;
	char passwd[20]={'\0'};
	char *p=passwd;
	printf("请输入你的帐号：");
	scanf("%d",&id);
	//printf("请输入你的密码：");
	//scanf("%s",passwd);
	p=getpass("请输入你的密码：");
	while(head->next!=NULL)
	{
		if(id==head->next->tdata.id&&strcmp(p,head->next->tdata.passwd)==0)
			return id;
		head=head->next;
	}
	return -1;
}
//处理辞职反馈
int faceback_resign(int ids)
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->next->tdata.id==ids)
		{
			if(temp->next->tdata.flag==2)
			{
				temp->next->tdata.flag=3;
				printf("您已辞职成功，这是您最后一次使用该帐号！\n");
				writefile(head);
				return 1;
			}
			else if(temp->next->tdata.flag==4)
			{
				temp->next->tdata.flag=0;
				printf("对不起，您的辞职申请未通过，请重新申请或继续使用该帐号！\n");
				writefile(head);
				return 1;
			}
			else if(temp->next->tdata.flag==0)
			{
				return 1;
			}
		}
		temp=temp->next;
	}
}
//删除教师信息
void delete_me_info()
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	link_teach_t *temp1=NULL;
	int flag1=1;
	while(temp->next!=NULL&&flag1==1)
	{
		if(temp->next->tdata.flag==3)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			writefile(head);
			free(temp1),temp1=NULL;
			flag1=0;
		}
		temp=temp->next;
	}
}
//教师界面菜单
void teach_menu(int ids)
{
	system("clear");
	printf("正在跳转班主任登录界面\n请稍后...\n");
	sleep(2);
	int flag=0;
	int ch1=0;
	while(1)
	{
		system("clear");
		int ch=0;
		printf("\t\t\t*班主任菜单界面*\n");
		printf("\t*****************************************\n");
		printf("\t|\t\t\t\t\t|\n");
		printf("\t| 1、录入学生信息\t2、查看学生信息\t|\n");
		printf("\t| 3、修改学生信息\t4、删除学生信息\t|\n");
		printf("\t| 5、查看学生排名\t6、修改登录密码\t|\n");
		printf("\t| 7、查看学生留言\t8、提出辞职\t|\n");
		printf("\t| 9、返回上一层\t\t\t\t|");
		printf("\n\t|\t\t\t\t\t|\n");
		printf("\t*****************************************\n");
		if(flag==0)
		{
			flag=faceback_resign(ids);
		}
		printf("请输入你的选择：");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				add_stu_info();
				break;
			case 2:
				print_stu_list();
				break;
			case 3:
				update_stu_by_id();
				break;
			case 4:
				delete_stu_info();
				break;
			case 5:
				stu_sort();
				break;
			case 6:
				update_teach_id(ids);
				break;
			case 7:
				check_stu_message();
				break;
			case 8:
				submit_regin(ids);
				break;
			case 9:
				//销毁单链表
				printf("确定是否返回登录界面：\n");
				printf("1-->确认\n");
				printf("2-->取消\n");
				printf("请选择：");
				scanf("%d",&ch1);
				while(getchar()!='\n');
				if(ch1==2)
				{
					break;
				}
				delete_me_info();
				destery_stu_list();
				login_menu();
				break;
			default:
				printf("输入有误，请重新输入！");
		}
		printf("按回车键继续！\n");
		while(getchar()!='\n');
	}
	return;
}
//读到内存
link_stu_t * stu_readfile()
{
	FILE *fp=fopen("student.txt","r");
	link_stu_t *temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	link_stu_t *head=(link_stu_t *)malloc(sizeof(link_stu_t));
	head->next=NULL;
	while(fread(temp,sizeof(link_stu_t),1,fp))
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;
}
//写入文件
void stu_writefile(link_stu_t *head)
{
	if(NULL==head)
	{
		printf("no mesage to save\n");
		return;
	}
	FILE *fp;
	fp=fopen("student.txt","w");
	while(head->next!=NULL)
	{
		fwrite(head->next,sizeof(link_stu_t),1,fp);
		head=head->next;
	}
	fclose(fp);
	return;
}
//添加学生信息
void add_stu_info()
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp1=head;
	link_stu_t *temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	if(temp==NULL)
	{
		printf("fail\n");
		return;
	}
	temp->next=NULL;
	int flag=1,n=0;
	while(flag)
	{
		temp1=head;
		n=0;
		printf("请输入帐号:");
		scanf("%d",&temp->sdata.id);
		if(temp->sdata.id<200||temp->sdata.id>299)
		{
			printf("对不起，请输入200～299以内的id！\n");
			continue;
		}
		else
		{
			while(temp1->next!=NULL)
			{
				if(temp1->next->sdata.id==temp->sdata.id)
					n++;
				temp1=temp1->next;
			}
			if(n==0)
			{
				flag=0;
			}
			else
			{
				printf("对不起，您输入的id已存在，请重新输入！\n");
			}
		}
	}
	printf("请输入姓名:");
	scanf("%s",temp->sdata.name);
	printf("请输入性别:");
	scanf("%s",temp->sdata.man);
	printf("请输入密码:");
	scanf("%s",temp->sdata.passwd);
	printf("请输入年龄:");
	scanf("%d",&temp->sdata.age);
	printf("请输入班级:");
	scanf("%s",temp->sdata.clas);
	printf("请输入数学成绩:");
	scanf("%f",&temp->sdata.math);
	printf("请输入C语言成绩:");
	scanf("%f",&temp->sdata.C);
	temp->sdata.score=(temp->sdata.math)+(temp->sdata.C);
	printf("请输入备注:");
	scanf("%d",&temp->sdata.flag);
	printf("请输入留言:");
	scanf("%s",temp->sdata.message);
	if(head->next!=NULL)
	{
		temp->next=head->next;
		head->next=temp;
	}
	else
	{
		head->next=temp;
	}
	stu_writefile(head);
	return;
}
//遍历打印学生信息
void print_stu_list()
{
	link_stu_t *head=stu_readfile();
	if(head->next==NULL)
		return;
	printf("帐号\t姓名\t性别\t密码\t年龄\t班级\t数学\tC语言\t总分\t留言\n");
	while(head->next!=NULL)
	{
		print_stu_data_info(head->next->sdata);
		head=head->next;
	}
	printf("\n");
	return;
}
//打印指定节点数据
static void print_stu_data_info(stu_t data)
{
	printf("%d\t%s\t%s\t%s\t%d\t%s\t%.2f\t%.2f\t%.2f\t%s\n",data.id,data.name,data.man,data.passwd,data.age,data.clas,data.math,data.C,data.score,data.message);
}
//删除学生信息
void delete_stu_info()
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=head;
	int id=0,flag1=1,ch=0,flag=1;
	printf("请输入你想删除的用户帐号:");
	scanf("%d",&id);
	while(temp->next!=NULL&&flag1==1)
	{
		if(temp->next->sdata.id==id)
		{
			flag1=0;
		}
		else
		{
			temp=temp->next;
		}
	}
	link_stu_t *temp1=NULL;
	print_stu_data_info(temp->next->sdata);
	printf("请检查学生信息，确认是否删除：\n");
	while(flag)
	{
		printf("1-->删除\n");
		printf("2-->退出\n");
		printf("请输入你的选择：");
		scanf("%d",&ch);
		if(ch==1)
		{
			temp1=temp->next;
			temp->next=temp1->next;
			stu_writefile(head);
			free(temp1),temp1=NULL;
			flag=0;
		}
		else if(ch==2)
			flag=0;
		else
			printf("输入有误，请重新选择");
	}
}
//学生按学号排序
void stu_sort()
{
	link_stu_t *head=stu_readfile();
	if(head==NULL)
	{
		printf("no massage\n");
		return;
	} 
	int ch=0;
	link_stu_t *p1=head->next;
	link_stu_t *low;
	link_stu_t *p2;
	link_stu_t *temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	temp->next=NULL;
	printf("您可以选择的排序方式有：\n");
	printf("1-->学号排序\n");
	printf("2-->总分排序\n");
	printf("请选择：");
	scanf("%d",&ch);
	while(getchar()!='\n');
	while(p1!=NULL)
	{
		low=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(ch==1&&low->sdata.id>p2->sdata.id)
			{
				low=p2;
				p2=p2->next;
			}
			else if(ch==2&&low->sdata.score<p2->sdata.score)
			{
				low=p2;
				p2=p2->next;
			}
			else
			{
				p2=p2->next;
			}
		}
		if(low!=p1)
		{
			temp->sdata=low->sdata;
			low->sdata=p1->sdata;
			p1->sdata=temp->sdata;
		}
		p1=p1->next;
	}
	printf("序号\t帐号\t姓名\t密码\t年龄\t班级\t数学\tC语言\t总分\t标记\n");
	int count=1;
	while(head->next!=NULL)
	{
		printf("%d\t%d\t%s\t%s\t%d\t%s\t%.2f\t%.2f\t%.2f\t%d\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.passwd,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.math,head->next->sdata.C,head->next->sdata.score,head->next->sdata.flag);
		count++;
		head=head->next;
	}
	printf("\n");
	free(temp),temp=NULL;
	return;
}
//修改指定id的信息节点
void update_stu_by_id()
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=head;
	int id=0,flag=1;
	char ch='\0';
	printf("请输入你想修改的用户帐号:");
	scanf("%d",&id);
	while(getchar()!='\n');
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->sdata.id==id)
		{
			link_stu_t *temp1=NULL;
			print_stu_data_info(temp->next->sdata);
			while(flag)
			{
				printf("请检查学生信息，确认是否修改(y/n)：");
				scanf("%c",&ch);
				while(getchar()!='\n');
				if(ch=='y')
				{
					temp1=temp->next;
					temp->next=temp1->next;
					stu_writefile(head);
					add_stu_info();
					free(temp1),temp1=NULL;
					flag=0;
				}
				else if(ch=='n')
					flag=0;
				else
					printf("输入有误，请重新选择");
			}
			flag=0;
		}
		else
		{
			temp=temp->next;
		}
	}
}
//修改教师密码
void update_teach_id(int ids)
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	int id=0,flag=1;
	char ch='\0',passwd[20]={'\0'},passwd1[20]={'\0'},passwd2[20]={'\0'};
	printf("请输入你的帐号：");
	scanf("%d",&id);
	while(getchar()!='\n');
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->tdata.id==ids&&id==ids)
		{
			printf("请输入原密码：");
			scanf("%s",passwd);
			while(getchar()!='\n');
			if(strcmp(temp->next->tdata.passwd,passwd)!=0)
			{
				printf("原密码输入错误，请重新输入！");
				return;
			}
			while(flag)
			{
				printf("请输入新密码：");
				scanf("%s",passwd1);
				while(getchar()!='\n');
				printf("请重新输入新密码：");
				scanf("%s",passwd2);
				while(getchar()!='\n');
				if(strcmp(passwd1,passwd2)!=0)
				{
					printf("您输入的两次新密码不一致，请重新输入！");
					continue;
				}
				printf("新密码输入成功，请确认是否修改（y/n）：");
				scanf("%c",&ch);
				while(getchar()!='\n');
				if(ch=='y'||ch=='Y')
				{
					strcpy(temp->next->tdata.passwd,passwd1);
					writefile(head);
					printf("您的密码修改成功，请重新登录！");
					flag=0;
				}
				else if(ch=='n'||ch=='N')
				{
					printf("密码修改已取消！");
					return;
				}
			}
		}
		temp=temp->next;
	}
	while(getchar()!='\n');
	
	destery_list();
	login_menu();
	
}
//查看学生留言
void check_stu_message()
{
	link_stu_t *head=stu_readfile();
	printf("以下是所有学生留言：\n");
	while(head->next!=NULL)
	{
		if(head->next->sdata.flag==1)
		{
			printf("帐号：%d\t姓名：%s\n留言：\n%s\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.message);
		}
		head=head->next;
	}
}
//添加辞职
void submit_regin(int ids)
{
	link_teach_t *head=readfile();
	link_teach_t *temp=head;
	int flag=1;
	char ch[1100]={'\0'},ch1='\0',ch2='\0';
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->tdata.id==ids)
		{
			printf("请问您确认辞职（y/n）:");
			scanf("%c",&ch2);
			while(getchar()!='\n');
			if(ch2=='n'||ch2=='N')
				return;
			printf("请输入您的辞职原因（少于500字）：\n");
			scanf("%s",ch);
			while(getchar()!='\n');
			while(flag)
			{
				printf("是否确认提交此辞职信息（y/n）:");
				scanf("%c",&ch1);
				while(getchar()!='\n');
				if(ch1=='n'||ch1=='N')
					return;
				else if(ch1=='y'||ch1=='Y')
				{
					strcpy(temp->next->tdata.resign,ch);
					temp->next->tdata.flag=1;
					writefile(head);
					printf("留言成功，请等待管理员处理，谢谢！");
					return;
				}
				printf("您的输入有误，请重新确认！\n");
			}
		}
		temp=temp->next;
	}
	while(getchar()!='\n');
}
//清空单链表
link_stu_t *clear_stu_list()
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=NULL;
	while(head->next!=NULL)
	{
		temp=head->next;
		head->next=temp->next;
		free(temp);
		temp=NULL;
	}
	return head;
}
//销毁单链表
void destery_stu_list()
{
	free(clear_stu_list());
	
}
/******************************

		教师函数

******************************/
//选择教师类型
void change_teach()
{
	int ch=0;
	system("clear");
	printf("您好！您有以下选择：\n");
	printf("1-->班主任登录\t");
	printf("2-->普通教师登录\n");
	printf("请选择您的登录方式：");
	scanf("%d",&ch);
	while(getchar()!='\n');
	
	teach_login(ch);
}
//普通教师登录界面
void teach2_menu(int ids)
{
	system("clear");
	printf("正在跳转教师登录界面\n请稍后...\n");
	sleep(2);
	int flag=0;
	char ch1[20]={'m','a','t','h','\0'};
	char ch2[20]={'C','\0'};
	int change=0;
	if(check_subject(ids)==1)
		change=1;
	else if(check_subject(ids)==2)
		change=2;
	while(1)
	{
		system("clear");
		int ch=0,ch1=0;
		printf("\t\t\t*教师菜单界面*\n");
		printf("\t*****************************************\n");
		printf("\t|\t\t\t\t\t|\n");
		printf("\t| 1、查看学生信息\t2、查看学生排名\t|\n");
		printf("\t| 3、修改学生信息\t4、修改登录密码\t|\n");
		printf("\t| 5、提出辞职    \t6、返回登陆界面\t|");
		printf("\n\t|\t\t\t\t\t|\n");
		printf("\t*****************************************\n");
		if(flag==0)
		{
			flag=faceback_resign(ids);
		}
		printf("请输入你的选择：");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				print2_stu_list(ids);
				break;
			case 2:
				stu2_sort(change);
				break;
			case 3:
				update2_stu_by_id(change);
				break;
			case 4:
				update_teach_id(ids);
				break;
			case 5:
				submit_regin(ids);
				break;
			case 6:
				//销毁单链表
				printf("确定是否返回登录界面：\n");
				printf("1-->确认\n");
				printf("2-->取消\n");
				printf("请选择：");
				scanf("%d",&ch1);
				while(getchar()!='\n');
				if(ch1==2)
				{
					break;
				}
				delete_me_info();
				destery_stu_list();
				login_menu();
				break;
			default:
				printf("输入有误，请重新输入！");
		}
		printf("按回车键继续！\n");
		while(getchar()!='\n');
	}
	return;
}
//遍历打印本学科学生信息
void print2_stu_list(int ids)
{
	link_teach_t *temp=readfile();
	link_stu_t *head=stu_readfile();
	if(head->next==NULL)
		return;
	int count=1;
	char ch1[20]={'m','a','t','h','\0'};
	char ch2[20]={'C','\0'};
	printf("序号\t帐号\t姓名\t性别\t密码\t年龄\t班级\t成绩\n");
	while(temp->next!=NULL)
	{
		if(temp->next->tdata.id==ids)
		{
			while(head->next!=NULL)
			{
				if(strcmp(ch1,temp->next->tdata.subject)==0)
				{
					printf("%d\t%d\t%s\t%s\t%s\t%d\t%s\t%.2f\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.man,head->next->sdata.passwd,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.math);
				}
				else if(strcmp(ch2,temp->next->tdata.subject)==0)
				{
					printf("%d\t%d\t%s\t%s\t%s\t%d\t%s\t%.2f\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.man,head->next->sdata.passwd,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.C);
				}
				head=head->next;
			}
		}
		temp=temp->next;
	}
	
	printf("\n");
	return;
}
//修改指定id的信息节点
void update2_stu_by_id(int change)
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=head;
	int id=0,flag=1;
	char ch='\0';
	printf("请输入你想修改的用户帐号:");
	scanf("%d",&id);
	while(getchar()!='\n');
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->sdata.id==id)
		{
			if(change==1)
				printf("%d\t%s\t%d\t%s\t%.2f\n",temp->next->sdata.id,temp->next->sdata.name,temp->next->sdata.age,temp->next->sdata.clas,temp->next->sdata.math);
			else if(change==2)
				printf("%d\t%s\t%d\t%s\t%.2f\n",temp->next->sdata.id,temp->next->sdata.name,temp->next->sdata.age,temp->next->sdata.clas,temp->next->sdata.C);
			//print_stu_data_info(temp->next->sdata);
			while(flag)
			{
				printf("请检查学生信息，确认是否修改(y/n)：");
				scanf("%c",&ch);
				while(getchar()!='\n');
				if(ch=='y')
				{
					if(change==1)
					{
						printf("请输入新成绩：");
						scanf("%f",&temp->next->sdata.math);
					}
					else if(change==2)
					{
						printf("请输入新成绩：");
						scanf("%f",&temp->next->sdata.C);
					}
					stu_writefile(head);
					flag=0;
				}
				else if(ch=='n')
					flag=0;
				else
					printf("输入有误，请重新选择");
			}
			flag=0;
		}
		else
		{
			temp=temp->next;
		}
	}
	printf("输入成功，请确认！\n");
	while(getchar()!='\n');
}

int check_subject(int ids)
{
	link_teach_t *head=readfile();
	char ch1[20]={'m','a','t','h','\0'};
	char ch2[20]={'C','\0'};
	while(head->next!=NULL)
	{
		if(head->next->tdata.id==ids)
		{
			if(strcmp(head->next->tdata.subject,ch1)==0)
				return 1;
			else if(strcmp(head->next->tdata.subject,ch2)==0)
				return 2;
		}
		head=head->next;
	}
}
//学生按本科成绩排序
void stu2_sort(int change)
{
	link_stu_t *head=stu_readfile();
	if(head==NULL)
	{
		printf("no massage\n");
		return;
	} 
	int ch=0;
	link_stu_t *p1=head->next;
	link_stu_t *low;
	link_stu_t *p2;
	link_stu_t *temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	temp->next=NULL;
	while(p1!=NULL)
	{
		low=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(change=1&&low->sdata.math<p2->sdata.math)
	 		{
				low=p2;
				p2=p2->next;
			}
			else if(change=2&&low->sdata.C<p2->sdata.C)
	 		{
				low=p2;
				p2=p2->next;
			}
			else
			{
				p2=p2->next;
			}
		}
		if(low!=p1)
		{
			temp->sdata=low->sdata;
			low->sdata=p1->sdata;
			p1->sdata=temp->sdata;
		}
		p1=p1->next;
	}
	printf("序号\t帐号\t姓名\t年龄\t班级\t成绩\n");
	int count=1;
	while(head->next!=NULL)
	{
		if(change==1)
			printf("%d\t%d\t%s\t%d\t%s\t%.2f\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.math);
		else if(change==2)
			printf("%d\t%d\t%s\t%d\t%s\t%.2f\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.C);
		count++;
		head=head->next;
	}
	printf("\n");
	free(temp),temp=NULL;
	return;
}
/******************************

		学生函数

******************************/
//学生登录界面
void student_login(void)
{
	int id=vali_login_student_info();
	if(id==-1)
	{
		printf("密码或用户名错误请重新输入！\n");
		return;
	}
	student_menu(id);

}
//检查密码错误
int vali_login_student_info()
{
	link_stu_t *head=stu_readfile();
	int id=0;
	char passwd[20]={'\0'};
	char *p=passwd;
	system("clear");
	printf("请输入你的帐号：");
	scanf("%d",&id);
	p=getpass("请输入你的密码：");
	//scanf("%s",passwd);
	while(head->next!=NULL)
	{
		if(id==head->next->sdata.id&&strcmp(p,head->next->sdata.passwd)==0)
			return id;
		head=head->next;
	}
	return -1;
}
//学生界面菜单
void student_menu(int ids)
{
	system("clear");
	printf("正在跳转学生菜单界面\n请稍候...\n");
	sleep(2);
	int ch1=0;
	while(1)
	{
		system("clear");
		int ch=0;
		printf("\t      *学生菜单界面*\n");
		printf("\t*************************\n");
		printf("\t|\t\t\t|\n");
		printf("\t| 1、查看成绩信息\t|\n");
		printf("\t| 2、给老师留言  \t|\n");
		printf("\t| 3、修改登录密码\t|\n");
		printf("\t| 4、注销登录    \t|");
		printf("\n\t|\t\t\t|\n");
		printf("\t*************************\n");
		printf("请输入你的选择：");
		scanf("%d",&ch);
		while(getchar()!='\n');
		switch(ch)
		{
			case 1:
				//查找指定id的信息节点
				check_stu_by_id(ids);
				break;
			case 2:
				//修改留言
				update_stu_message(ids);
				break;
			case 3:
				//修改密码
				update_stu_id(ids);
				break;
			case 4:
				//销毁单链表
				printf("确定是否返回登录界面：\n");
				printf("1-->确认\n");
				printf("2-->取消\n");
				printf("请选择：");
				scanf("%d",&ch1);
				while(getchar()!='\n');
				if(ch1==2)
				{
					break;
				}
				destery_stu_list();
				login_menu();
				break;
			default:
				printf("输入有误，请重新输入！");
		}
		while(getchar()!='\n');
		printf("按回车键继续！\n");
		while(getchar()!='\n');
	}
	return;
}
//查找指定id的信息节点
void check_stu_by_id(int ids)
{
	link_stu_t *head=stu_readfile();
	if(head==NULL)
	{
		printf("no massage\n");
		return;
	}
	int ch=0;
	link_stu_t *p1=head->next;
	link_stu_t *low;
	link_stu_t *p2;
	link_stu_t *temp=(link_stu_t *)malloc(sizeof(link_stu_t));
	temp->next=NULL;
	while(p1!=NULL)
	{
		low=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(low->sdata.score<p2->sdata.score)
			{
				low=p2;
				p2=p2->next;
			}
			else
			{
				p2=p2->next;
			}
		}
		if(low!=p1)
		{
			temp->sdata=low->sdata;
			low->sdata=p1->sdata;
			p1->sdata=temp->sdata;
		}
		p1=p1->next;
	}
	int count=1,flag=1;
	while(head->next!=NULL&&flag==1)
	{
		if(head->next->sdata.id==ids)
		{
			printf("恭喜您查找成功，您的信息如下：\n");
			printf("序号\t帐号\t姓名\t密码\t年龄\t班级\t数学\tC语言\t总分\n");
			printf("%d\t%d\t%s\t%s\t%d\t%s\t%.2f\t%.2f\t%.2f\n",count,head->next->sdata.id,head->next->sdata.name,head->next->sdata.passwd,head->next->sdata.age,head->next->sdata.clas,head->next->sdata.math,head->next->sdata.C,head->next->sdata.score);
			flag=0;
		}
		count++;
		head=head->next;
	}
	printf("\n");
	free(temp),temp=NULL;
	return;
	
}
//修改学生密码
void update_stu_id(int ids)
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=head;
	int id=0,flag=1;
	char ch='\0',passwd[20]={'\0'},passwd1[20]={'\0'},passwd2[20]={'\0'};
	printf("请输入你的帐号：");
	scanf("%d",&id);
	while(getchar()!='\n');
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->sdata.id==ids&&id==ids)
		{
			printf("请输入原密码：");
			scanf("%s",passwd);
			while(getchar()!='\n');
			if(strcmp(temp->next->sdata.passwd,passwd)!=0)
			{
				printf("原密码输入错误，请重新输入！");
				return;
			}
			while(flag)
			{
				printf("请输入新密码：");
				scanf("%s",passwd1);
				while(getchar()!='\n');
				printf("请重新输入新密码：");
				scanf("%s",passwd2);
				while(getchar()!='\n');
				if(strcmp(passwd1,passwd2)!=0)
				{
					printf("您输入的两次新密码不一致，请重新输入！");
					continue;
				}
				printf("新密码输入成功，请确认是否修改（y/n）：");
				scanf("%c",&ch);
				while(getchar()!='\n');
				if(ch=='y'||ch=='Y')
				{
					strcpy(temp->next->sdata.passwd,passwd1);
					stu_writefile(head);
					printf("您的密码修改成功，请重新登录！");
					flag=0;
				}
				else if(ch=='n'||ch=='N')
				{
					printf("密码修改已取消！");
					return;
				}
			}
		}
		temp=temp->next;
	}
	while(getchar()!='\n');
	
	destery_stu_list();
	login_menu();
	
}
//修改留言
void update_stu_message(int ids)
{
	link_stu_t *head=stu_readfile();
	link_stu_t *temp=head;
	int flag=1;
	char ch[1100]={'\0'},ch1='\0',ch2='\0';
	while(temp->next!=NULL&&flag==1)
	{
		if(temp->next->sdata.id==ids)
		{
			printf("您已有留言如下：\n\t%s\n",temp->next->sdata.message);
			printf("请问是否需要修改留言（y/n）:");
			scanf("%c",&ch2);
			while(getchar()!='\n');
			if(ch2=='n'||ch2=='N')
				return;
			printf("请输入您的留言（少于500字）：\n");
			scanf("%s",ch);
			while(getchar()!='\n');
			while(flag)
			{
				printf("是否确认保存此留言信息（y/n）:");
				scanf("%c",&ch1);
				while(getchar()!='\n');
				if(ch1=='n'||ch1=='N')
					return;
				else if(ch1=='y'||ch1=='Y')
				{
					strcpy(temp->next->sdata.message,ch);
					temp->next->sdata.flag=1;
					stu_writefile(head);
					printf("留言成功，请前往查看，谢谢！");
					return;
				}
				printf("您的输入有误，请重新确认！\n");
			}
		}
		temp=temp->next;
	}
	while(getchar()!='\n');
}











