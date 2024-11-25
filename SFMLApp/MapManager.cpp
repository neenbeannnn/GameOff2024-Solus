#include "MapManager.h"

MapManager::MapManager() {}

//Add a new map
void MapManager::addMap(MapName name, std::shared_ptr<Map> map) {
	allMaps[name] = map;
	if (!currentMap) {
		currentMap = map; //Sets the first added map as the default map
	}
}

//Switch to a specific map and return True if found
void MapManager::switchToMap(MapName map) {
	auto newMap = allMaps.find(map);
	currentMap = newMap->second;
}