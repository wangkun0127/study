#ifndef _FUNC_H_
#define _FUNC_H_

typedef struct teacher_info
{
	int id;
	char name[100];
	char man[20];
	char passwd[20];
	char position[20];
	char subject[20];
	int flag;
	char resign[1100];
}teacher_t;
typedef struct student_info
{
	int id;
	char name[100];
	char man[20];
	char passwd[20];
	int age;
	char clas[10];
	float math;
	//float chinese;
	float C;
	float score;
	int flag;
	char message[1100];
}stu_t;
typedef struct link_teacher
{
	teacher_t tdata;
	struct link_teacher *next;
}link_teach_t;
typedef struct link_student
{
	stu_t sdata;
	struct link_student *next;
}link_stu_t;

//char *asii_c();
//打印用户登录菜单
void login_menu(void);
/*****************************

		管理员函数

*****************************/
//管理员
void adm_login(void);
//管理员菜单
void adm_menu(void);
//检查密码
int vali_login_info(char *ch,char *num);
//处理辞职信息
int resign_info();
//添加教师信息
void add_teacher_info();
//输入教师信息
//link_teach-t *put_tdata();
//删除教师信息
void delete_teacher_info(int flag);
//写入文件
void writefile(link_teach_t *head);
//读文件
link_teach_t *readfile();
//遍历打印单链表
void print_teach_list();
//修改指定id的信息节点
void update_by_id();
//查看学生留言
void check_stu_message();
//添加辞职
void submit_regin(int ids);
//打印指定节点数据
static void print_data_info(teacher_t data);
//清空单链表
link_teach_t *clear_list();
//销毁单链表
void destery_list();
/******************************

		班主任函数

******************************/
//教师登录界面
void teach_login(int ch);
//检查密码错误
int vali_login_teach_info();
//处理辞职反馈
int faceback_resign(int ids);
//删除教师信息
void delete_me_info();
//教师界面菜单
void teach_menu(int ids);
//添加学生信息
void add_stu_info();
//遍历打印学生信息
void print_stu_list();
//打印指定节点数据
static void print_stu_data_info(stu_t data);
//删除学生信息
void delete_stu_info();
//学生按学号排序
void stu_sort();
//修改指定id的信息节点
void update_stu_by_id();
//修改教师密码
void update_teach_id(int ids);
//读到内存
link_stu_t * stu_readfile();
//写入文件
void stu_writefile(link_stu_t *head);
//清空单链表
link_stu_t *clear_stu_list();
//销毁单链表
void destery_stu_list();
/******************************

		教师函数

******************************/
//选择教师类型
void change_teach();
//普通教师登录界面
void teach2_menu(int ids);
//判断老师身份
int check_subject(int ids);
//遍历打印本学科学生信息
void print2_stu_list(int ids);
//学生按本科成绩排序
void stu2_sort(int change);
//修改指定id的信息节点
void update2_stu_by_id(int change);
/******************************

		学生函数

******************************/
//学生登陆界面
void student_login(void);
//检查密码错误
int vali_login_student_info();
//学生界面菜单
void student_menu(int ids);
//查找指定id的信息节点
void check_stu_by_id(int ids);
//修改学生密码
void update_stu_id(int ids);
//修改留言
void update_stu_message(int ids);
#endif
