#pragma once
#include "Idle.h"

class Driving : public State
{

public:
	Driving() {};
	~Driving() {};

	void idle(FSM* a)
	{
		std::cout << "Going from Driving to Idling" << std::endl;
		a->setCurrent(new Idle());
		delete this;
	}
};