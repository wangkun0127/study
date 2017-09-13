/*
 * SalePartTime.cpp
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#include "SalePartTime.h"
#include "DataSet.h"
#include <string.h>

SalePartTime::SalePartTime(string strName,uint uiLevel,
		float fPerSalePay):Employee(strName,uiLevel){
	// TODO Auto-generated constructor stub
	m_fPerSalePay = fPerSalePay;
	m_uiSaleMoney = 0;
	//m_uiSaleLeaderId = 0;
}

SalePartTime::~SalePartTime() {
	// TODO Auto-generated destructor stub
}
//设置工作时间
void SalePartTime::setSaleWorkHour(){

}
//显示信息
void SalePartTime::info(){
	Employee::info();
	cout << "销售额:" << m_uiSaleMoney << " 工资占比:"
				<< m_fPerSalePay << " 总工资:" << m_uiSaleMoney * m_fPerSalePay
				<< " 上级:" << m_uiSaleLeaderId << ' ';
	cout << DataSet::getInstance().getSaleManagerMap().find(m_uiSaleLeaderId)->second->getName()
				<< endl;
}
//设置所属上级
void SalePartTime::setSaleLeaderId(uint uiSaleLeaderId){
	m_uiSaleLeaderId = uiSaleLeaderId;
}

uint SalePartTime::getSaleLeader() const{
	return m_uiSaleLeaderId;
}
uint &SalePartTime::getSaleLeader(){
	return m_uiSaleLeaderId;
}

float SalePartTime::getSaleMoney() const{
	return m_uiSaleMoney;
}
float &SalePartTime::getSaleMoney(){
	return m_uiSaleMoney;
}

float SalePartTime::getPerSalePay() const{
	return m_fPerSalePay;
}
float &SalePartTime::getPerSalePay(){
	return m_fPerSalePay;
}

short SalePartTime::workFace(){
	cout << "\t\t***********SALEPT**********\n";
	cout << "\t\t*   1、显示个人基本信息   *\n";
	cout << "\t\t*   2、修改登录密码       *\n";
	cout << "\t\t*   0、返回               *\n";
	cout << "\t\t***************************\n";
	cout << "请输入选项:";
	short num = 0;
	cin >> num;
	return num;
}
short SalePartTime::modifyById(){

	uint uiId;
	uiId = getId();
	SalePartTime *pSalePT = NULL;
	MAP_SALEPART::iterator iter;
	MAP_SALEPART &refMap = DataSet::getInstance().getSalePartMap();
	iter = refMap.find(uiId);
	if(iter != refMap.end())
	{
		pSalePT = iter->second;
	}
	string passwd;
	string passwd1;
	char ch;
	cout << "请输入原密码:";
	cin >> passwd;
	if(pSalePT->getPWd() == passwd){
		cout << "请输入新密码:";
		cin >> passwd1;
		cout << "确认修改(Y/N):";
		cin >> ch;
		if('Y' == ch||'y' == ch)
		{
			pSalePT->getPWd()=passwd1;
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
	DataSet::getInstance().getSalePartMap().insert(
								PAIR_SALEPART(uiId,pSalePT));
	return 1;
}
void SalePartTime::work(){
	system("clear");
	cout << "正在为您跳转界面...\n";
	sleep(3);
	system("clear");
	cout << "\t\t       欢迎" << getName() << "登入" << endl;
	short num  = 0;
	while(1)
	{
		num = workFace();
		switch(num)
		{
		case 1:
			info();
			break;
		case 2:
			if(1 == modifyById())
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
