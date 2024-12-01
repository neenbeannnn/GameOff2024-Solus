#pragma once

#include <SFML/Graphics.hpp>
class Animations
{
public:
	Animations(sf::Texture& texture, sf::Vector2u imageCount, float switchTime);

	void update(int row, float deltaTime);
	sf::IntRect getUVRect() const;

private:
	sf::Vector2u imageCount;	//Total number of images in Animation
	sf::Vector2u currentImage;	//Current frame
	float  totalTime;			//Time since last switch
	float switchTime;			//Time between frame switches
	sf::IntRect uvRect;			//Texture rectangle for the current frame
};

