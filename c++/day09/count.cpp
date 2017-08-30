#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename M,typename N>

int mycount(M first,M last,N vlaue)
{
	int num = 0;
	while(first != last)
	{
		if(*first == vlaue)
		{
			num++;
		}
		first++;
	}
	return num;
}

int main(void)
{
	int a[7] = {75,89,75,78,66,55,45};
	
	cout << mycount(a,a+7,66);
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	cout << endl;


	return 0;
}
