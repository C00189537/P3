#pragma once
#include "Idle.h"

class Swimming : public State
{

public:
	Swimming() {};
	~Swimming() {};

	void idle(FSM* a)
	{
		std::cout << "Going from Swimming to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};