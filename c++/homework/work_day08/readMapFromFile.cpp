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

	ifstream file("stu.info");
	Student *stu = NULL;
	STU_MAP::iterator iter = stu_map.begin();
	while(1)
	{
		stu = new Student;
		file >> stu;
		if(file.eof())
		{
			delete stu;
			break;
		}
		stu_map.insert(PAIR(stu->getId(),stu));
	}
	file.close();
	for(iter = stu_map.begin();iter != stu_map.end();iter++)
	{
		cout << iter->first << ' ' 
			<< "学号:" << iter->second->getId()
			<< "姓名:" << iter->second->getName()
			<< "分数:" << iter->second->getScore() << endl;
	}

	return 0;
}
