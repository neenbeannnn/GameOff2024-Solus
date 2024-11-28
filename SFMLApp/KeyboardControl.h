#pragma once
#include "Player.h"
#include "DialogueBox.h"
#include "Interactions.h"
class KeyboardControl {

public:
	void checkKeyInput(sf::Keyboard::Key key, bool isPressed);
	void eForInteract(sf::Keyboard::Key key, bool isPressed,
		const Player& player, Interactions& interaction);

private:
	//Player controls
	bool up;
	bool down;
	bool left;
	bool right;
	sf::Keyboard::Key key;
	//Interaction, for now it's just e

};