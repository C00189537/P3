#pragma once
#include "GameData.h"
#include "Host.h"
class FSM
{
	class State* current;
public:
		FSM();
		~FSM();

		FSM(GameData data);
		void setCurrent(State* s);
		void idle();
		void walking();
		void driving();
		void flying();
		void swimming();

		SDL_Point getHostPos();
		SDL_Point getHostVel();

private:
		GameData m_data;
		Host m_host;
};
