#pragma once
#include "Idle.h"

namespace FSMLIB
{

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
		void swimming(FSM* a)
		{
			SDL_Point vel = { a->getHostPos().x + a->m_data->swimSpeed,  a->getHostPos().y + a->m_data->swimSpeed };
			if (a->getHostPos().y >= a->m_data->seaLevel)
			{
				SDL_Point temp = { a->getHostPos().x + a->m_data->swimSpeed, a->m_data->seaLevel };
				a->setHostPos(temp);
			}
			else
			{
				a->setHostPos(vel);
			}
		}
	};
}