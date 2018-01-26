#pragma once
#include "Idle.h"

namespace FSMLIB
{

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
		void driving(FSM* a)
		{
			SDL_Point vel = { a->getHostPos().x + a->m_data->driveSpeed,  a->getHostPos().y };
			a->setHostPos(vel);
		}
	};
}