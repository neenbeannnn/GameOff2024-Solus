#include "Map.h"

Map::Map(pair<float, float> spawnPoints, 
	std::string tileset,
	int tileSize, 
	int mapWidth, 
	int mapHeight,
	const std::vector<int> tiles,
	const std::vector<int>& collisions, 
	bool canMoveOut,
	std::vector<std::string> decorTileSet,
	int decorTileSize
	) {
		this->spawnPoints = sf::Vector2f(spawnPoints.first, spawnPoints.second);
		this->tileset = tileset;
		this->tileSize = sf::Vector2u(tileSize, tileSize);
		this->mapWidth = mapWidth;
		this->mapHeight = mapHeight;
		//Flatten the 2D array into a 1D vector
		this->tiles = tiles;
		this->collisions = collisions;
		this->collisionHandler = new Collisions(collisions);
		this->canGoOut = canMoveOut,
		this->decorTileSet = decorTileSet;
		this->decorTileSize = sf::Vector2u(decorTileSize, decorTileSize);
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
	//this->map.setDebugDrawing(true); // Enable debug drawing

	//Load the decor layer (16x16 tiles)
	for (const std::string& decorTile : this->decorTileSet) {
		sf::Texture decorTexture;
		if (!decorTexture.loadFromFile(decorTile))
			return false;
	}

	return true;
}

void Map::draw(sf::RenderWindow& window) {
	window.draw(map);
}

bool Map::handleCollision(sf::Vector2f& newPosition, sf::Vector2f movement) {
	if (!this->collisionHandler->checkCollision(newPosition.x, newPosition.y, this->mapWidth, this->tileSize.x)) {
		newPosition += movement;
		return true;
	}
	return false;
}

void Map::setCanGoOut() {
	this->canGoOut = true;
}

