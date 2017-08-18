#ifndef _FUNC_H_
#define _FUNC_H_

#define MAX_NAME_LEN 50
#define MAX_STUDENT_LEN 100

//定义菜单数字宏
#define MENU_ITEM_ADD 1
#define MENU_ITEM_DEL 2
#define MENU_ITEM_UPDATE 3
#define MENU_ITEM_QUERY 4
#define MENU_ITEM_PRINT 5
#define MENU_ITEM_EXIT 0

//学生信息结构体类型及其别名
typedef struct student
{
	int id;
	char name[MAX_NAME_LEN];
	int score;
}student_t;
//顺序表类型及其别名
typedef struct line_list
{
	//数据部分：存储具体数据
	student_t data[MAX_STUDENT_LEN];
	//游标部分：用于表示有效数据个数
	int count;
}line_list_t;
//打印菜单函数
void print_menu(void);
//向指定顺序表添加指定的学生信息
//插入成功，返回 0；失败 返回 -1
int add_student_to_list(line_list_t *l,student_t stu);
//从指定顺序表删除指定id的学生信息
//删除成功，返回 0；失败 返回 -1
int del_student_from_list(line_list_t *l,student_t *p_stu);
//更改指定顺序表中指定id的学生信息
//更改成功，返回 0；失败 返回 -1
int update_student_info(line_list_t *l);
//查询指定顺序表中指定id的学生信息
//查询成功，返回0，平p_stu传递学生信息
//失败 返回 -1
int query_student_info(line_list_t *l,student_t *p_stu);
//获取指定id在顺序表中下标
//成功，返回 下表；失败 返回 -1
int search_index_by_id(line_list_t *l,int id);
//打印所有学生信息
void print_students_info(line_list_t *l);
//输入学生信息
void input_student_info(student_t *p_stu);
//打印学生信息
void print_student_info(student_t stu);
//判断顺序表是否为满
//满。1；否则 0
int is_list_full(line_list_t *l);
//判断顺序表是否为空
//空 1;否则 0
int is_list_empty(line_list_t *l);

#endif
