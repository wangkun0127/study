#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	//string str;
	vector<int> vec;
	vec.push_back(67);
	vec.push_back(88);
	vec.push_back(77);
	vec.push_back(92);
	vec.push_back(47);

	vector<int>::iterator iter;
	iter = vec.begin();
	int oddSum =0;
	int evenSum = 0;
	for(;iter!=vec.end();iter++)
	{
		if(0==*iter%2)
		{
			evenSum += *iter;
		}
		else if(0!=*iter%2)
		{
			oddSum += *iter;
		}
	}
	cout << "奇数之和:" << oddSum
		<< "偶数之和:" << evenSum << endl;

	cout << "Hello World" << endl;
	return 0;
}
