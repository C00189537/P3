#include "GameLoader.h"
namespace FSMLIB
{

	GameLoader::GameLoader() {};
	GameLoader::~GameLoader() {};
	void GameLoader::parseJSONData(shared_ptr<GameData> &data)
	{
		// Retrieve the main root object
		m_value = JSON::Parse(m_JSONData.c_str());
		// Retrieve the main (root) object
		JSONObject root = getTopLevelJSONObject();

		//Load the global settings object
		JSONObject globalSettings = root[L"global_settings"]->AsObject();

		//Player
		JSONObject tempPlayer = globalSettings[L"player"]->AsObject();
		data->playerX = tempPlayer[L"playerX"]->AsNumber();
		data->playerY = tempPlayer[L"playerY"]->AsNumber();
		data->width = tempPlayer[L"width"]->AsNumber();
		data->heigth = tempPlayer[L"heigth"]->AsNumber();
		data->walkSpeed = tempPlayer[L"walkSpeed"]->AsNumber();
		data->driveSpeed = tempPlayer[L"driveSpeed"]->AsNumber();
		data->airSpeedX = tempPlayer[L"airSpeedX"]->AsNumber();
		data->airSpeedY = tempPlayer[L"airSpeedY"]->AsNumber();
		data->swimSpeed = tempPlayer[L"swimSpeed"]->AsNumber();

		JSONObject tempStates = globalSettings[L"states"]->AsObject();
		data->walk = tempStates[L"walk"]->AsBool();
		data->drive = tempStates[L"drive"]->AsBool();
		data->fly = tempStates[L"fly"]->AsBool();
		data->swim = tempStates[L"swim"]->AsBool();

		JSONObject tempPos = globalSettings[L"yPositions"]->AsObject();
		data->groundLevel = tempPos[L"ground"]->AsNumber();
		data->skyLevel = tempPos[L"sky"]->AsNumber();
		data->seaLevel = tempPos[L"sea"]->AsNumber();




	}
	void GameLoader::loadJSONData(std::string const & filename)
	{
		m_JSONData.clear();

		// Loads all the data in the file into a std::string.
		std::ifstream myfile(filename);
		std::string line;
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				m_JSONData.append(line);
			}
			myfile.close();
			std::cout << m_JSONData << std::endl;
		}
		else
		{
			std::string errorMessage = "Could not open " + filename + " exiting!";
			std::cout << "Could not open " + filename + " exiting!" << std::endl;
			throw std::exception(errorMessage.c_str());
		}
	}
	JSONObject GameLoader::getTopLevelJSONObject() {
		// Retrieve the main (root) object
		JSONObject root;

		if (m_value->IsObject() == false)
		{
			throw std::exception("Problem with root element in json file, exiting");
		}
		root = m_value->AsObject();

		return root;
	}
}