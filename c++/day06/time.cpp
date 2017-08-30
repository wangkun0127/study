#include <iostream>
#include <unistd.h>

using namespace std;

class Time
{
	public:
		Time(int minute = 0,int second = 0)
		{
			m_iMinute = minute;
			m_iSecond = second;
		}
		void display()
		{
			cout << m_iMinute << ':' << m_iSecond << endl;
		}
		Time operator--()
		{
			m_iSecond--;
			if(0==m_iSecond)
			{
				m_iSecond = 59;
				m_iMinute--;
				if(0==m_iMinute)
				{
					m_iMinute = 59;
				}
			}
			return *this;
		}
	private:
		int m_iMinute;
		int m_iSecond;

};

int main(void)
{
	Time t(59,56);
	t.display();

	Time t2=--t;
	t.display();
	t2.display();
	return 0;
}
