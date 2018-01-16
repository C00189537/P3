#pragma once
#include "Idle.h"

class Walking : public State
{

public:
	Walking() {};
	~Walking() {};

	void idle(FSM* a)
	{
		std::cout << "Going from Walking to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};