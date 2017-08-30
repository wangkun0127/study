#include "student.h"
#include <map>
#include <string>

using namespace std;

int main(void)
{
	STU_MAP stu_map;
	Student *stu = new Student("张三"，89);
	stu_map.insert(PAIR(stu->getId(),stu));

	stu = new Student("李四"，56);
	stu_map.insert(PAIR(stu->getId(),stu));
	stu = new Student("小敏"，78);
	stu_map.insert(PAIR(stu->getId(),stu));
	stu = new Student("小美"，98);
	stu_map.insert(PAIR(stu->getId(),stu));

	STU_MAP::iterator iter = stu_map.begin();
	for(;iter != stu_map.end();iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
	return 0;
}
