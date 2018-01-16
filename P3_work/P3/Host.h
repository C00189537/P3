// Host Class
// Used by finite state machine
// Values will be transfered to an external object

#pragma once
#include "SDL.h"
class Host
{
public:
	Host();
	~Host();

	SDL_Point getPos();
	SDL_Point getVelocity();

	void setPos(SDL_Point p);
	void setVelocity(SDL_Point v);


private:

	SDL_Point m_pos;
	SDL_Point m_vel;
};

