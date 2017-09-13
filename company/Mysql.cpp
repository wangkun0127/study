/*
 * Mysql.cpp
 *
 *  Created on: 2017年9月11日
 *      Author: wk
 */
#include "Employee.h"
#include "Mysql.h"

Mysql::Mysql() {
	// TODO Auto-generated constructor stub

}

Mysql::~Mysql() {
	// TODO Auto-generated destructor stub
}

int Mysql::saveTecMangerToMysql(){
	MYSQL *conn = NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "delete from TecManger";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024] = {'\0'};
	char buf[100] = "insert into TecManger values(";

	MAP_TECMA &refMap = DataSet::getInstance().getTecManagerMap();
	MAP_TECMA::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s',%d,%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPWd().data(),
				iter->second->getLevel(),
				iter->second->getSalary(),
				iter->second->getNote().data());
				mysql_query(conn,buff);
	}
	mysql_close(conn);

}
int Mysql::saveTecPartTimeToMysql(){
	MYSQL *conn = NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "delete from TecPartTime";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024] = {'\0'};
	char buf[100] = "insert into TecPartTime values(";

	MAP_TECPART &refMap = DataSet::getInstance().getTecPartMap();
	MAP_TECPART::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s',%d,%d,%d,%d,%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPWd().data(),
				iter->second->getLevel(),
				iter->second->getWorkHour(),
				iter->second->getPerHourPay(),
				iter->second->getWorkHour()*iter->second->getPerHourPay(),
				iter->second->getLearder(),
				iter->second->getNote().data());
				mysql_query(conn,buff);
	}
	mysql_close(conn);

}
int Mysql::saveSaleMangerToMysql(){
	MYSQL *conn = NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "delete from SaleManger";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024] = {'\0'};
	char buf[100] = "insert into SaleManger values(";

	MAP_SALEMA &refMap = DataSet::getInstance().getSaleManagerMap();
	MAP_SALEMA::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s',%d,%f,%f,%f,%f,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPWd().data(),
				iter->second->getLevel(),
				iter->second->getuiSaleMoney(),
				iter->second->getPerSale(),
				iter->second->getSaleSalary(),
				iter->second->getuiSaleMoney()*iter->second->getPerSale()+iter->second->getSaleSalary(),
				iter->second->getNote().data());
				mysql_query(conn,buff);
	}
	mysql_close(conn);
}
int Mysql::saveSalePartTimeToMysql(){
	MYSQL *conn = NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "delete from SalePartTime";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024] = {'\0'};
	char buf[100] = "insert into SalePartTime values(";

	MAP_SALEPART &refMap = DataSet::getInstance().getSalePartMap();
	MAP_SALEPART::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s',%d,%f,%f,%f,%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPWd().data(),
				iter->second->getLevel(),
				iter->second->getSaleMoney(),
				iter->second->getPerSalePay(),
				iter->second->getSaleMoney()*iter->second->getPerSalePay(),
				iter->second->getSaleLeader(),
				iter->second->getNote().data());
				mysql_query(conn,buff);
	}
	mysql_close(conn);
}
int Mysql::saveBossToMysql(){
	MYSQL *conn = NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "delete from Boss";
	mysql_real_query(conn,q,strlen(q));
	char buff[1024] = {'\0'};
	char buf[100] = "insert into Boss values(";

	MAP_BOSSMA &refMap = DataSet::getInstance().getBossMap();
	MAP_BOSSMA::iterator iter;
	iter = refMap.begin();
	for(;iter != refMap.end();iter++)
	{
		sprintf(buff,"%s%d,'%s','%s',%d,'%s')",buf,
				iter->second->getId(),
				iter->second->getName().data(),
				iter->second->getPWd().data(),
				iter->second->getLevel(),
				iter->second->getNote().data());
				mysql_query(conn,buff);
	}
	mysql_close(conn);
}

