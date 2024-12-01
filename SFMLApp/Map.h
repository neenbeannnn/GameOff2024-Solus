#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <string>
#include "TileMap.h"
#include "Collisions.h"

using namespace std;
class Map
{
public:
	//Constructor for Map
	//TODO implement bool canGoOut
	Map(
		pair<float, float> spawnPoints, 
		std::string tileset, int tileSize, 
		int mapWidth, int mapHeight, 
		const std::vector<int> tiles, 
		const std::vector<int>& collisions, 
		bool canMoveOut = true, 
		std::vector<std::string> decorTileSet = {}, 
		int decorTileSize = 16
	);

	//Get the Spawn Points
	sf::Vector2f getSpawnPoints() { return this->spawnPoints; }
	
	//Returns true if successfully loaded
	bool load();

	//Draw the map
	void draw(sf::RenderWindow& window);

	//Collision checking
	bool handleCollision(sf::Vector2f& newPosition, sf::Vector2f movement);

	//If conditions are true, then change canGoOut to True
	void setCanGoOut();
	//Apartment: once you interact with all interactables you can go to Town
	//Town: once you interact with the villagers with the dog you can go to Forest

private:
	TileMap map;
	sf::Vector2f spawnPoints;		//Spawn points specific to each map
	string tileset;					//Location of tileset for map relative to main.cpp
	sf::Vector2u tileSize;
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::vector<int> tiles;
	std::vector<int> collisions;
	Collisions *collisionHandler;
	const float scale = 4.0f;
	bool canGoOut;
	std::vector<std::string> decorTileSet;
	sf::Vector2u decorTileSize;
};

#endif

