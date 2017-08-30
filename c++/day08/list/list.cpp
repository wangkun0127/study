#include <iostream>
#include <list>

using namespace std;

typedef list<int> LIST;

void display(const LIST &l)
{
	LIST::const_iterator iter = l.begin();
	for(;iter != l.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;
}

bool compare(const int &a,const int &b)
{
	return a>b;
}

int main(void)
{
	list<int> l;
	l.push_back(78);
	l.push_back(77);
	l.push_back(65);
	l.push_back(89);
	l.push_back(92);

	l.push_front(1111);
	l.push_front(2222);
	l.push_front(3333);
	l.push_front(4444);
	l.push_front(5555);
	//l.sort();
	l.sort(compare);
	display(l);


	return 0;
}
