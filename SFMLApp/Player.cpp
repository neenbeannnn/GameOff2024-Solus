#include "Player.h"
#include <iostream>

Player::Player()
{
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setOutlineThickness(1.0f);
    collisionBox.setOutlineColor(sf::Color::Green);
}

void Player::init(const std::string& textureFile, const sf::Vector2f& position, const sf::Vector2f& scale)
{
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Failed to load texture" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(scale);
    sprite.setPosition(position);
}

void Player::update(const TileMap& map, const Movement& movement)
{
    sf::Vector2f move = movement.getMovement();
    if (movement.canMoveTo(sprite, map, move)) {
        sprite.move(move);
    }

    // Update the collision box to match the sprite's global bounds
    collisionBox.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
    collisionBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(collisionBox); // Draw the collision box
}

sf::FloatRect Player::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

void Player::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

