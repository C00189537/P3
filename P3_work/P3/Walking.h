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
	void walking(FSM* a)
	{
		SDL_Point vel = { a->getHostPos().x + a->m_data->walkSpeed,  a->getHostPos().y };
		a->setHostPos(vel);
	}
};