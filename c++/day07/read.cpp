#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream file("./stu.info");
	ofstream file1("./rstu.info");
	if(file.is_open())
	{
		cout << "open file ok" << endl;
		string strName;
		int iId;
		for(int i=0;i<3;i++)
		{
			file >> strName >> iId;
			file1 << strName <<' '<< iId << ' ';
			cout << strName << ' ' << iId << endl;
		}
	}
	else
	{
		cout << "open file failed" << endl;
	}
	file.close();
	file1.close();
	return 0;
}
