#include "KeyboardControl.h"
#include "SFML\Graphics.hpp"


//void KeyboardControl::checkKeyInput(sf::Keyboard::Key key, bool isPressed)
//{
//	if (isPressed)
//	{
//		if (key == sf::Keyboard::W) {
//			up = isPressed;
//		}
//		if (key == sf::Keyboard::A) {
//			right = isPressed;
//		}
//		if (key == sf::Keyboard::S) {
//			down = isPressed;
//		}
//		if (key == sf::Keyboard::D) {
//			left = isPressed;
//		}
//	}
//	else {
//		up = false;
//		down = false;
//		right = false;
//		left = false;
//	}
//}

void KeyboardControl::eForInteract(sf::Keyboard::Key key, bool isPressed,
		const Player& player, Interactions& interaction)
{
	if (key == sf::Keyboard::E && isPressed)
	{
		if (interaction.checkProximity(player)) 
		{
			cout << "I'll set the interaction up later!" << endl;
		}
		else 
		{
			cout << "I'm pressing E and nothing's happening! Nothing should!" << endl;
		}
	}

}