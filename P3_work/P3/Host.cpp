#include "Host.h"



Host::Host()
{
}


Host::~Host()
{
}
SDL_Point Host::getPos()
{
	return m_pos;
}
SDL_Point Host::getVelocity()
{
	return m_vel;
}
void Host::setPos(SDL_Point p)
{
	m_pos = p;
}
void Host::setVelocity(SDL_Point v)
{
	m_vel = v;
}