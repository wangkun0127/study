#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main(int argc,char *argv[])
{
	int select_no=0;
	student_t stu;
	line_list_t list;

	memset(&stu,0,sizeof(stu));
	memset(&list,0,sizeof(list));

	while(1)
	{
		system("clear");
		memset(&stu,0,sizeof(stu));
		print_menu();

		scanf("%d",&select_no);

		switch(select_no)
		{
			case MENU_ITEM_ADD:
				input_student_info(&stu);
				add_student_to_list(&list,stu);
				break;
			case MENU_ITEM_DEL:
				del_student_from_list(&list,&stu);
				break;
			case MENU_ITEM_UPDATE:
				update_student_info(&list);
				break;
			case MENU_ITEM_QUERY:
				query_student_info(&list,&stu);
				break;
			case MENU_ITEM_PRINT:
				print_students_info(&list);
				break;
			case MENU_ITEM_EXIT:
				printf("Bay!!!!\n");
				exit(0);
				break;
			default:
				break;
		}
		while(getchar()!='\n');
		printf("请输入回车继续！");
		while(getchar() != '\n');
	}

	return 0;

}
