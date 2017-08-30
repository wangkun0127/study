#include <iostream>
#include <map>
#include "student.h"

using namespace std;

typedef map<float, Student *>STU_MAP;
typedef pair<float, Student *>PAIR;

int main(void)
{
	STU_MAP stu_map;
	Student *stu = new Student("小明",98);
	stu_map.insert(PAIR(stu->getScore(),stu));

	stu = new Student("小红",56);
	stu_map.insert(PAIR(stu->getScore(),stu));

	stu = new Student("小海",87);
	stu_map.insert(PAIR(stu->getScore(),stu));

	STU_MAP::iterator iter = stu_map.begin();
	for(;iter != stu_map.end();iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

	return 0;
}
