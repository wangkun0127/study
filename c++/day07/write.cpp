#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream file;
	file.open("./stu.info");
	if(file.is_open())
	{
		cout << "open file ok" << endl;
		file << "Hello World" << "^_^" << endl;
		file << 123456 << ' ' << 3.14 << endl;
	}
	else
	{
		cout << "open file failed" << endl;
	}
	file.close();

	return 0;
}
