/*
 * TecPartTime.h
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#ifndef TECPARTTIME_H_
#define TECPARTTIME_H_

#include "Employee.h"

class TecPartTime: virtual public Employee {
public:
	TecPartTime(string strName = "NewTecPP"
				,uint uiLevel =
				ENUM_EMPLOYEE_LEVEL_PARTTIME_TEC
				,uint fPerHourPay = 50);
	virtual ~TecPartTime();

	//设置工作时间
	void setWorkHour(uint workHour);
	//显示信息
	void info();
	//设置所属上级
	void setLearder(uint uiLearderId);
	//获得其领导
	uint getLeader() const;
	uint &getLearder();

	uint getWorkHour() const;
	uint &getWorkHour();

	 uint getPerHourPay() const;
	 uint &getPerHourPay();

	 short TecworkFace();
	 short modifyTecById();
	 void work();
private:
	uint m_uiWorkHour;		//工作时间
	uint m_fPerHourPay;		//单位时间工资
	uint m_uiLeaderId;		//所属上级Id
};

#endif /* TECPARTTIME_H_ */
