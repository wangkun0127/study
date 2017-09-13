/*
 * TecManager.cpp
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#include "TecManager.h"
#include "DataSet.h"

TecManager::TecManager(string strName, uint fSalary)
		:TecPartTime(strName,ENUM_EMPLOYEE_LEVEL_MANAGER_TEC)
			, Employee(strName, ENUM_EMPLOYEE_LEVEL_MANAGER_TEC)
{
	// TODO Auto-generated constructor stub
	m_fSalary = fSalary;
}

TecManager::~TecManager() {
	// TODO Auto-generated destructor stub
}

void TecManager::info(){
	Employee::info();
	cout << "--工资:" << m_fSalary << endl;
}
void TecManager::setSalary(uint Salary){
	m_fSalary = Salary;
}

uint TecManager::getSalary() const{
	return m_fSalary;
}
uint &TecManager::getSalary(){
	return m_fSalary;
}
void TecManager::addTecPartTime(uint uiId){
	string strName;
	cout << "请输入兼职技术人员的名字:";
	cin >> strName;
	if(0 == uiId)
	{
		uiId = getId();
	}
	TecPartTime *pTecPT = new TecPartTime(strName);
	pTecPT->setLearder(uiId);
	DataSet::getInstance().getTecPartMap().insert(
			PAIR_TECPART(pTecPT->getId(),pTecPT));
	cout << DataSet::getInstance().getTecPartMap().size() << endl;
}
void TecManager::delTecPartTimeById(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要删除的员工编号:";
		cin >> uiId;
	}
	MAP_TECPART::iterator iter;
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		delete iter->second;
		refMap.erase(iter);
		cout << "删除编号为:" << uiId << "的员工成功...\n";
	}
	else
	{
		cout << "没有编号为:" << uiId << "的员工...\n";
	}
}

TecPartTime* TecManager::findTecPartTime(uint uiId){
//void TecManager::findTecPartTime(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要查找的兼职技术人员编号:";
		cin >> uiId;
	}
	TecPartTime* pTecPT = NULL;
	MAP_TECPART::iterator iter;
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pTecPT = iter->second;
	}
	//pTecPT->info();
	return pTecPT;
}
void TecManager::modifyTecPartTime(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要修改的兼职技术人员编号:";
		cin >> uiId;
	}
	uint workHour;
	string strNote;
	TecPartTime* pTecPT = NULL;
	pTecPT = findTecPartTime(uiId);
	cout << "请输入工作时间:";
	cin >> workHour;
	cout << "请输入说明:";
	cin >> pTecPT->getNote();
	pTecPT->setWorkHour(workHour);
	DataSet::getInstance().getTecPartMap().insert(
						PAIR_TECPART(uiId,pTecPT));
}
void TecManager::displayTecPartTimeinfo(){
	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	cout << refMap.size() << endl;
	MAP_TECPART::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		iter->second->info();
	}
}

short TecManager::TecPartTimeFace(){
	cout << "\t\t***********TECMA***********\n";
	cout << "\t\t*   1、增加兼职技术人员   *\n";
	cout << "\t\t*   2、显示兼职技术人员   *\n";
	cout << "\t\t*   3、删除兼职技术人员   *\n";
	cout << "\t\t*   4、查找兼职技术人员   *\n";
	cout << "\t\t*   5、修改兼职技术人员   *\n";
	cout << "\t\t*   6、查看个人基本信息   *\n";
	cout << "\t\t*   7、修改个人密码       *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}

short TecManager::TecPartTimeFaceByBoss(){
	cout << "\t\t***********TECMA***********\n";
	cout << "\t\t*   1、增加兼职技术人员   *\n";
	cout << "\t\t*   2、显示兼职技术人员   *\n";
	cout << "\t\t*   3、删除兼职技术人员   *\n";
	cout << "\t\t*   4、查找兼职技术人员   *\n";
	cout << "\t\t*   5、修改兼职技术人员   *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short TecManager::modifyTecManagerById(){
	uint uiId;
	uiId = getId();
	TecManager *pTecMA = NULL;
	MAP_TECMA::iterator iter;
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pTecMA = iter->second;
	}
	string passwd;
	string passwd1;
	char ch;
	cout << "请输入原密码:";
	cin >> passwd;
	if(pTecMA->getPWd() == passwd){
		cout << "请输入新密码:";
		cin >> passwd1;
		cout << "确认修改(Y/N):";
		cin >> ch;
		if('Y' == ch||'y' == ch)
		{
			pTecMA->getPWd()=passwd1;
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
	DataSet::getInstance().getTecManagerMap().insert(
										PAIR_TECMA(uiId,pTecMA));
	return 1;
}
void TecManager::work(){
	if(10000 != getId())
	{
		system("clear");
		cout << "正在为您跳转界面...\n";
		sleep(3);
		system("clear");
	}
	cout << "\t\t       欢迎" << getName() << "登入" << endl;
	short num  = 0;

	while(1)
	{
		uint uiId = 0;
		if(10000 == getId())
		{
			num = TecPartTimeFaceByBoss();
		}
		else
		{
			num = TecPartTimeFace();
		}
		switch(num)
		{
		case 1:
			if(10000 == getId())
			{
				cout << "请输入所属技术经理的id:";
				cin >> uiId;
			}
			addTecPartTime(uiId);
			break;
		case 2:
			displayTecPartTimeinfo();
			break;
		case 3:
			delTecPartTimeById(uiId);
			break;
		case 4:
			findTecPartTime(uiId)->TecPartTime::info();
			//findTecPartTime(uiId);
			break;
		case 5:
			modifyTecPartTime(uiId);
			break;
		case 6:
			info();
			break;
		case 7:
			if(0 == modifyTecManagerById())
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


