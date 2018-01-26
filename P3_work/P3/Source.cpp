#define SDL_MAIN_HANDLED
#include "stdafx.h"
#include "SDL.h"
#include <SDL_image.h> 
#include "Gameloader.h"
#include "StateHandler.h"

using namespace FSMLIB;


int main(int argc, char* argv[]) {

	//Load data from the file
	std::shared_ptr<GameData> data;
	std::shared_ptr<GameData> carData;
	std::shared_ptr<GameData> planeData;
	std::shared_ptr<GameData> submarineData;
	GameLoader gameLoader;

	data = make_shared<GameData>();
	std::string filename = ".\\GameData.json";
	gameLoader.loadJSONData(filename);
	gameLoader.parseJSONData(data);

	carData = make_shared<GameData>();
	std::string cfilename = ".\\Car.json";
	gameLoader.loadJSONData(cfilename);
	gameLoader.parseJSONData(carData);

	planeData = make_shared<GameData>();
	std::string pfilename = ".\\Plane.json";
	gameLoader.loadJSONData(pfilename);
	gameLoader.parseJSONData(planeData);

	submarineData = make_shared<GameData>();
	std::string sfilename = ".\\Submarine.json";
	gameLoader.loadJSONData(sfilename);
	gameLoader.parseJSONData(submarineData);

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	SDL_Event e;

	// creates SDL window
	SDL_Window * window = SDL_CreateWindow("Finite State Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480, 0);

	// sets renderer for window
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	// loads image
	SDL_Texture * image = IMG_LoadTexture(renderer, "square.bmp");
	SDL_Texture * cimage = IMG_LoadTexture(renderer, "car.bmp");
	SDL_Texture * pimage = IMG_LoadTexture(renderer, "plane.bmp");
	SDL_Texture * simage = IMG_LoadTexture(renderer, "submarine.bmp");
	SDL_Texture * bimage = IMG_LoadTexture(renderer, "background.bmp");

	bool running = true;

	StateHandler sHandle(data);
	StateHandler carHandle(carData);
	StateHandler planeHandle(planeData);
	StateHandler submarineHandle(submarineData);

	SDL_Rect rect1;
	rect1.w = 32;
	rect1.h = 32;

	SDL_Rect rect2;
	rect2.w = 32;
	rect2.h = 32;

	SDL_Rect rect3;
	rect3.w = 32;
	rect3.h = 32;

	SDL_Rect rect4;
	rect4.w = 32;
	rect4.h = 32;

	SDL_Rect rect5;
	rect5.x = 0;
	rect5.y = 0;
	rect5.w = 800;
	rect5.h = 480;

	while (running) {
		// reads event event
		SDL_PollEvent(&e);

		sHandle.handleState(e);
		SDL_Point temp = sHandle.getPos(800);
		rect1.x = temp.x;
		rect1.y = temp.y;
		
		carHandle.handleState(e);
		temp = carHandle.getPos(800);
		rect2.x = temp.x;
		rect2.y = temp.y;
		planeHandle.handleState(e);
		temp = planeHandle.getPos(800);
		rect3.x = temp.x;
		rect3.y = temp.y;

		submarineHandle.handleState(e);
		temp = submarineHandle.getPos(800);
		rect4.x = temp.x;
		rect4.y = temp.y;

		// clears and redraws window
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, bimage, NULL, &rect5);

		SDL_RenderCopy(renderer, image, NULL, &rect1);
		SDL_RenderCopy(renderer, cimage, NULL, &rect2);
		SDL_RenderCopy(renderer, pimage, NULL, &rect3);
		SDL_RenderCopy(renderer, simage, NULL, &rect4);
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(image);
	SDL_DestroyTexture(cimage);
	SDL_DestroyTexture(simage);
	SDL_DestroyTexture(pimage);
	SDL_DestroyTexture(bimage);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
