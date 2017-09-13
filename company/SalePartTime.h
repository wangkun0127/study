/*
 * SalePartTime.h
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#ifndef SALEPARTTIME_H_
#define SALEPARTTIME_H_

#include "Employee.h"

class SalePartTime: virtual public Employee {
public:
	SalePartTime(string strName = "NewSalePT",
			uint uiLevel =
					ENUM_EMPLOYEE_LEVEL_PARTTIME_SALE,
					float fPerSalePay = 0.3);
	virtual ~SalePartTime();
	//设置工作时间
	void setSaleWorkHour();
	//显示信息
	void info();
	//设置所属上级
	void setSaleLeaderId(uint uiSaleLeaderId);

	uint getSaleLeader() const;
	uint &getSaleLeader();

	float getSaleMoney() const;
	float &getSaleMoney();

	float getPerSalePay() const;
	float &getPerSalePay();

	short workFace();
	short modifyById();
	void work();

private:
	float m_uiSaleMoney;
	float m_fPerSalePay;
	uint m_uiSaleLeaderId;
};

#endif /* SALEPARTTIME_H_ */
