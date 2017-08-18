#include <stdlib.h>
#include "line_list.h"
#include <stdio.h>

//创建一个空的带头节点的单链表
link_list_t create_empty_link_list(void)
{
	//为头节点分配空间
	link_list_t l=(link_list_t)malloc(sizeof(link_node_t));
	//进行空的单链表的初始化
	l->next=NULL;
	return l;
}
//判断单链表是否为空，为空，返回1;否则，返回，0
int is_link_list_empty(link_list_t l)
{
	return l->next==NULL;
}
//求单链表的表长，成功，返回len，否则，返回-1
int length_of_link_list(link_list_t l)
{
	if(is_link_list_empty(l))
		return -1;
	int len=0;
	while(l->next!=NULL)
	{
		len++;
		l=l->next;
	}
	return len;
}
//遍历打印单链表
void print_link_list_data_info(link_list_t l);
//打印单链表输出指定类型
static void print_data_info(datatype_t x);
//销毁单链表
void destroy_link_lint(link_list_t l);
