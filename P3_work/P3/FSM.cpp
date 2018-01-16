#include "FSM.h"
#include "Idle.h"


FSM::FSM()
{
	current = new Idle();
}
FSM::~FSM()
{
}
FSM::FSM(GameData data) : m_data(data)
{
	current = new Idle();
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
	current->walk(this);
}

void FSM::driving()
{
	current->drive(this);

}
void FSM::flying()
{
	current->fly(this);
}
void FSM::swimming()
{
	current->swim(this);
}
SDL_Point FSM::getHostPos()
{
	return m_host.getPos();
}
SDL_Point FSM::getHostVel()
{
	return m_host.getVelocity();
}