#pragma once
#include <thread>
#include <chrono>
#include <SDL.h>
#include "FSM.h"
#include "Walking.h"
#include "Idle.h"
#include "Driving.h"
#include "Flying.h"
#include "Swimming.h"

class StateHandler
{
public:
	StateHandler();
	StateHandler(std::shared_ptr<GameData> &data);
	~StateHandler();

	void handleState(SDL_Event &e);
	SDL_Point getPos();

private:
	FSM fsm;



};

