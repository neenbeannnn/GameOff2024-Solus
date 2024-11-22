#include "Map.h"

Map::Map(pair<float, float> spawnPoints, std::string tileset, int tileSize, int mapWidth, int mapHeight, const std::vector<int> tiles, const std::vector<int>& collisions) {
	this->spawnPoints = sf::Vector2f(spawnPoints.first, spawnPoints.second);
	this->tileset = tileset;
	this->tileSize = sf::Vector2u(tileSize, tileSize);
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;
	//Flatten the 2D array into a 1D vector
	this->tiles = tiles;
	this->collisions = collisions;
}

bool Map::load() {
	sf::Texture texture;
	//If failed to load tileset
	if (!texture.loadFromFile(this->tileset))
		return false;
	//Convert std::vector<int>& tiles to const int *
	const int* newTiles = this->tiles.data();
	
	this->map.load(this->tileset, this->tileSize, newTiles, this->mapWidth, this->mapHeight);
	this->map.setScale(4.0f, 4.0f); // Scale up the tile map
	this->map.setDebugDrawing(true); // Enable debug drawing
	return true;
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(map);
}

