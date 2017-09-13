/*
 * main.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: wk
 */
#include "Company.h"
#include "Mysql.h"


int main(void) {

	Mysql sql;
	sql.readMysqlToMap();
	/*Boss boss;
	boss.info();*/
	Company com;
	com.work();

	sql.saveDataToMysql();

	return 0;
}




