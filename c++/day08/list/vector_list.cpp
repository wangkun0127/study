#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template<typename T>

void display(const T &data)
{
	typename T::const_iterator iter = data.begin();
	for(;iter != data.end();iter++)
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
	int a[7] = {78,89,85,74,42,45,46};
	vector<int> vec(a,a+7);
	display(vec);

	list<int> list(vec.begin(),vec.end());
	list.sort(compare);
	display(list);

	return 0;
}
