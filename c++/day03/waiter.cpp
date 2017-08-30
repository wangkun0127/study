#include <iostream>
#include <string>

using namespace std;

class Saler
{
	public:
		Saler(string name)
		{
			m_strName = name;
			m_totalNume = 0;
		}
		void sale()
		{
			cout << "请输入销售数目:";
			int num = 0;
			cin >> num;
			m_totalNume += num;
			totalNume -= num;
			cout << m_strName << "此次卖了" 
				 << num << "量，共卖了"
				 << m_totalNume << endl;
			cout << "货物剩余量为:" << totalNume << endl;
		}
	private:
		string m_strName;
		int m_totalNume;
		static int totalNume;
};

int Saler::totalNume = 1000;

int main(void)
{
	Saler s("小米");
	s.sale();
	s.sale();
	s.sale();
	s.sale();
	return 0;
}










