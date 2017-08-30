#include <iostream>
#include <map>
#include "student.h"
#include <fstream>

using namespace std;

typedef map<int, Student *>STU_MAP;
typedef pair<int, Student *>PAIR;

int main(void)
{
	STU_MAP stu_map;
	Student *stu = new Student("小明",98);
	stu_map.insert(PAIR(stu->getId(),stu));

	stu = new Student("小红",56);
	stu_map.insert(PAIR(stu->getId(),stu));

	stu = new Student("小海",87);
	stu_map.insert(PAIR(stu->getId(),stu));

	ofstream file("stu.info");
	STU_MAP::iterator iter = stu_map.begin();
	for(;iter != stu_map.end();iter++)
	{
		file << iter->second << endl;
	}
	file.close();

	return 0;
}
