#include "func.h"
#include <stdio.h>


void print_menu(void)
{
	printf("SQ Student Manager V1.0\n");
	printf("1-->add student\n"
			"2-->del student\n"
			"3-->update student\n"
			"4-->query student\n"
			"5-->print student\n"
			"0-->exit\n"
			"input func no:"
			);
}
//向指定顺序表添加指定的学生信息
//插入成功，返回 0；失败 返回 -1
int add_student_to_list(line_list_t *l,student_t stu)
{
	if(is_list_full(l))
		return -1;
	l->data[l->count]=stu;
	l->count++;

	return 0;
}
//从指定顺序表删除指定id的学生信息
//删除成功，返回 0；失败 返回 -1
int del_student_from_list(line_list_t *l,student_t *p_stu)
{
	if(is_list_empty(l))
		return -1;
	int i=0,index=0,id=0;
	printf("input id you want delete:");
	scanf("%d",&id);
	index=search_index_by_id(l,id);
	if(index==-1)
		return -1;
	if(p_stu!=NULL)
		*p_stu=l->data[index];
	for(i=index;i<l->count-1;i++)
		l->data[i]=l->data[i+1];
	l->count--;
	
	return 0;
}
//更改指定顺序表中指定id的学生信息
//更改成功，返回 0；失败 返回 -1
int update_student_info(line_list_t *l)
{
	if(is_list_empty(l))
		return -1;
	int index=0,id=0;
	printf("input id you want to update:");
	scanf("%d",&id);
	index=search_index_by_id(l,id);
	if(index==-1)
		return -1;
	printf("current student info:\n");
	print_student_info(l->data[index]);

	printf("new name:");
	scanf("%s",l->data[index].name);
	printf("new score:");
	scanf("%d",&(l->data[index].score));
	return 0;
}
//查询指定顺序表中指定id的学生信息
//查询成功，返回0，平p_stu传递学生信息
//失败 返回 -1
int query_student_info(line_list_t *l,student_t *p_stu)
{
	if(is_list_empty(l))
		return -1;
	int id=0,index=0;
	printf("input id you want to query:");
	scanf("%d",&id);
	index=search_index_by_id(l,id);
	if(index==-1)
		return -1;
	if(p_stu!=NULL)
		*p_stu=l->data[index];
	return 0;
}
//获取指定id在顺序表中下标
//成功，返回 下表；失败 返回 -1
int search_index_by_id(line_list_t *l,int id)
{
	int i=0;
	for(i=0;i<l->count;i++)
	{
		if(l->data[i].id==id)
			return i;
	}
	return -1;
}
//打印所有学生信息
void print_students_info(line_list_t *l)
{
	int i=0;

	printf("id\tname\tscore\n");
	for(i=0;i<l->count;i++)
		print_student_info(l->data[i]);
}
//输入学生信息
void input_student_info(student_t *p_stu)
{
	if(p_stu==NULL)
		return;
	printf("input id:");
	scanf("%d",&(p_stu->id));
	printf("input name:");
	scanf("%s",p_stu->name);
	printf("input score:");
	scanf("%d",&(p_stu->score));
}
//打印学生信息
void print_student_info(student_t stu)
{
	printf("%d\t%s\t%d\n",stu.id,stu.name,stu.score);
}
//判断顺序表是否为满
//满。1；否则 0
int is_list_full(line_list_t *l)
{
	return l->count==MAX_STUDENT_LEN;
}
//判断顺序表是否为空
//空 1;否则 0
int is_list_empty(line_list_t *l)
{
	return l->count==0;
}

