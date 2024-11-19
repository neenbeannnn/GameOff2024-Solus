#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player();
	Player(sf::RectangleShape& rectShape, float spd);
	void keyInput(sf::Keyboard::Key key, bool isPressed);
	void drawTo(sf::RenderWindow& window);
	void update();
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;

private:
	sf::RectangleShape rect;
	sf::Vector2f position;
	bool up;
	bool down;
	bool left;
	bool right;
};