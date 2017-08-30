#include <iostream>

using namespace std;

class A
{
	public:
		A(int a): m_a(a){}
		//将一个函数申明为类的友元函数
		//则在该函数中可以通过该类对象直接访问同类的私有数据

		//友元破坏了类的封装性
		//能不用尽量不用
		friend void fun(const A &a);
		//将类B申明为类A的友元类
		//则在类B中所有成员函数中
		//可以通过类A对象
	private:
		int m_a;
};

class B
{
	public:
		void test(A &a)
		{
			cout << a.m_a << endl;
			a.m_a = 999;
			cout << a.m_a << endl;
		}
};

void fun(const A &a)
{
	cout << a.m_a << endl;
}

int main(void)
{
	A a(90);
	fun(a);
	B b;
	b.test(a);

	return 0;
}
