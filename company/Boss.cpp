/*
 * Boss.cpp
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#include "Boss.h"
#include "DataSet.h"

Boss::Boss(string strName):
				Employee(strName, ENUM_EMPLOYEE_LEVEL_BOSS),TecManager(strName),
				SaleManager(strName)
{
	// TODO Auto-generated constructor stub

}

Boss::~Boss() {
	// TODO Auto-generated destructor stub
}

void Boss::info(){
	Employee::info();
}

//对技术经理增删改查
void Boss::addTecManager(){
	string strName;
	cout << "请输入技术经理的姓名:";
	cin >> strName;
	TecManager *pTecMa = new TecManager(strName);
	DataSet::getInstance().getTecManagerMap().insert(
			PAIR_TECMA(pTecMa->getId(),pTecMa));
}
void Boss::delTecManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要删除的员工编号:";
		cin >> uiId;
	}
	MAP_TECMA::iterator iter;
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
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
void Boss::modifyTecManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要修改的技术经理的编号:";
		cin >> uiId;
	}
	uint Salary;
	string strNote;
	TecManager* pTecPT = NULL;
	pTecPT = findTecManager(uiId);
	cout << "请输入工作月薪:";
	cin >> Salary;
	cout << "请输入说明:";
	cin >> pTecPT->getNote();

	pTecPT->setSalary(Salary);
	DataSet::getInstance().getTecManagerMap().insert(
							PAIR_TECMA(uiId,pTecPT));
}
TecManager* Boss::findTecManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要查找的技术经理的id:";
		cin >> uiId;
	}
	TecManager* pTecMA = NULL;
	MAP_TECMA::iterator iter;
	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pTecMA = iter->second;
	}
	return pTecMA;
}
void Boss::displayTecManager(){
	MAP_TECMA &refMa = DataSet::getInstance().getTecManagerMap();
	MAP_TECMA::iterator iter = refMa.begin();
	for (;iter != refMa.end(); iter++)
	{
		iter->second->info();
	}
}

//对技术经理增删改查
void Boss::addSaleManager(){
	string strName;
	cout << "请输入销售经理的姓名:";
	cin >> strName;
	SaleManager *pTecMa = new SaleManager(strName);
	DataSet::getInstance().getSaleManagerMap().insert(
				PAIR_SALEMA(pTecMa->getId(),pTecMa));
}
void Boss::delSaleManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要删除的员工编号:";
		cin >> uiId;
	}
	MAP_SALEMA::iterator iter;
	MAP_SALEMA &refMap = DataSet::getInstance().getSaleManagerMap();
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
void Boss::modifySaleManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要修改的销售经理的编号:";
		cin >> uiId;
	}
	uint Salary;
	string strNote;
	SaleManager* pTecPT = NULL;
	pTecPT = findSaleManager(uiId);
	cout << "请输入工作月薪:";
	cin >> Salary;
	cout << "请输入说明:";
	cin >> pTecPT->getNote();

	pTecPT->setSaleSalary(Salary);
	DataSet::getInstance().getSaleManagerMap().insert(
								PAIR_SALEMA(uiId,pTecPT));
}
SaleManager* Boss::findSaleManager(uint uiId){
	if(0 == uiId)
	{
		cout << "请输入要查找的销售经理的id:";
		cin >> uiId;
	}
	SaleManager* pSaleMA = NULL;
	MAP_SALEMA::iterator iter;
	MAP_SALEMA &refMa = DataSet::getInstance().getSaleManagerMap();
	iter = refMa.find(uiId);
	if(iter != refMa.end())
	{
		pSaleMA = iter->second;
	}
	return pSaleMA;
}
void Boss::displaySaleManager(){
	MAP_SALEMA &refMa = DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMA::iterator iter = refMa.begin();
	for (;iter != refMa.end(); iter++)
	{
		iter->second->info();
	}
}

short Boss::BossFace(){

	cout << "\t\t************BOSS************\n";
	cout << "\t\t*   1、对技术经理操作      *\n";
	cout << "\t\t*   2、对销售经理操作      *\n";
	cout << "\t\t*   3、对兼职技术人员操作  *\n";
	cout << "\t\t*   4、对兼职销售人员操作  *\n";
	cout << "\t\t*   5、显示所有员工信息    *\n";
	cout << "\t\t*   0、返回                *\n";
	cout << "\t\t****************************\n";
	cout << "请输入选项:";
	short ch = 0;
	cin >> ch;
	return ch;
}
short Boss::TecManagerFace(){
	cout << "\t\t*******TECMANAGER*******\n";
	cout << "\t\t*   1、增加技术经理    *\n";
	cout << "\t\t*   2、显示技术经理    *\n";
	cout << "\t\t*   3、删除技术经理    *\n";
	cout << "\t\t*   4、查找技术经理    *\n";
	cout << "\t\t*   5、修改技术经理    *\n";
	cout << "\t\t*   0、返回            *\n";
	cout << "\t\t************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short Boss::SaleManagerFace(){
	cout << "\t\t*******SALEMANAGER*******\n";
	cout << "\t\t*   1、增加销售经理     *\n";
	cout << "\t\t*   2、显示销售经理     *\n";
	cout << "\t\t*   3、删除销售经理     *\n";
	cout << "\t\t*   4、查找销售经理     *\n";
	cout << "\t\t*   5、修改销售经理     *\n";
	cout << "\t\t*   0、返 回            *\n";
	cout << "\t\t*************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short Boss::TecPartTimeFace(){
	TecManager::TecPartTimeFaceByBoss();
}
short Boss::SalePartTimeFace(){
	SaleManager::SalePartTimeFaceByBoss();
}

void Boss::operatorToTecManager(){
	short num  = 0;
	uint uiId = 0;
	while(1)
	{
		num = TecManagerFace();
		switch(num)
		{
		case 1:
			addTecManager();
			break;
		case 2:
			displayTecManager();
			break;
		case 3:
			delTecManager(uiId);
			break;
		case 4:
			findTecManager(uiId)->TecManager::info();
			break;
		case 5:
			modifyTecManager(uiId);
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}
void Boss::operatorToSaleManager(){
	short num  = 0;
	uint uiId = 0;
	while(1)
	{
		num = SaleManagerFace();
		switch(num)
		{
		case 1:
			addSaleManager();
			break;
		case 2:
			displaySaleManager();
			break;
		case 3:
			delSaleManager(uiId);
			break;
		case 4:
			findSaleManager(uiId)->SaleManager::info();
			break;
		case 5:
			modifySaleManager(uiId);
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}
void Boss::operatorToTecPartTime(){
	TecManager::work();
}
void Boss::operatorToSalePartTime(){
	SaleManager::work();
}

void Boss::TotalInfo(){
	MAP_TECMA::iterator iter1;
		MAP_TECMA &refMap1 = DataSet::getInstance().getTecManagerMap();
		iter1 = refMap1.begin();
		for(;iter1 != refMap1.end();iter1++)
		{
			iter1->second->TecManager::info();
		}
		MAP_SALEMA::iterator iter2;
		MAP_SALEMA &refMap2 = DataSet::getInstance().getSaleManagerMap();
		iter2 = refMap2.begin();
		for(;iter2 != refMap2.end();iter2++)
		{
			iter2->second->SaleManager::info();
		}
		MAP_TECPART::iterator iter3;
		MAP_TECPART &refMap3 = DataSet::getInstance().getTecPartMap();
		iter3 = refMap3.begin();
		for(;iter3 != refMap3.end();iter3++)
		{
			iter3->second->TecPartTime::info();
		}
		MAP_SALEPART::iterator iter4;
		MAP_SALEPART &refMap4 = DataSet::getInstance().getSalePartMap();
		iter4 = refMap4.begin();
		for(;iter4 != refMap4.end();iter4++)
		{
			iter4->second->SalePartTime::info();
		}
		/*MAP_BOSSMA::iterator iter5;
		MAP_BOSSMA &refMap5 = DataSet::getInstance().getBossMap();
		iter5 = refMap5.begin();
		for(;iter5 != refMap5.end();iter5++)
		{
			iter2->second->info();
		}*/
}
void Boss::work(){
	system("clear");
	cout << "正在为您跳转界面...\n";
	sleep(3);
	system("clear");
	cout << "\t\t        欢迎" << Employee::getName() << "登入" << endl;
	short ch = 0;
	while(1)
	{
		ch = BossFace();
		switch(ch)
		{
		case 1:
			operatorToTecManager();
			break;
		case 2:
			operatorToSaleManager();
			break;
		case 3:
			operatorToTecPartTime();
			break;
		case 4:
			operatorToSalePartTime();
			break;
		case 5:
			TotalInfo();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}
