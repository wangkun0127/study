#include <iostream>

using namespace std;

class A
{
	public:
		int m_a;
		void show()
		{
			cout << "this is A::show()\n";
		}
};

class B :public A
{
	public:
		int m_b;
		void show()
		{
			cout << "this is B::show()\n";
		}
};

//class C
//{

//};

int main(void)
{
	A a;
	a.m_a = 11;
	cout << a.m_a << endl;

	B b;
	b.m_a = 22;
	b.m_b = 33;
	cout << b.m_a << endl << b.m_b << endl;

	//在默认情况下，派生类对象可以赋值给基类对象
	//a=b
	//在默认情况下，基类对象不可以赋值给派生类对象
	//b=a//error


	return 0;
}
