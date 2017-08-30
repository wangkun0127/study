#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
	public:
		Student(string name = "",int id = 123)
		{
			m_strName = name;
			m_iId = id;
		}
	//private:
		string m_strName;
		int m_iId;
};

int main(void)
{
	Student s("小明",1000);
	//Student s("小海"，1001);
	//Student s("小强"，1002);
	ofstream file;
	file.open("./stu.info");
	if(file.is_open())
	{
		cout << "open file ok" << endl;
		file << s.m_strName << ' ' << s.m_iId << endl;
	}
	else
	{
		cout << "file open failed" << endl;
	}
	file.close();

	return 0;
}
