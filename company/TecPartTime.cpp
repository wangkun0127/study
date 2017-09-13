/*
 * TecPartTime.cpp
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#include "TecPartTime.h"
#include "DataSet.h"

TecPartTime::TecPartTime(string strName, uint uiLevel
		,uint fPerHourPay):Employee(strName,uiLevel) {
	// TODO Auto-generated constructor stub
	m_uiWorkHour = 0;
	m_fPerHourPay = fPerHourPay;
	//m_uiLeaderId = 0;
}

TecPartTime::~TecPartTime() {
	// TODO Auto-generated destructor stub
}

void TecPartTime::setWorkHour(uint workHour){
	m_uiWorkHour = workHour;
}
void TecPartTime::info()
{
	Employee::info();
	cout << "工作时间:" << m_uiWorkHour << " 每小时薪水:"
			<< m_fPerHourPay << " 总工资:" << m_uiWorkHour * m_fPerHourPay//<< endl;
			<< " 上级:" << m_uiLeaderId << ' ';
	cout << DataSet::getInstance().getTecManagerMap().find(m_uiLeaderId)->second->getName()
			<< endl;
}

void TecPartTime::setLearder(uint uiLeaderId){
	m_uiLeaderId = uiLeaderId;
}
uint TecPartTime::getLeader() const{
	return m_uiLeaderId;
}
uint &TecPartTime::getLearder(){
	return m_uiLeaderId;
}

uint TecPartTime::getWorkHour() const{
	return m_uiWorkHour;
}
uint &TecPartTime::getWorkHour(){
	return m_uiWorkHour;
}

uint TecPartTime::getPerHourPay() const{
	return m_fPerHourPay;
}
uint &TecPartTime::getPerHourPay(){
	return m_fPerHourPay;
}

short TecPartTime::TecworkFace(){
	cout << "\t\t************TECPT**********\n";
	cout << "\t\t*   1、显示个人基本信息   *\n";
	cout << "\t\t*   2、修改登录密码       *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short TecPartTime::modifyTecById(){
	uint uiId;
	uiId = getId();
	TecPartTime *pTecPT = NULL;
	MAP_TECPART::iterator iter;
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pTecPT = iter->second;
	}
	string passwd;
	string passwd1;
	char ch;
	cout << "请输入原密码:";
	cin >> passwd;
	if(pTecPT->getPWd() == passwd){
		cout << "请输入新密码:";
		cin >> passwd1;
		cout << "确认修改(Y/N):";
		cin >> ch;
		if('Y' == ch||'y' == ch)
		{
			pTecPT->getPWd()=passwd1;
			cout << "密码已修改，请重新登录^_^" << endl;
		}
		else
		{
			cout << "已取消修改！\n";
		}
	}
	else
	{
		cout << "原密码输入错误！！！\n";
		return 0;
	}
	DataSet::getInstance().getTecPartMap().insert(
									PAIR_TECPART(uiId,pTecPT));
	return 1;
}
void TecPartTime::work(){
	system("clear");
	cout << "正在为您跳转界面...\n";
	sleep(3);
	system("clear");
	cout << "\t\t        欢迎" << getName() << "登入" << endl;
	short num  = 0;
	while(1)
	{
		num = TecworkFace();
		switch(num)
		{
		case 1:
			info();
			break;
		case 2:
			if(1 == modifyTecById())
			{
				return;
			}
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}


