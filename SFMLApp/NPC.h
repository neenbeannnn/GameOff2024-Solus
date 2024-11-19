#pragma once
#include "SFML\Graphics.hpp"
#include "DialogueBox.h"
class NPC
{
public:
	NPC();
	NPC(sf::RectangleShape& npcShape);
	//NPC(std::string spriteDirectory);
	void drawTo(sf::RenderWindow& window);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	/*literally all dialogue box stuff
	decided not to use inheritance bc an NPC is not a dialogue box.
	obviously the functions aren't complete but first */
	void setBoxSize(float x, float y);
	void setBoxPosition(float x, float y);
	void setDialogue(const std::string& message, sf::Color textColor);
	void setDialogueFont(sf::Font& font);
	void drawDialogue(sf::RenderWindow& window);
	void displayDialogue(bool isVisible);
	void changeDialogue(const std::string newMsg);
	void pressEToContinue(sf::Keyboard::Key key, bool isPressed);

private:
	/* someone is personally going to have to
	change this to a sprite, remember, for some
	reason my end wont load any sprites */

	sf::RectangleShape npc;
	sf::Vector2f position;
	DialogueBox dialogueBox;

	//sf::Sprite sprite;
	//sf::Texture texture;

};

