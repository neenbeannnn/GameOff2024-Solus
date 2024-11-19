#pragma once
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Movement.h"

class Player
{
public:
    Player();
    void init(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scale);
    void update(const TileMap& map, const Movement& movement);
    void render(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape collisionBox;
};

