#pragma once
#include "Idle.h"

namespace FSMLIB
{

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
		void flying(FSM* a)
		{
			SDL_Point vel = { a->getHostPos().x + a->m_data->airSpeedX,  a->getHostPos().y - a->m_data->airSpeedY };
			if (a->getHostPos().y <= a->m_data->skyLevel)
			{
				SDL_Point temp = { a->getHostPos().x + a->m_data->airSpeedX, a->m_data->skyLevel };
				a->setHostPos(temp);
			}
			else
			{
				a->setHostPos(vel);
			}
		}
	};
}