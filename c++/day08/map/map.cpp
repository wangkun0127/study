#include <iostream>
#include <map>
#include <string>

using namespace std;

void display(const map<int,string> &m)
{
	map<int,string>::const_iterator iter = m.begin();
	for(;iter!=m.end();iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}

}

int main(void)
{
	map<int,string> stu;
	pair<int,string> p(1001,"aa");
	stu.insert(p);
	stu.insert(pair<int,string>(1006,"ff"));
	stu.insert(pair<int,string>(1002,"bb"));
	stu.insert(pair<int,string>(1008,"aa"));
	stu.insert(pair<int,string>(1003,"gg"));
	stu.insert(pair<int,string>(1005,"vv"));
	stu.insert(pair<int,string>(1004,"kk"));
	stu.insert(pair<int,string>(1007,"tt"));
	display(stu);

	return 0;
}
