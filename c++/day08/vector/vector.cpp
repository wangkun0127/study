#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	//string str;
	vector<int> vec;
	//实际有效数据的量
	cout << vec.size() << endl;
	//实际存储空间大小
	cout << vec.capacity() << endl;
	//使用
	vec.push_back(67);
	vec.push_back(87);
	vec.push_back(77);
	vec.push_back(97);
	vec.push_back(47);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;


	for(int i = 0;i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
		//若使用下标赋值，越界不会自动增长空间
		vec[i] += 100;//不能越界
	}
	cout << endl;

	for (int i=0;i < vec.size();i++)
	{
		//vec.at()使用之前会自动越界检查，如果越界会报错
		//比使用下标直接访问更安全
		cout << vec.at(i) << ' ';
	}
	cout << endl;

	vector<int>::iterator iter;
	iter = vec.begin();
	for(;iter!=vec.end();iter++)
	{
		cout << *iter << ' ';
		*iter += 90;
		cout << *iter << ' ';
	}
	cout << endl;

	

	cout << "Hello World" << endl;
	return 0;
}
