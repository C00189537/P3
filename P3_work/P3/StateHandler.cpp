#include "StateHandler.h"



StateHandler::StateHandler()
{
	fsm.idle();
}
StateHandler::StateHandler(std::shared_ptr<GameData> &data)
{
	fsm.initialise(data);
	fsm.idle();
}

StateHandler::~StateHandler()
{
}
void StateHandler::handleState(SDL_Event &e) {
	// switch case to find the event type
	switch (e.type) {
	case SDL_KEYDOWN: // key down event detected
		switch (e.key.keysym.sym) {
		case SDLK_a:
			if (fsm.m_data->fly)
			{
				fsm.flying();
			}
			break;
		case SDLK_w:
			if (fsm.m_data->walk)
			{
				fsm.walking();
			}
			break;
		case SDLK_s:
			if (fsm.m_data->swim)
			{
				fsm.swimming();
			}
			break;
		case SDLK_d:
			if (fsm.m_data->drive)
			{
				fsm.driving();
			}
			break;
		}

		break; // keydown
	case SDL_KEYUP:
		fsm.idle();
		break; // key up
	}
}

SDL_Point StateHandler::getPos()
{
	return fsm.getHostPos();
}