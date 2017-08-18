#ifndef _LINE_LIST_H_
#define _LINE_LIST_H_
//定义单链表中数据域的抽象数据类型
//实现单链表时，尽量与其具体类型无关
typedef int datatype_t;

//定义单链表数据类型节点类型
//link_node_t    数据节点类型的别名（struct link_node）
//link_list_t    数据节点的指针类型别名，主要用于标示指针的类型，用于唯一标识一条单链表，等价于（struct line_node *或line_node_t *）
typedef struct link_node
{
	//数据域：存放数据部分
	datatype_t data;
	//指针域：存放后一个数据节点的地址值
	struct link_node *next;
}link_node_t,*link_list_t;

//创建一个空的带头节点的单链表
link_list_t create_empty_link_list(void);
//判断单链表是否为空，为空，返回1;否则，返:回，0
int is_link_list_empty(link_list_t l);
//求单链表的表长，成功，返回len，否则，返回-1
int length_of_link_list(link_list_t l);
//向单链表中指定位置插入数据，成功，返回0,失败，返回-1
//头结点的pos为0
//pos的有效值[1,len+1]
int insert_into_link_list_by_position(link_list_t l,int pos,datatype_t x);
//遍历打印单链表
void print_link_list_data_info(link_list_t l);
//打印单链表输出指定类型
static void print_data_info(datatype_t x);
//销毁单链表
void destroy_link_lint(link_list_t l);

#endif
