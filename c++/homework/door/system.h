#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "computer.h"
#include "door.h"
#include "input.h"

class DoorSystem
{
	public:
		DoorSystem()
		{
			m_ring = false;
			m_open = false;
		}
		void work();
		void setRing(bool ring = true)
		{
			m_ring = ring;
		}
		void setOpen(bool open = true)
		{
			m_open = open;
		}
	private:
		Door m_door;
		bool m_ring;
		bool m_open;//是否有开门信号
	public:
		Input m_input;
		CComputer m_computer;
};

#endif
