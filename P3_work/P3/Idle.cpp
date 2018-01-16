#include "Idle.h"
#include "Walking.h"
#include "Driving.h"
#include "Flying.h"
#include "Swimming.h"


void Idle::walking(FSM* a)
{
	std::cout << "walking" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Walking());
	delete this;
}

void Idle::driving(FSM* a)
{
	std::cout << "driving" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Driving());
	delete this;
}
void Idle::flying(FSM* a)
{
	std::cout << "flying" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Flying());
	delete this;
}
void Idle::swimming(FSM* a)
{
	std::cout << "swimming" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
	a->setCurrent(new Swimming());
	delete this;
}