#include "list.h"
#include "student.h"

int main(void)
{
	List<int> int_list;
	int_list.insert(67);
	int_list.insert(87);
	int_list.insert(72);
	int_list.insert(79);
	int_list.sort();

	List<int>::iterator iter = int_list.begin();
	for(;iter != int_list.end(); iter++)
	{
		cout << *iter << endl;
	}


	return 0;
}
