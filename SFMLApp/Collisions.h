#pragma once

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include <iostream>
using namespace std;

class Collisions
{
public:

	Collisions(std::vector<int> collisions);

	bool checkCollision(float x, float y, int mapWidth, int tileSize);
private:
	int* collisionLayer;
};

#endif
