#pragma once
#include "Idle.h"

class Flying : public State
{

public:
	Flying() {};
	~Flying() {};

	void idle(FSM* a)
	{
		std::cout << "Going from Flying to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};