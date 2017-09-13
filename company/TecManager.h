/*
 * TecManager.h
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#ifndef TECMANAGER_H_
#define TECMANAGER_H_

#include "TecPartTime.h"

class TecManager: public TecPartTime {
public:
	TecManager(string strName = "NewTecMa", uint fSalary = 10000);
	virtual ~TecManager();

	//显示信息
	void info();

	void setSalary(uint Salary);

	uint getSalary() const;
	uint &getSalary();
	//对员工的增删改查
	static short TecPartTimeFace();
	static short TecPartTimeFaceByBoss();
	void addTecPartTime(uint uiId = 0);
	void delTecPartTimeById(uint uiId = 0);
	void modifyTecPartTime(uint uiId = 0);
	TecPartTime *findTecPartTime(uint uiId = 0);
	//void findTecPartTime(uint uiId = 0);
	void displayTecPartTimeinfo();

	short modifyTecManagerById();
	void work();
private:
	uint m_fSalary;
};

#endif /* TECMANAGER_H_ */