//从mysql读数据到map
int Mysql::readMysqlToTecManger(){
	MYSQL *conn = NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "select * from TecManger";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(res == NULL)
	{
		cout << "mysql_use_result error" << endl;
		return -1;
	}
	while((row=mysql_fetch_row(res))!=NULL)
	{
		TecManager *pTecMA = new TecManager(row[1]);
		pTecMA->getId()=atoi(row[0]);
		pTecMA->getPWd()=row[2];
		pTecMA->getLevel()=atoi(row[3]);
		pTecMA->getSalary()=atoi(row[4]);
		pTecMA->getNote()=row[5];
		DataSet::getInstance().getTecManagerMap().insert(
				PAIR_TECMA(atoi(row[0]),pTecMA));
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
int Mysql::readMysqlToTecPartTime(){
	MYSQL *conn = NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "select * from TecPartTime";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(res == NULL)
	{
		cout << "mysql_use_result error" << endl;
		return -1;
	}
	while((row=mysql_fetch_row(res))!=NULL)
	{
		TecPartTime *pTecPT = new TecPartTime(row[1]);
		pTecPT->getId()=atoi(row[0]);
		pTecPT->getPWd()=row[2];
		pTecPT->getLevel()=atoi(row[3]);
		pTecPT->getWorkHour()=atoi(row[4]);
		pTecPT->getPerHourPay()=atoi(row[5]);
		pTecPT->getLearder()=atoi(row[7]);
		pTecPT->getNote()=row[8];
		DataSet::getInstance().getTecPartMap().insert(
					PAIR_TECPART(atoi(row[0]),pTecPT));
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
int Mysql::readMysqlToSaleManger(){
	MYSQL *conn = NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "select * from SaleManger";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(res == NULL)
	{
		cout << "mysql_use_result error" << endl;
		return -1;
	}
	while((row=mysql_fetch_row(res))!=NULL)
	{
		SaleManager *pSaleMA = new SaleManager(row[1]);
		pSaleMA->getId()=atoi(row[0]);
		pSaleMA->getPWd()=row[2];
		pSaleMA->getLevel()=atoi(row[3]);
		pSaleMA->getuiSaleMoney()=atof(row[4]);
		pSaleMA->getPerSale()=atof(row[5]);
		pSaleMA->getSaleSalary()=atof(row[6]);
		pSaleMA->getNote()=row[8];
		DataSet::getInstance().getSaleManagerMap().insert(
					PAIR_SALEMA(atoi(row[0]),pSaleMA));
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
int Mysql::readMysqlToSalePartTime(){
	MYSQL *conn = NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "select * from SalePartTime";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(res == NULL)
	{
		cout << "mysql_use_result error" << endl;
		return -1;
	}
	while((row=mysql_fetch_row(res))!=NULL)
	{
		SalePartTime *pSalePT = new SalePartTime(row[1]);
		pSalePT->getId()=atoi(row[0]);
		pSalePT->getPWd()=row[2];
		pSalePT->getLevel()=atoi(row[3]);
		pSalePT->getSaleMoney()=atof(row[4]);
		pSalePT->getPerSalePay()=atof(row[5]);
		pSalePT->getSaleLeader()=atoi(row[7]);
		pSalePT->getNote()=row[8];
		DataSet::getInstance().getSalePartMap().insert(
						PAIR_SALEPART(atoi(row[0]),pSalePT));
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
int Mysql::readMysqlBossMap(){
	MYSQL *conn = NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		cout << "数据库初始化失败" << endl;
		return -1;
	}
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "127";
	const char *db = "projects";
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);
	if(NULL == conn)
	{
		cout << mysql_errno(conn) << endl;
		return -1;
	}
	mysql_set_character_set(conn,"utf8");
	const char *q = "use projects";
	mysql_real_query(conn,q,strlen(q));
	q = "select * from Boss";
	mysql_real_query(conn,q,strlen(q));
	res=mysql_use_result(conn);
	if(res == NULL)
	{
		cout << "mysql_use_result error" << endl;
		return -1;
	}
	while((row=mysql_fetch_row(res))!=NULL)
	{
		Boss *pBossMA = new Boss(row[1]);
		pBossMA->getId()=atoi(row[0]);
		pBossMA->getPWd()=row[2];
		pBossMA->getLevel()=atoi(row[3]);
		pBossMA->getNote()=row[4];
		DataSet::getInstance().getBossMap().insert(
					PAIR_BOSSMA(atoi(row[0]),pBossMA));
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
void Mysql::readMysqlToMap(){
	readMysqlToTecManger();
	readMysqlToTecPartTime();
	readMysqlToSaleManger();
	readMysqlToSalePartTime();
	readMysqlBossMap();
}
void Mysql::saveDataToMysql(){
	saveTecMangerToMysql();
	saveTecPartTimeToMysql();
	saveSaleMangerToMysql();
	saveSalePartTimeToMysql();
	saveBossToMysql();
}
