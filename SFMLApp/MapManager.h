#pragma once
#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <vector>
#include "Map.h"

//All map names
enum class MapName {
	APARTMENT_
};

class MapManager
{
public:
	MapManager();

	//Add a new map
	void addMap(const std::string& name, std::shared_ptr<Map> map);

	//Switch to a specific map
	bool switchToMap(const std::string& name);

	//Get the current map
	std::shared_ptr<Map> getCurrentMap() { return this->currentMap; };

	//Draw the current map
	void drawCurrentMap(sf::RenderWindow& window);
private:
	//A map of room names to Map objects
	std::map<std::string, std::shared_ptr<Map>> allMaps;

	std::shared_ptr<Map> currentMap;
};

#endif

