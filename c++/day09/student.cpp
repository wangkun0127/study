#include <iostream>
#include <algorithm>
#include <vector>
#include "student.h"

using namespace std;

template<typename M,typename N>

int mycount(M first,M last,N vlaue)
{
	int num = 0;
	while(first != last)
	{
		if(*first == vlaue)
		{
			num++;
		}
		first++;
	}
	return num;
}

bool predicate(const Student *stu)
{
	return stu->getScore() < 60;
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
	for(int i =0;i<6;i++)
	{
		cout << vec[i] << endl;
	}

	vector<Student *>::const_iterator iter = vec.begin();
	for(;iter!=vec.end();iter++)
	{
		cout << *iter << endl;
	}
	display(vec);
	cout << count_if(vec.begin(),vec.end(),predicate) << endl;



	return 0;
}
