#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>
#include <string>
#include <string.h>


using namespace std;

class Input
{
	public:
		Input()
		{
			m_strData.clear();
		}
		~Input(){}
		//清空输入设备数据
		void clearData()
		{
			m_strData.clear();
		}

		void InputData()
		{
			cout << "请输入数据:";
			cin >> m_strData;
		}
		const string &getData()
		{
			return m_strData;
		}
		string dataType()
		{
			string strType= "";
			if (0 == strncmp("ca",m_strData.c_str(),2))
			{
				strType= "ca";
			}
			else if(0 == strncmp("pa",m_strData.c_str(),2))
			{
				strType= "pa";
			}
			else if (0 == strncmp("fi",m_strData.c_str(),2))
			{
				strType= "fi";
			}
			return strType;
		}
	private:
		string m_strData;
};


#endif
