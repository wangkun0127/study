#include <iostream>
#include <string.h>

using namespace std;
template<typename T>
class Student
{
	public:
		Student(string name,float score)
		{
			m_strName = name;
			m_fScore = score;
			m_iId = m_iBaseId++;
		}
		void info()
		{
			cout << " name:" << m_strName 
				<< " id:" << m_iId 
				<< " score:" << m_fScore << endl;
		}
		bool operator<(const Student &other) const
		{
			return m_fScore < other.m_fScore;
		}
		bool operator()(T &a,T &b)
		{
			return a<b;
		}
	private:
		string m_strName;
		float m_fScore;
		int m_iId;
		static int m_iBaseId;
};
int Student::m_iBaseId = 1000;

void bubble(Student *(&stu)[3])
{
	Student *tmp = NULL;
	Student<float> com;
	int i = 0;
	int j = 0;
	for(;i<3-1;i++)
	{
		for(j=0;j<3-1-i;j++)
		{
			if(com(stu[j],stu[j+1]))
			{
				tmp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = tmp;
			}
		}
	}
}

void show(Student *(&stu)[3])
{
	for(int i=0;i<3;i++)
	{
		stu[i]->info();
	}
}

int main(void)
{
	Student *pStu[3] = {NULL};
	string strName = "";
	float fScore = 0.0f;
	for(int i=0;i<3;i++)
	{
		cout << "请输入名字:" << endl;
		cin >> strName;
		cout << "请输入分数:" << endl;
		cin >> fScore;
		pStu[i] = new Student(strName,fScore);
	}
	bubble(pStu);

	show(pStu);

	return 0;
}
