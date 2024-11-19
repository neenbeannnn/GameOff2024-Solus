#include "Player.h"
Player::Player() : up(false), down(false), left(false), right(false)
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color::Blue);
	position = sf::Vector2f(0, 0);
	rect.setPosition(position);
}
Player::Player(sf::RectangleShape& rectShape, float spd) : rect(rectShape), up(false), down(false), left(false), right(false)
{
	rectShape.setPosition(position);
}
void Player::keyInput(sf::Keyboard::Key key, bool isPressed)
{
	if (isPressed) 
	{
		if (key == sf::Keyboard::W) {
			up = isPressed;
		}
		if (key == sf::Keyboard::A) {
			right = isPressed;
		}
		if (key == sf::Keyboard::S) {
			down = isPressed;
		}
		if (key == sf::Keyboard::D) {
			left = isPressed;
		}
	}
	else {
		up = false;
		down = false;
		right = false;
		left = false;
	}
}
void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(rect);
}
void Player::update()
{
	sf::Vector2f movement;
	if (up)
		movement.y -= 0.05f;
	if (down)
		movement.y += 0.05f;
	if (left)
		movement.x += 0.05f;
	if (right)
		movement.x -= 0.05f;
	rect.move(movement);
}
void Player::setPosition(float x, float y) 
{
	position = sf::Vector2f(x, y);
	rect.setPosition(position);
}
sf::Vector2f Player::getPosition() const
{
	return position;
}