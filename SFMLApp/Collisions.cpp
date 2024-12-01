#include "Collisions.h"


Collisions::Collisions(std::vector<int> collisions) {
    this->collisionLayer = collisions;
}

bool Collisions::checkCollision(float x, float y, int mapWidth, int tileSize) {
    
    int scaledTileSize = static_cast<int>(tileSize * 4.0f) - 2;
    int tileX = static_cast<int>(x) / scaledTileSize;
    int tileY = static_cast<int>(y) / scaledTileSize;

    //cout << "x: " << tileX << " y: " << tileY << " mapWidth: " << mapWidth << " tileSize: " << tileSize << endl;
    if (tileX >= 0 && tileX < mapWidth && tileY >= 0) {
        int index = tileY * mapWidth + tileX;
        return this->collisionLayer[index] == 1;
    }
    return false;
}