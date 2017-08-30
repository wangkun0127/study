#include <iostream>
#include <algorithm>
#include <vector>
#include "student.h"

using namespace std;

bool predicate(const Student *stu)
{
	return stu->getName() == "小林";
}

void display(const vector<Student *> &vec)
{
	vector<Student *>::const_iterator iter = vec.begin();
	for(;iter!=vec.end();iter++)
	{
		cout << *iter << endl;
	}
	
}

int main(void)
{
	vector<Student *> vec;
	vec.push_back(new Student("小明",89));
	vec.push_back(new Student("小花",74));
	vec.push_back(new Student("小华",45));
	vec.push_back(new Student("小海",52));
	vec.push_back(new Student("小林",78));
	vec.push_back(new Student("小坤",85));
	display(vec);
	vector<Student *>::iterator iter;
	iter = find_if(vec.begin(),vec.end(),predicate);
	if(iter!=vec.end())
	{
		cout << *iter << endl;
	}
	else
	{
		cout << "no match\n";
	}


	return 0;
}
