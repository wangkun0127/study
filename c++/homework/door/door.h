#ifndef _DOOR_H_
#define _DOOR_H_

#include <iostream>

#include <unistd.h>
using namespace std;

class Door
{
	public:
		void open()
		{
			cout << "door is openning" << endl;
			sleep(3);
			cout << "door is closing" << endl;
		}
	private:
};


#endif
