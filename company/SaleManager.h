/*
 * SaleManager.h
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#ifndef SALEMANAGER_H_
#define SALEMANAGER_H_

#include "SalePartTime.h"

class SaleManager: public SalePartTime {
public:
	SaleManager(string strName = "NewMa",float SaleSalary = 10000,float fPerSale = 0.13);
	virtual ~SaleManager();

	void info();

	void setSaleSalary(float Salary);
	void setSaleMoney(uint uiId,float saleMoney);

	float  getSaleSalary() const;
	float &getSaleSalary();

	float getPerSale() const;
	float &getPerSale();

	float getuiSaleMoney() const;
	float &getuiSaleMoney();

	//对员工的增删改查
	static short SalePartTimeFace();
	static short SalePartTimeFaceByBoss();
	void addSalePartTime(uint uiId = 0);
	void delSalePartTimeById(uint uiId = 0);
	void modifySalePartTime(uint uiId = 0);
	SalePartTime *findSalePartTime(uint uiId = 0);
	void displaySalePartTimeinfo();

	short modifySaleManagerById();
	void work();
private:
	float m_uiSaleMoney;
	float m_fPerSale;
	float m_fSaleSalary;
};

#endif /* SALEMANAGER_H_ */
