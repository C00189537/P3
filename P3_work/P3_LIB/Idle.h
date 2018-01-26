
#ifndef IDLE_H_
#define IDLE_H_

#include "State.h"
//States

#include <thread>
#include <chrono>

namespace FSMLIB
{

	class Idle : public State
	{
	public:
		Idle() { std::cout << "Idle" << std::endl; };
		~Idle() {  };

		void idle(FSM* a);
		void walking(FSM* a);
		void driving(FSM* a);
		void flying(FSM* a);
		void swimming(FSM* a);
	};

}
#endif // !
