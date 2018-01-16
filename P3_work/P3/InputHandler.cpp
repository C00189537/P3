#include "InputHandler.h"
#include <SDL.h>


void InputHandler::handleInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_1:
			
			break;
		case SDLK_2:
			
			break;
		default:
			
			break;
		}
	}
}
