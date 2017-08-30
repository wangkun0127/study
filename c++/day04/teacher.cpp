#include <iostream>

using namespace std;

class People
{
public:
	People(string name ="newPeople",
    	string bron ="1988-08-09",
    	string addr ="shanghai",
    	string sex = "女")
	{
		m_strName = name;
		m_strBron = bron;
		m_strAddr = addr;
		m_strSex = sex;
		cout << "People(args)...\n";
    }
    void show()
    {
        cout << " name:" << m_strName
            << " bron:" << m_strBron
            << " addr:" << m_strAddr
            << " sex:" << m_strSex <<endl;
    }
private:
    string m_strName;
    string m_strBron;
    string m_strAddr;
    string m_strSex;
};

class Teacher : public People
{
	public:
		Teacher(string id = "123456",
				string course = "math",
				string level = "jiaoshi",
				float salary = 5237.12)
			//:People(name,bron,addr,sex)
		{
			m_strId = id;
			m_strCourse = course;
			m_strLevel = level;
			m_fSalary = salary;
			cout << "Teacher(args)...\n";
		}
		void info()
		{
			People::show();
			cout << m_strId << ' '
				<< m_strCourse << ' '
				<< m_strLevel << ' '
				<< m_fSalary << ' ' << endl;
		}
	private:
		string m_strId;
		string m_strCourse;
		string m_strLevel;
		float m_fSalary;

};

int main(void)
{
    Teacher p;
    p.info();
    return 0;
}
