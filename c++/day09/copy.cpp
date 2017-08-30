#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int a[7] = {75,89,75,78,66,55,45};
	vector<int> vec(7);

	copy(a,a+7,vec.begin());
	
	for(int i = 0;i < vec.size();i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;


	return 0;
}
