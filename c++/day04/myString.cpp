#include <iostream>

using namespace std;

class MyString
{
public:
    MyString()
    {
        m_pData = NULL;
        cout << "MyString\n";
    }
    MyString(const char *pData)
    {
        m_pData = NULL;
        if(NULL != pData)
        {
            m_pData = new char[strlen(pData)];
        }
    }
    MyString(const MyString &other)
    {}
    const char *data
    {}
    int length()
    {}
    ~MyString()
    {}
private:
    char *m_pData;
}

int main(void)
{
    return 0;
}