#pragma once
#include <SFML/Graphics.hpp>
#include "Animations.h"
#include <vector>

using namespace std;
//All cat animations
enum class CatAnimation {
	CAT_SITTING,
	CAT_RIGHT,
	CAT_LEFT,
	CAT_FORWARD,
	CAT_BACKWARD
};

class CatSprite
{
public:
	CatSprite();

	//Add a new animation
	void addAnimation(CatAnimation name, std::shared_ptr<Animations> animation);

	//Switch to an animation
	void switchToAnimation(CatAnimation name);

	//Get the current animation
	std::shared_ptr<Animations> getCurrentAnimation() { return this->currentAnimation; };

private:
	sf::Sprite sprite;		//The sprite
	std::map<CatAnimation, std::shared_ptr<Animations>> allAnimations;
	std::shared_ptr<Animations> currentAnimation; //Current animation
	sf::Vector2f position;	//Current position of the sprite
};

