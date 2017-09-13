/*
 * Mysql.h
 *
 *  Created on: 2017年9月11日
 *      Author: wk
 */

#ifndef MYSQL_H_
#define MYSQL_H_

#include "DataSet.h"
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Mysql: public DataSet {
public:
	Mysql();
	virtual ~Mysql();

	//map存入mysql
	int saveTecMangerToMysql();
	int saveTecPartTimeToMysql();
	int saveSaleMangerToMysql();
	int saveSalePartTimeToMysql();
	int saveBossToMysql();
	void saveDataToMysql();

	//从mysql到map
	int readMysqlToTecManger();
	int readMysqlToTecPartTime();
	int readMysqlToSaleManger();
	int readMysqlToSalePartTime();
	int readMysqlBossMap();

	void readMysqlToMap();
};

#endif /* MYSQL_H_ */
