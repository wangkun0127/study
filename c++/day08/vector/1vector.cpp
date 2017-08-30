#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display(const vector<int> &vec)
{
	for(int i = 0;i<vec.size();i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int a[7] = {89,76,56,45,98,88,67};
	vector<int> vec(a,a+7);
	display(vec);
	
	vector<int>::iterator iter = vec.begin();
	iter++;
	iter++;
	//若空间不够自动增长
	//vec.insert(iter,888);//在指定位置插入888
//	vec.insert(iter,3,888);//在指定位置插入3个888
//	display(vec);

	int a2[5] = {189,178,165,157,189};
	vector<int> vec2(a2,a2+5);
	vec.insert(iter,vec2.begin(),vec2.end());
	display(vec);
	
	cout << "Hello World" << endl;
	return 0;
}
