/*
 * Company.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: wk
 */

#include "Company.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

Company::Company() {
	// TODO Auto-generated constructor stub
	init();
	setBaseId();
}

Company::~Company() {
	// TODO Auto-generated destructor stub
}

void Company::init(){
	cout << DataSet::getInstance().getBossMap().size() << endl;
	if(DataSet::getInstance().getBossMap().empty())
	{
		Boss *pBoss = new Boss;
		DataSet::getInstance().getBossMap().insert(
				PAIR_BOSSMA(pBoss->Employee::getId(),pBoss));
		cout << pBoss->Employee::getId() << ' ' << pBoss->Employee::getPWd() << endl;
	}
}
void Company::setBaseId(){
	MAP_TECMA::iterator iter1;
	MAP_TECMA &refMap1 = DataSet::getInstance().getTecManagerMap();
	iter1 = refMap1.begin();
	for(;iter1 != refMap1.end();iter1++)
	{
		if(iter1->second->getId()>Employee::m_suiId){
			Employee::m_suiId = iter1->second->getId();
		}
	}
	MAP_SALEMA::iterator iter2;
	MAP_SALEMA &refMap2 = DataSet::getInstance().getSaleManagerMap();
	iter2 = refMap2.begin();
	for(;iter2 != refMap2.end();iter2++)
	{
		if(iter2->second->getId()>Employee::m_suiId){
			Employee::m_suiId = iter2->second->getId();
		}
	}
	MAP_TECPART::iterator iter3;
	MAP_TECPART &refMap3 = DataSet::getInstance().getTecPartMap();
	iter3 = refMap3.begin();
	for(;iter3 != refMap3.end();iter3++)
	{
		if(iter3->second->getId()>Employee::m_suiId){
			Employee::m_suiId = iter3->second->getId();
		}
	}
	MAP_SALEPART::iterator iter4;
	MAP_SALEPART &refMap4 = DataSet::getInstance().getSalePartMap();
	iter4 = refMap4.begin();
	for(;iter4 != refMap4.end();iter4++)
	{
		if(iter4->second->getId()>Employee::m_suiId){
			Employee::m_suiId = iter4->second->getId();
		}
	}
	MAP_BOSSMA::iterator iter5;
	MAP_BOSSMA &refMap5 = DataSet::getInstance().getBossMap();
	iter5 = refMap5.begin();
	for(;iter5 != refMap5.end();iter5++)
	{
		if(iter5->second->getId()>Employee::m_suiId){
			Employee::m_suiId = iter5->second->getId();
		}
	}
	//Employee::m_suiId++;
}
short Company::loginFace(){
	system("clear");
	cout << "\t     欢迎使用公司管理系统测试版" << endl;
	cout << "\t\t********************\n";
	cout << "\t\t*1,技术经理登录    *\n";
	cout << "\t\t*2,兼职技术人员登录*\n";
	cout << "\t\t*3,销售经理登录    *\n";
	cout << "\t\t*4,兼职销售人员登录*\n";
	cout << "\t\t*5,老板登录        *\n";
	cout << "\t\t*0,退出系统        *\n";
	cout << "\t\t********************\n";
	cout << "请输入选项：";
	short ch = -1;
	cin >> ch;
	while(getchar()!='\n');
	return ch;
}
void Company::work(){
	short ch = -1;
	uint uiId = 0;
	string strPwd = "";
	//Employee::setBaseId();
	short count = 0;
	while (1)
	{
		count++;
		if(4 == count)
		{
			system("clear");
			cout << "您的用户名或密码或验证码输错三次，系统将自动退出！\n";
			sleep(3);
			break;
		}
		ch = loginFace();
		if (0 != ch)
		{
			char a[37]="0123456789qwertyuioplkjhgfdsazxcvbnm";
			int i,j;char output[5];
			srand((int)time(0));
			for(i=0;i<4;i++)
			{
				j=rand()%36;
				output[i]=a[j];
			}
			char num1[20];
			char *p=num1;
			cout << "请输入员工编号:";
			cin >> uiId;
			p=getpass("请输入密码：");
			strPwd=p;
			char out[5];
			cout << "------\n";
			cout <<"|"<<output<<"|\n";
			cout <<"------\n";

			cout << "请输入验证码：";
			cin >> out;
			while(getchar()!='\n');
			if(0!=strcmp(out,output))
			{
				cout << "验证码输入错误，请重新输入！\n";
				while(getchar()!='\n');
				continue;
			}
		}

		switch (ch)
		{
		case 1: //技术经理登录
		{
			TecManager *pTecMa = loginCompare<TecManager *>(uiId, strPwd, DataSet::getInstance().getTecManagerMap());
			if (NULL != pTecMa)
			{
				pTecMa->work();
				count = 0;
			}
			else
			{
				cout << "密码或用户名错误，请重新输入！\n";
			}
			break;
		}
		case 2: //兼职技术人员登录
		{
			TecPartTime *pTecPT = loginCompare<TecPartTime *>(uiId, strPwd, DataSet::getInstance().getTecPartMap());
			if (NULL != pTecPT)
			{
				pTecPT->TecPartTime::work();
			}
			else
			{
				cout << "密码或用户名错误，请重新输入！\n";
			}
			break;
		}

		case 3: //销售经理登录
		{
			SaleManager *pSaleMa = loginCompare<SaleManager *>(uiId, strPwd, DataSet::getInstance().getSaleManagerMap());
			if (NULL != pSaleMa)
			{
				pSaleMa->work();
			}
			else
			{
				cout << "密码或用户名错误，请重新输入！\n";
			}
			break;
		}
		case 4: //兼职销售人员登录
		{
			SalePartTime *pSalePT = loginCompare<SalePartTime *>(uiId, strPwd, DataSet::getInstance().getSalePartMap());
			if (NULL != pSalePT)
			{
				pSalePT->work();
			}
			else
			{
				cout << "密码或用户名错误，请重新输入！\n";
			}
			break;
		}
		case 5: //老板登录
		{
			Boss *pBoss = loginCompare<Boss *>(uiId, strPwd, DataSet::getInstance().getBossMap());
			if (NULL != pBoss)
			{
				pBoss->work();
				count = 0;
			}
			else
			{
				cout << "密码或用户名错误，请重新输入！\n";
			}
			break;
		}
		case 0: //退出系统
			//saveTecMangerToMysql();
			cout << "谢谢您的使用，再见！\n";
			sleep(3);
			system("clear");
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
		while(getchar()!='\n');
	}
}

