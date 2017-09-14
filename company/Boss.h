/*
 * Boss.h
 *
 *  Created on: 2017年9月9日
 *      Author: wk
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "SaleManager.h"
#include "TecManager.h"

class Boss: public SaleManager, public TecManager {
public:
	Boss(string strName = "Boss");
	virtual ~Boss();

	static short BossFace();
	static short TecManagerFace();
	static short SaleManagerFace();
	static short TecPartTimeFace();
	static short SalePartTimeFace();

	void info();

	//对技术经理增删改查
	void operatorToTecManager();
	void addTecManager();
	void delTecManager(uint uiId = 0);
	void modifyTecManager(uint uiId = 0);
	TecManager* findTecManager(uint uiId = 0);
	void displayTecManager();

	//对技术经理增删改查
	void operatorToSaleManager();
	void addSaleManager();
	void delSaleManager(uint uiId = 0);
	void modifySaleManager(uint uiId = 0);
	SaleManager* findSaleManager(uint uiId = 0);
	void displaySaleManager();

	//对兼职技术人员的增删改查
	void operatorToTecPartTime();

	//对兼职销售人员的增删改查
	void operatorToSalePartTime();

	void TotalInfo();
	void work();
};

#endif /* BOSS_H_ */
