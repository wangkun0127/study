/*
 * DataSet.cpp
 *
 *  Created on: 2017年8月31日
 *      Author: wk
 */

#include "DataSet.h"

DataSet::DataSet() {
	// TODO Auto-generated constructor stub

}

DataSet::~DataSet() {
	// TODO Auto-generated destructor stub
}

DataSet &DataSet::getInstance(){
	static DataSet data;
	return data;
}

MAP_TECPART &DataSet::getTecPartMap(){
	return m_tecPartTimeMap;
}
MAP_TECMA &DataSet::getTecManagerMap(){
	return m_tecManagerMap;
}

MAP_SALEPART &DataSet::getSalePartMap(){
	return m_salePartTimeMap;
}
MAP_SALEMA &DataSet::getSaleManagerMap(){
	return m_saleManagerMap;
}
MAP_BOSSMA &DataSet::getBossMap(){
	return m_BossMap;
}



