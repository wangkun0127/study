#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <iostream>
#include <string>
#include <list>
#include "check.h"

using namespace std;

typedef list<string> LIST;
typedef list<string>::iterator ITER_LIST;

class CComputer
{
	public:
		CComputer();
		~CComputer();

		void addData(string data,string sign);

		const LIST &getPwdList();
		const LIST &getCardList();
		const LIST &getFingerList();

		bool check(const string &str,const string &type)
		{
			bool bOk = false;
			if("pa" == type)
			{
				m_pCheck = &(PwdCheck::getInstance());
				bOk = m_pCheck->check(str,m_pwdList);
			}
			else if("ca" == type)
			{
				m_pCheck = &(CardCheck::getInstance());
				bOk = m_pCheck->check(str,m_cardList);
			}
			else if("fi" == type)
			{
				m_pCheck = &(FingerCheck::getInstance());
				bOk = m_pCheck->check(str,m_fingerList);
			}
			return bOk;
		}
	private:
		LIST m_pwdList;
		LIST m_cardList;
		LIST m_fingerList;
	//public:
		Check *m_pCheck;
};

#endif
