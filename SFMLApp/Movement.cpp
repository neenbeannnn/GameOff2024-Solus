#include "Movement.h"

Movement::Movement(float speed)
    : speed(speed)
{
}

sf::Vector2f Movement::getMovement() const
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed;

    return movement;
}

bool Movement::canMoveTo(const sf::Sprite& sprite, const TileMap& map, const sf::Vector2f& movement) const
{
    sf::Vector2u tileSize = map.getTileSize();
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::FloatRect futureBounds = spriteBounds;
    futureBounds.left += movement.x;
    futureBounds.top += movement.y;

    // Calculate the tile indices that the sprite is overlapping
    int startX = std::floor(futureBounds.left / (tileSize.x * map.getScaleX()));
    int startY = std::floor(futureBounds.top / (tileSize.y * map.getScaleY()));
    int endX = std::floor((futureBounds.left + futureBounds.width) / (tileSize.x * map.getScaleX()));
    int endY = std::floor((futureBounds.top + futureBounds.height) / (tileSize.y * map.getScaleY()));

    for (int y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            if (map.isSolidTile(x, y)) {
                return false; // Cannot move to a solid tile
            }
        }
    }

    return true; // Can move to non-solid tiles
}
