#pragma once
#include "GameData.h"
#include "Host.h"
#include "stdafx.h"

namespace FSMLIB
{

	class FSM
	{
		class State* current;
	public:
		FSM();
		~FSM();

		void initialise(std::shared_ptr<GameData> &data);
		void setCurrent(State* s);
		void idle();
		void walking();
		void driving();
		void flying();
		void swimming();

		SDL_Point getHostPos();
		SDL_Point getHostVel();
		void setHostPos(SDL_Point p);
		void boundaries(int screenX);
		std::shared_ptr<GameData> m_data;

	private:

		Host m_host;
	};
}
