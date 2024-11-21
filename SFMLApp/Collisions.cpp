#include "Collisions.h"
#include <vector>
#include <iostream>
using namespace std;

int apartmentFirstFloorCollisions[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};


Collisions::Collisions()
{
}

//Helper Functions (for each area)
bool Collisions::checkCollisionApartmentFirstFloor(float x, float y, int mapWidth, int tileSize) {
    return checkCollision(x, y, mapWidth, tileSize, apartmentFirstFloorCollisions);
}

//End of Helper Functions

bool Collisions::checkCollision(float x, float y, int mapWidth, int tileSize, int* collisionLayer) {
    
    int scaledTileSize = static_cast<int>(tileSize * 4.0f) - 2;
    int tileX = static_cast<int>(x) / scaledTileSize;
    int tileY = static_cast<int>(y) / scaledTileSize;

    //cout << "x: " << tileX << " y: " << tileY << " mapWidth: " << mapWidth << " tileSize: " << tileSize << endl;
    if (tileX >= 0 && tileX < mapWidth && tileY >= 0) {
        int index = tileY * mapWidth + tileX;
        return collisionLayer[index] == 1;
    }
    return false;
}