#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Student
{
	public:
		Student(string name ="",float score = 0.0f)
		{
			m_strName = name;
			m_fScore  = score;
		}
		const string &getName() const
		{
			return m_strName;
		}
		float getScore() const
		{
			return m_fScore;
		}
		bool operator<(const Student &stu)
		{
			return m_fScore < stu.m_fScore;
		}
	private:
		string m_strName;
		float m_fScore;
};

ostream &operator<<(ostream &out,const Student &stu)
{
	out << stu.getName() << ' ' << stu.getScore();
	return out;
}

bool compare(const int &a,const int &b)
{
	return a>b;
}

int main(void)
{
	int a[7] = {12,45,56,58,87,89,78};

	//sort(a,a+7);//[)
	sort(a,a+7,compare);//[)
	for(int i=0;i<7;i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
