#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>

//空链表
link_list_t creat_link_list_empty(void)
{
	link_list_t l=(link_list_t)malloc(sizeof(link_node_t));
	l->next=NULL;
	return l;
}
//求表长
int link_list_length(link_list_t l)
{
	if(l==NULL)
		return -1;
	int len=0;
	while(l->next!=NULL)
	{
		len++;
		l=l->next;
	}
	return len;
}
//插入元素
int insert_link_list_info(link_list_t l,int pos,datatype_t x)
{
	if(pos<1||pos>link_list_length(l)+1)
		return -1;
	int i=0;
	for(i=0;i<pos-1;i++)
		l=l->next;
	link_node_t *p=NULL;
	p=(link_node_t *)malloc(sizeof(link_node_t));
	p->data=x;
	p->next=l->next;
	l->next=p;
	return 0;
}
//删除表
int delete_link_list_info(link_list_t l,int pos,datatype_t *ptr)
{
	if(is_link_list_empty(l))
		return -1;
	if(pos<1||pos>link_list_length(l))
		return -1;
	int i=0;
	link_node_t *p=NULL;
	for(i=0;i<pos-1;i++)
		l=l->next;
	p=l->next;
	l->next=p->next;
	if(ptr!=NULL)
		*ptr=p->data;
	free(p),p=NULL;
	return 0;
}
//遍历打印
void print_all_link_list(link_list_t l)
{
	if(l==NULL)
		return;
	printf("link_list:");
	while(l->next!=NULL)
	{
		print_data_info(l->next->data);
		l=l->next;
	}
	printf("\n");
	return;
}
//逆序
void reverse_link_list(link_list_t l)
{
	if(l==NULL||is_link_list_empty(l))
		return;
	link_list_t l2=l->next;
	l->next=NULL;
	link_node_t *p=NULL;
	while(l2!=NULL)
	{
		p=l2;
		l2=l2->next;
		p->next=l->next;
		l->next=p;
	}
}
//打印
static int print_data_info(datatype_t x)
{
	printf("%d ",x);
}
//清空单链表
void clear_link_list(link_list_t l)
{
	link_node_t *p=NULL;
	while(l->next!=NULL)
	{
		p=l->next;
		l->next=p->next;
		free(p);
	}
}
//销毁
void destroy_link_list(link_list_t l)
{
	clear_link_list(l);
}
//判断是否为空
int is_link_list_empty(link_list_t l)
{
	return l->next==NULL;
}
