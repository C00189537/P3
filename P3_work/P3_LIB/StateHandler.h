#pragma once

#include "FSM.h"

namespace FSMLIB
{

	class StateHandler
	{
	public:
		StateHandler();
		StateHandler(std::shared_ptr<GameData> &data);
		~StateHandler();

		void handleState(SDL_Event &e);
		SDL_Point getPos(int screenX);

	private:
		FSM fsm;



	};
}

