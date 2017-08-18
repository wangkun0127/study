#include "link_list.h"
#include <stdio.h>
int main(int agrc,char *agrv[])
{
	int i=0;
	datatype_t *str=NULL;
	link_list_t l=creat_link_list_empty();
	if(is_link_list_empty(l))
		printf("link list empty\n");
	for(i=0;i<10;i++)
		insert_link_list_info(l,i+1,i);
	printf("length:%d\n",link_list_length(l));
	print_all_link_list(l);
	reverse_link_list(l);
	printf("after reverse:\n");
	print_all_link_list(l);
	insert_link_list_info(l,4,100);
	print_all_link_list(l);
	delete_link_list_info(l,1,str);
	print_all_link_list(l);
	destroy_link_list(l);
	return 0;
}
