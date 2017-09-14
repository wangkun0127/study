/*
 * Employee.cpp
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#include "Employee.h"
#include "DataSet.h"
uint Employee::m_suiId = 10000;
Employee::Employee(string strName,uint uiLevel) {
	// TODO Auto-generated constructor stub
	m_strName = strName;
	m_uiLevel = uiLevel;
	m_strPwd = "123456";
	m_strNote = "表现良好";
	m_uiId = m_suiId++;
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}
void Employee::info(){
	cout << "编号:" << m_uiId << " 名字:" << m_strName << ' ';
	switch(m_uiLevel)
	{
	case ENUM_EMPLOYEE_LEVEL_PARTTIME_TEC:
		cout << "--级别:兼职技术人员" << ' ';
		break;
	case ENUM_EMPLOYEE_LEVEL_MANAGER_TEC:
		cout << "--级别:技术经理" << ' ';
		break;
	case ENUM_EMPLOYEE_LEVEL_PARTTIME_SALE:
		cout << "--级别:兼职销售人员" << ' ';
		break;
	case ENUM_EMPLOYEE_LEVEL_MANAGET_SALE:
		cout << "--级别:销售经理" << ' ';
		break;
	case ENUM_EMPLOYEE_LEVEL_BOSS:
		cout << "--级别:老板" << ' ';
		break;
	}
	cout << "密码:" << m_strPwd << " 说明:" << m_strNote << ' ';
}

void Employee::modifyPwd(){

}

void Employee::setBaseId(){
	/*MAP_TECMA::iterator iter1;
		MAP_TECMA &refMap1 = DataSet::getInstance().getTecManagerMap();
		iter1 = refMap1.begin();
		for(;iter1 != refMap1.end();iter1++)
		{
			if(iter1->second>Employee::m_suiId){
				Employee::m_suiId = iter1->second->getId();
			}
		}
		MAP_SALEMA::iterator iter2;
		MAP_SALEMA &refMap2 = DataSet::getInstance().getSaleManagerMap();
		iter2 = refMap2.begin();
		for(;iter2 != refMap2.end();iter2++)
		{
			if(iter2->second>Employee::m_suiId){
				Employee::m_suiId = iter2->second->getId();
			}
		}
		MAP_TECPART::iterator iter3;
		MAP_TECPART &refMap3 = DataSet::getInstance().getTecPartMap();
		iter3 = refMap3.begin();
		for(;iter3 != refMap3.end();iter3++)
		{
			if(iter3->second>Employee::m_suiId){
				Employee::m_suiId = iter3->second->getId();
			}
		}
		MAP_SALEPART::iterator iter4;
		MAP_SALEPART &refMap4 = DataSet::getInstance().getSalePartMap();
		iter4 = refMap4.begin();
		for(;iter4 != refMap4.end();iter4++)
		{
			if(iter4->second>Employee::m_suiId){
				Employee::m_suiId = iter4->second->getId();
			}
		}
		MAP_BOSSMA::iterator iter5;
		MAP_BOSSMA &refMap5 = DataSet::getInstance().getBossMap();
		iter5 = refMap5.begin();
		for(;iter5 != refMap5.end();iter5++)
		{
			if(iter5->second>Employee::m_suiId){
				Employee::m_suiId = iter5->second->getId();
			}
		}*/
}

uint Employee::getId() const
{
	return m_uiId;
}
uint &Employee::getId()
{
	return m_uiId;
}
const string &Employee::getName() const
{
	return m_strName;
}
string &Employee::getName()
{
	return m_strName;
}

const string &Employee::getPWd() const
{
	return m_strPwd;
}
string &Employee::getPWd()
{
	return m_strPwd;
}

const string &Employee::getNote() const
{
	return m_strNote;
}
string &Employee::getNote()
{
	return m_strNote;
}

uint Employee::getLevel() const
{
	return m_uiLevel;
}
uint &Employee::getLevel()
{
	return m_uiLevel;
}
ostream &operator<<(ostream &out,const Employee &employee)
{
	out << "编号:" << employee.m_uiId << " 名字:" << employee.m_strName
			<< " 级别:兼职技术人员" << " 密码:" << employee.m_strPwd
			<< " 说明:" << employee.m_strNote;
	return out;
}
void work()
{}
