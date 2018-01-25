#include "FSM.h"
#include "Idle.h"

namespace FSMLIB
{

	FSM::FSM()
	{

	}
	FSM::~FSM()
	{
	}
	void FSM::initialise(std::shared_ptr<GameData> &data)
	{
		current = new Idle();
		m_data = data;
		SDL_Point pos = { m_data->playerX, m_data->playerY };
		m_host.setPos(pos);
	}
	//Sets the state of the 
	void FSM::setCurrent(State* s)
	{
		current = s;
	}

	void FSM::idle()
	{
		current->idle(this);
	}

	void FSM::walking()
	{
		current->walking(this);
	}

	void FSM::driving()
	{
		current->driving(this);
	}
	void FSM::flying()
	{
		current->flying(this);
	}
	void FSM::swimming()
	{
		current->swimming(this);
	}
	SDL_Point FSM::getHostPos()
	{
		return m_host.getPos();
	}
	SDL_Point FSM::getHostVel()
	{
		return m_host.getVelocity();
	}
	void FSM::setHostPos(SDL_Point p)
	{
		m_host.setPos(p);
	}
	void FSM::boundaries(int screenX)
	{
		if (m_host.getPos().x > screenX + m_data->width)
		{
			SDL_Point temp = { 0, m_host.getPos().y };
			m_host.setPos(temp);
		}
	}
}