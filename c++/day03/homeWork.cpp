#include <iostream>
#include <string>

using namespace std;

class Goods
{
	public:
		Goods(string name,float price)
			: m_gsName(name),m_gsPrice(price)
		{}
		void show()
		{
			cout << "name:" << m_gsName 
				 << "price:" << m_gsPrice 
				 << "TotalNum:" << m_gsTotalNum << endl;
		}
	private:
		string m_gsName;
		float m_gsPrice;
		static int m_gsTotalNum;
};
int Goods::m_gsTotalNum = 1000;

class Saler
{
	public:
		Saler(string name)
		{
			m_srName = name;
			m_srTotalNum = 0;
		}
		void sale()
		{
			cout << "请输入销售数目:" << endl;
			int num = 0;
			cin >> num;
			Goods &good = Goods::show();
			m_srTotalNum +=num;
			m_gsTotalNum -=num;
			cout << m_srName << "此次卖了"
				 << num << "量，共卖了"
				 << m_srTotalNum << endl;
			cout << "货物剩余量为:" << m_gsTotalNum << endl;
		}
	private:
		string m_srName;
		int m_srTotalNum;
};

class Supermarket
{
	public:
	private:
};

int main(void)
{
	Goods t("苹果",12.5f);
	t.show();
	Saler t1("小明");
	t1.sale();
	return 0;
}
