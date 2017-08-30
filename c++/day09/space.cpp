#include <iostream>
using namespace std;

namespace myspace
{
	void fun()
	{
		cout << "fun()..." << endl;
	}
}

int main(void)
{
	myspace::fun();
	cout << "Hello World" << endl;
	return 0;
}
