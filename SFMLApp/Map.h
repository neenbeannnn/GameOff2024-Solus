#pragma once
#ifndef MAP_H
#define MAP_H

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include <string>
using namespace std;
class Map
{
//TODO: Add - Door doors, Interactables interactables
public:
	Map(pair<float, float> spawnPoints, string tileset, int tileSize, int mapWidth, int mapHeight, std::vector<int>& tiles, std::vector<int>& collisions) {
		this->spawnPoints			= sf::Vector2f(spawnPoints.first, spawnPoints.second);
		this->tileset				= tileset;
		this->tileSize				= sf::Vector2u(tileSize, tileSize);
		this->mapWidth				= mapWidth;
		this->mapHeight				= mapHeight;
		this->tiles					= tiles;
		this->collisions			= collisions;
	}

	//Returns true if successfully loaded
	bool load() {

	}

private:
	sf::Vector2f spawnPoints;		//Spawn points specific to each map
	string tileset;					//Location of tileset for map relative to main.cpp
	sf::Vector2u tileSize;
	unsigned int mapWidth;
	unsigned int mapHeight;
	std::vector<int> tiles;
	std::vector<int> collisions;

	const float scale = 4.0f;
};

#endif

