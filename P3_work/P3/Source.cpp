#define SDL_MAIN_HANDLED
#include "stdafx.h"
#include "SDL.h"
#include "Gameloader.h"


int main()
{
	std::shared_ptr<GameData> data;
	GameLoader gameLoader;

	data = make_shared<GameData>();
	std::string filename = ".\\GameData.json";
	gameLoader.loadJSONData(filename);
	gameLoader.parseJSONData(data);


	system("pause");
	return 0;
}