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
//TODO: Add - Door doors, Interactables interactables
public:
	//Constructor for Map
	Map(pair<float, float> spawnPoints, std::string tileset, int tileSize, int mapWidth, int mapHeight, const std::vector<int> tiles, const std::vector<int>& collisions);

	//Returns true if successfully loaded
	bool load();

	//Draw the map
	void draw(sf::RenderWindow& window);

	//Collision checking
	bool handleCollision(sf::Vector2f& newPosition, sf::Vector2f movement);

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
};

#endif

