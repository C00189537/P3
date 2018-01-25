////////////////////////////////////////////////////////////
//
// Created by Connor
//
////////////////////////////////////////////////////////////
#ifndef GAMEDATA_H_
#define GAMEDATA_H_
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include "SDL.h"

namespace FSMLIB
{

	class GameData
	{

	public:

		////////////////////////////////////////////////////////////
		/// Contains all the variables that will store values from 
		//  the GameData file. 
		///
		////////////////////////////////////////////////////////////

		//Sprite
		std::string playerImg;

		//Player
		int playerX;
		int playerY;
		int width;
		int heigth;

		//States
		bool walk;
		bool drive;
		bool fly;
		bool swim;

		//Player Speeds
		int walkSpeed;
		int driveSpeed;
		int airSpeedX;
		int airSpeedY;
		int swimSpeed;

		//Reset levels
		int groundLevel = 300;
		int seaLevel = 420;
		int skyLevel = 100;


	};
}
#endif;