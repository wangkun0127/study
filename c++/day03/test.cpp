#include <iostream>

using namespace std;

class Student
{
public:
	Student(string name,float score,const char *note)
	{
		m_strName = name;
		m_fScore = score;
		int iLen = strlen(note)+1;
		m_pNote = new char[iLen];
		strcpy(m_pNote,note);
	}
private:
	string m_strName;
	float m_fScore;
	char *m_pNote;
}

int main(void)
{
	while(1)
	{
		Student stu("张三",89,"_活得长_");
		stu.info();
	}
}
