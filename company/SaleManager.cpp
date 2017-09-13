/*
 * SaleManager.cpp
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#include "SaleManager.h"
#include "DataSet.h"

SaleManager::SaleManager(string strName,float SaleSalary,float fPerSale)
			:SalePartTime(strName,ENUM_EMPLOYEE_LEVEL_MANAGET_SALE)
			,Employee(strName,ENUM_EMPLOYEE_LEVEL_MANAGET_SALE)
{
	// TODO Auto-generated constructor stub
	m_fPerSale = fPerSale;
	m_fSaleSalary = SaleSalary;
	m_uiSaleMoney = 0;
}

SaleManager::~SaleManager() {
	// TODO Auto-generated destructor stub
}
void SaleManager::info(){
	Employee::info();
	cout << "销售额:" << m_uiSaleMoney << " 工资占比:" << m_fPerSale <<
			" 基础工资:" << m_fSaleSalary << endl;
	cout << "--工资:" << m_uiSaleMoney*m_fPerSale+m_fSaleSalary << endl;
}
void SaleManager::setSaleMoney(uint uiId,float saleMoney){
	uint uiid;
	SalePartTime* pTecPT = NULL;
	pTecPT = findSalePartTime(uiId);
	uiid = pTecPT->getSaleLeader();
	SaleManager* pTecMA = NULL;
	MAP_SALEMA::iterator iter;
	MAP_SALEMA &refMa = DataSet::getInstance().getSaleManagerMap();
	iter = refMa.find(uiid);
	if(iter != refMa.end())
	{
		pTecMA = iter->second;
	}
	pTecMA->getuiSaleMoney()= pTecMA->getuiSaleMoney()+saleMoney;
	DataSet::getInstance().getSaleManagerMap().insert(
								PAIR_SALEMA(uiid,pTecMA));


}
void SaleManager::setSaleSalary(float Salary){
	m_fSaleSalary = Salary;
}

float  SaleManager::getSaleSalary() const{
	return m_fSaleSalary;
}
float &SaleManager::getSaleSalary(){
	return m_fSaleSalary;
}
float SaleManager::getPerSale() const{
	return m_fPerSale;
}
float &SaleManager::getPerSale(){
	return m_fPerSale;
}

float SaleManager::getuiSaleMoney() const{
	return m_uiSaleMoney;
}
float &SaleManager::getuiSaleMoney(){
	return m_uiSaleMoney;
}

//对员工的增删改查
void SaleManager::addSalePartTime(uint uiId){
	string strName;
	cout << "请输入兼职销售人员姓名:";
	cin >> strName;
	if(0 == uiId)
	{
		uiId = getId();
	}
	SalePartTime *pSalePT = new SalePartTime(strName);
	pSalePT->setSaleLeaderId(uiId);
	DataSet::getInstance().getSalePartMap().insert(
			PAIR_SALEPART(pSalePT->getId(),pSalePT));
	cout << DataSet::getInstance().getSalePartMap().size() << endl;
}
void SaleManager::delSalePartTimeById(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要删除的员工编号:";
		cin >> uiId;
	}
	MAP_SALEPART::iterator iter;
	MAP_SALEPART &refMap = DataSet::getInstance().getSalePartMap();
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
void SaleManager::modifySalePartTime(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要修改的兼职技术人员编号:";
		cin >> uiId;
	}
	float saleMoney;
	string strNote;
	SalePartTime* pTecPT = NULL;
	pTecPT = findSalePartTime(uiId);
	cout << "请输入销售额:";
	cin >> saleMoney;
	setSaleMoney(uiId,saleMoney);
	pTecPT->getSaleMoney() = saleMoney;
	cout << "请输入说明:";
	cin >> pTecPT->getNote();

	DataSet::getInstance().getSalePartMap().insert(
							PAIR_SALEPART(uiId,pTecPT));
}
SalePartTime *SaleManager::findSalePartTime(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入你要查找的销售人员的编号:";
		cin >> uiId;
	}
	SalePartTime *pSalePT = NULL;
	MAP_SALEPART::iterator iter;
	MAP_SALEPART &refMap = DataSet::getInstance().getSalePartMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pSalePT = iter->second;
	}
	return pSalePT;
}
void SaleManager::displaySalePartTimeinfo(){
	MAP_SALEPART &refMap = DataSet::getInstance().getSalePartMap();
	cout << refMap.size() << endl;
	MAP_SALEPART::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		iter->second->info();
	}
}
short SaleManager::SalePartTimeFace(){
	cout << "\t\t***********SALEMA**********\n";
	cout << "\t\t*   1、增加兼职销售人员   *\n";
	cout << "\t\t*   2、显示兼职销售人员   *\n";
	cout << "\t\t*   3、删除兼职销售人员   *\n";
	cout << "\t\t*   4、查找兼职销售人员   *\n";
	cout << "\t\t*   5、修改兼职销售人员   *\n";
	cout << "\t\t*   6、查看个人基本信息   *\n";
	cout << "\t\t*   7、修改个人密码       *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short SaleManager::SalePartTimeFaceByBoss(){
	cout << "\t\t***********SALEMA**********\n";
	cout << "\t\t*   1、增加兼职销售人员   *\n";
	cout << "\t\t*   2、显示兼职销售人员   *\n";
	cout << "\t\t*   3、删除兼职销售人员   *\n";
	cout << "\t\t*   4、查找兼职销售人员   *\n";
	cout << "\t\t*   5、修改兼职销售人员   *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short SaleManager::modifySaleManagerById(){
	uint uiId;
	uiId = getId();
	SaleManager *pSaleMA = NULL;
	MAP_SALEMA::iterator iter;
	MAP_SALEMA &refMap = DataSet::getInstance().getSaleManagerMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pSaleMA = iter->second;
	}
	string passwd;
	string passwd1;
	char ch;
	cout << "请输入原密码:";
	cin >> passwd;
	if(pSaleMA->getPWd() == passwd){
		cout << "请输入新密码:";
		cin >> passwd1;
		cout << "确认修改(Y/N):";
		cin >> ch;
		if('Y' == ch||'y' == ch)
		{
			pSaleMA->getPWd()=passwd1;
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
	DataSet::getInstance().getSaleManagerMap().insert(
										PAIR_SALEMA(uiId,pSaleMA));
	return 1;
}
void SaleManager::work(){
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
			num = SalePartTimeFaceByBoss();
		}
		else
		{
			num = SalePartTimeFace();
		}
		switch(num)
		{
		case 1:
			if(10000 == getId())
			{
				cout << "请输入所属销售经理的id:";
				cin >> uiId;
			}
			addSalePartTime(uiId);
			break;
		case 2:
			displaySalePartTimeinfo();
			break;
		case 3:
			delSalePartTimeById(uiId);
			break;
		case 4:
			findSalePartTime(uiId)->SalePartTime::info();
			break;
		case 5:
			modifySalePartTime(uiId);
			break;
		case 6:
			info();
			break;
		case 7:
			modifySaleManagerById();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}

