#pragma once
#include <SFML/Graphics.hpp>
#include "TileMap.h"

class Movement
{
public:
    Movement(float speed);
    sf::Vector2f getMovement() const;
    bool canMoveTo(const sf::Sprite& sprite, const TileMap& map, const sf::Vector2f& movement) const;

private:
    float speed;
};
