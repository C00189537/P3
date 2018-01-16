#ifndef STATE_H_
#define STATE_H_
#include "stdafx.h"
#include "FSM.h"
class State
{
public:
	virtual void idle(FSM* a)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void walk(FSM* a)
	{
		std::cout << "State::Walk" << std::endl;
	}

	virtual void drive(FSM* a)
	{
		std::cout << "State::Drive" << std::endl;

	}
	virtual void fly(FSM* a)
	{
		std::cout << "State::Fly" << std::endl;
	}
	virtual void swim(FSM* a)
	{
		std::cout << "State::Swim" << std::endl;
	}
};
#endif // !STATE_H_