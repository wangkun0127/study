#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class MyString
{
public:
	MyString()
	{
		m_pData = NULL;
		cout << "MyString()\n";
	}
	MyString(const char *pData)
	{
		m_pData = NULL;
		if(NULL != pData)
		{
			m_pData = new char[strlen(pData)+1];
			if(NULL==m_pData)
			{
				exit(EXIT_FAILURE);
			}
			strcpy(m_pData,pData);
		}
		cout << "MyString(const char *)\n";
	}
	const char *data()
	{
		return m_pData;
	}
	int length()
	{
		int iLen = 0;
		if(NULL!=m_pData)
		{
			iLen = strlen(m_pData);
		}
		return iLen;
	}
	const MyString &operator=(const MyString &other)
	{
		//若本身原有数据，先将原数据删除
		if(NULL != m_pData)
		{
			delete []m_pData;
			m_pData = NULL;
		}
		if(NULL != other.m_pData)
		{
			m_pData = new char[strlen(other.m_pData)];
			strcpy(m_pData,other.m_pData);
		}
		cout << "operator=\n";
		return *this;
	}
	MyString operator+(const MyString &other) const
	{
		MyString str;
		int iLen1 = strlen(m_pData);
	}
	~MyString()
	{
		cout << "~MyString()\n";
		if(NULL!=m_pData)
		{
			delete []m_pData;
		}
	}
private:
	char *m_pData;
};

int main(void)
{
	MyString s1("Hello World");
	MyString s2("123");
	cout << "s1:" << s1.data() << endl;
	cout << "s2:" << s2.data() << endl;

	s2 = s1;
	s2.operator=(s1);
	cout << "s1:" << s1.data() << endl;
	cout << "s2:" << s2.data() << endl;

	//cout << "s2[0]=" << s2[0] << endl;
	return 0;
}


