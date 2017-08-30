#include <iostream>

using namespace std;

template<typename T,typename M>

class Sort
{
	public:
		void sort(T *addr,int count,M &com)
		{
			int i = 0;
			int j = 0;
			T tmp;
			for(;i<count-1;i++)
			{
				for(j=0;j<count-1-i;j++)
				{
					if(com(addr[j],addr[j+1]))
					{
						tmp = addr[j];
						addr[j] = addr[j+1];
						addr[j+1] = tmp;
					}
				}
			}
		}
};

template<typename T>
class MyLess
{
	public:
		bool operator()(T &a,T &b)
		{
			return a<b;
		}
};
template<typename T>
class MyGreater
{
	public:
		bool operator()(T &a,T &b)
		{
			return a>b;
		}
};

template<typename T>
void display(T *addr,int count)
{
	for(int i=0;i<count;i++)
	{
		cout << addr[i] << ' ';
	}
	cout << endl << "-------------------------------" << endl;

};

int main(void)
{
	int a[6] = {12,45,25,78,96,85};
	display(a,6);

	Sort<int,MyLess<int> > s;
	MyLess<int> less;
	s.sort(a,6,less);
	display(a,6);

	Sort<int,MyGreater<int> > h;
	MyGreater<int> greater;
	h.sort(a,6,greater);
	display(a,6);
	return 0;
}
