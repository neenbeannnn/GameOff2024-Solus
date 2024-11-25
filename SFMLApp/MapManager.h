#pragma once

#include <vector>
#include "Map.h"
#include <iostream>
using namespace std;

//All map names
enum class MapName {
	APARTMENT_FIRST_FLOOR,
	APARTMENT_SECOND_FLOOR,
	APARTMENT_BATHROOM,
	APARTMENT_LEFT_ROOM,
	APARTMENT_RIGHT_ROOM,
	TOWN
};

class MapManager
{
public:
	MapManager();

	//Add a new map
	void addMap(MapName name, std::shared_ptr<Map> map);

	//Switch to a specific map
	void switchToMap(MapName map);

	//Get the current map
	std::shared_ptr<Map> getCurrentMap() { return this->currentMap; };

	//Draw the current map
	void drawCurrentMap(sf::RenderWindow& window);

	//List all maps
	void listAllMaps() {
		for (const auto& pair : allMaps) {
			cout<<"Map: "<<pair.second.get()<<endl;
		}
	}
private:
	//A map of room names to Map objects
	std::map<MapName, std::shared_ptr<Map>> allMaps;

	std::shared_ptr<Map> currentMap;
};


