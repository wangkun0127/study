#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
//定义变量别名
typedef int datatype_t;
//定义单链表
typedef struct link_node
{
	//定义数据域
	datatype_t data;
	//定义指针域
	struct link_node *next;
}link_node_t,*link_list_t;

//创建一个空的单链表
link_list_t creat_link_list_empty(void);
//销毁单链表
void destroy_link_list(link_list_t l);
//求单链表的表长
int link_list_length(link_list_t l);
//判断单链表是否为空
int is_link_list_empty(link_list_t l);
//遍历打印单链表
void print_all_link_list(link_list_t l);
//向单链表中插入元素
int insert_link_list_info(link_list_t l,int pos,datatype_t x);
//从单链表中删除元素
int delete_link_list_info(link_list_t l,int pos,datatype_t *ptr);
//清空单链表
void clear_link_list(link_list_t l);
//单链表逆序
void reverse_link_list(link_list_t l);
//头插
//尾插
//头删
//尾删
//获取单链表中指定位置的值
static int print_data_info(datatype_t x);


#endif
