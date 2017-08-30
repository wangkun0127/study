#include <iostream>

using namespace std;

class Teacher
{
	public:
		Teacher(float salary = 0.0f,
				float other = 0.0f,
				float wages = 0.0f)
		{
			m_fSalary = salary;
			m_fOther = other;
		}
		void info()
		{
			cout << m_fSalary << ' ' << m_fOther << endl;
		}
	private:
		float m_fWages;
		string m_strName;
		float m_fSalary;
		float m_fOther;
};

class Professor : public Teacher
{
	public:
		Professor()
}

int main(void)
{
	Teacher a(188.2,155.2);
	a.info();
	return 0;
}
