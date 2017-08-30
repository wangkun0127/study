#ifndef _USER_H_
#define _USER_H_

#include "system.h"

class Guest
{
	public:
		void pressRing(DoorSystem &ds)
		{
			cout << "以访客身份按门铃...\n";
			ds.setRing();
		}
};
class Employee: public Guest
{
	public:
		void input(DoorSystem &ds)
		{
			ds.m_input.InputData();
		}
};
class Admin: public Employee
{
	public:
		void pressOpenButton(DoorSystem &ds)
		{
			cout << "管理员正在开门..." << endl;
			ds.setOpen();
		}
		void addUsrInfo(DoorSystem &ds)
		{
			ds.m_input.InputData();
			string strType = ds.m_input.dataType();
			ds.m_computer.addData(ds.m_input.getData(),strType);
		}
};

#endif
