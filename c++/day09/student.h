#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>

using namespace std;

class Student
{
	public:
		Student(string name ="NewStu",
				float score = 0.0f)
		{
			m_strName = name;
			m_fScore = score;
			m_iId = m_iBaseId++;
		}
		int getId() const
		{
			return m_iId;
		}
		float getScore() const
		{
			return m_fScore;
		}
		const string getName() const
		{
			return m_strName;
		}
		friend ostream &operator<<(ostream &out,const Student &stu);
		friend istream &operator>>(istream &in,Student &stu);
		friend istream &operator>>(istream &in,Student *stu);
	private:
		int m_iId;
		static int m_iBaseId;
		string m_strName;
		float m_fScore;
};
int Student::m_iBaseId = 1000;

ostream &operator<<(ostream &out,const Student &stu)
{
	out << stu.m_iId << stu.m_strName << stu.m_fScore;
	return out;
}

ostream &operator<<(ostream  &out,const Student *stu)
{
	out << stu->getId() << ' ' << stu->getName() << ' ' << stu->getScore();
	return out;
}

istream &operator>>(istream &in,Student &stu)
{
	in >> stu.m_iId >> stu.m_strName >> stu.m_fScore;
	return in;
}

istream &operator>>(istream &in,Student *stu)
{
	in >> stu->m_iId >> stu->m_strName >> stu->m_fScore;
	return in;
}

#endif
