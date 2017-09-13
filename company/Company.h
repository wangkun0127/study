/*
 * Company.h
 *
 *  Created on: 2017年9月11日
 *      Author: wk
 */

#ifndef COMPANY_H_
#define COMPANY_H_

#include "DataSet.h"
//#include "Mysql.h"

class Company {
public:
	Company();
	virtual ~Company();

	void init();
	void setBaseId();

	static short loginFace();
	void work();

	template<typename T>
	T loginCompare(uint uiId, const string &strPwd, map<uint, T>&container);
};
template<typename T>
T Company::loginCompare(uint uiId, const string &strPwd, map<uint, T>&container){
	T reval = NULL;
	typename map<uint, T>::iterator iter = container.find(uiId);
	if(iter != container.end())
	{
		if (iter->second->getPWd() == strPwd)
		{
			reval = iter->second;
		}
	}
	return reval;
}


#endif /* COMPANY_H_ */
