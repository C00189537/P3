#define SDL_MAIN_HANDLED
#include "stdafx.h"
#include "SDL.h"
#include <SDL_image.h> 
#include "Gameloader.h"


int main(int argc, char* argv[]) {

	//Load data from the file
	std::shared_ptr<GameData> data;
	GameLoader gameLoader;

	data = make_shared<GameData>();
	std::string filename = ".\\GameData.json";
	gameLoader.loadJSONData(filename);
	gameLoader.parseJSONData(data);

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	SDL_Event e;

	// creates SDL window
	SDL_Window * window = SDL_CreateWindow("Finite State Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	// sets renderer for window
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	// loads image
	SDL_Texture * image = IMG_LoadTexture(renderer, "square.bmp");
	if (image == nullptr)
	{
		std::cout << "image failed to load" << std::endl;
	}
	
	bool running = true;

	//InputHandler input;

	SDL_Rect rect;
	rect.x = 300;
	rect.y = 300;
	rect.w = 32;
	rect.h = 32;

	while (running) {
		// reads event event
		SDL_PollEvent(&e);

		//input.handleInput(e, verticalPos);

		// clears and redraws window
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, image, NULL, &rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}