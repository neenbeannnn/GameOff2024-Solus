#pragma once

#ifndef COLLISIONS_H
#define COLLISIONS_H
class Collisions
{
public:
	//Defines all allowed Map Names
	enum class MapName {
		ApartmentFirstFloor,
		ApartmentSecondFloor,
		ApartmentLeftRoom,
		ApartmentBathroom,
		ApartmentRightRoom,

		Town,
		ForestStageOne,
		ForestStageTwo,
		ForestStageThree
	};

	Collisions();

	bool checkCollisionApartmentFirstFloor(float x, float y, int mapWidth, int tileSize);
	bool checkCollision(float x, float y, int mapWidth, int tileSize, int* collisionLayer);
private:
	MapName currentMap;
};

#endif
