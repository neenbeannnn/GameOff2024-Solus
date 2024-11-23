#include "MapManager.h"

MapManager::MapManager() {}

//Add a new map
void MapManager::addMap(const std::string& name, std::shared_ptr<Map> map) {
	allMaps[name] = map;
	if (!currentMap) {
		currentMap = map; //Sets the first added map as the default map
	}
}

//Switch to a specific map and return True if found
bool MapManager::switchToMap(const std::string& name) {
	auto newMap = allMaps.find(name);
	if (newMap != allMaps.end()) {
		this->currentMap = newMap->second;
		return true;
	}
	return false;
}