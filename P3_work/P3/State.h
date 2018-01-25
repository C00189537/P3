#ifndef STATE_H_
#define STATE_H_
#include "FSM.h"
class State
{
public:

	virtual void idle(FSM* a)
	{
		//std::cout << "State::Idling" << std::endl;
	}

	virtual void walking(FSM* a)
	{
		//std::cout << "State::Walk" << std::endl;
	}

	virtual void driving(FSM* a)
	{
		//std::cout << "State::Drive" << std::endl;

	}
	virtual void flying(FSM* a)
	{
		//std::cout << "State::Fly" << std::endl;
	}
	virtual void swimming(FSM* a)
	{
		//std::cout << "State::Swim" << std::endl;
	}
};
#endif // !STATE_H_