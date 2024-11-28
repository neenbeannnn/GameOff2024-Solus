#include "NPC.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <iomanip>
NPC::NPC()
{

}
//will add sprite parameter later
NPC::NPC(sf::RectangleShape& npcSquare) : npc(npcSquare), textPrompt("Talk (e)", sf::Color::White)
{
	npc.setFillColor(sf::Color::Green);
	position = sf::Vector2f(0, 0);
	npc.setPosition(position);
	npc.setSize(sf::Vector2f(32, 32));

	textPrompt.setSize(50, 20);
	textPrompt.setCharAndOutlineSize(15, 1);
	textPrompt.setDialogueColors(sf::Color::White, sf::Color::White, sf::Color::Transparent);

}

void NPC::setPosition(float x, float y) 
{
	position = sf::Vector2f(x, y);
	npc.setPosition(position);
}

//NPC stuff
void NPC::drawTo(sf::RenderWindow& window) 
{
	window.draw(npc);
	textPrompt.draw(window);
}
void NPC::getPosition() const 
{
	std::cout << std::fixed << std::setprecision(3)
		<< "NPC Position (x: " + std::to_string(position.x) + ", y:"
		+ std::to_string(position.y) + ")" << std::endl;
}
sf::FloatRect NPC::getBoundBox() const
{
	return npc.getGlobalBounds();

}
//This function will bring up a prompt that tells the player to press E to talk.
void NPC::interactPrompt()
{
	std::cout << "Player is close to NPC" << std::endl;
	textPrompt.setDialogue("Talk (e)"); 
	textPrompt.setPosition(npc.getPosition().x + 35, npc.getPosition().y + 5);
	textPrompt.displayDialogue(displayPrompt);
	std::cout << "Displaying prompt" << std::endl;
	textPrompt.setTextPosition(npc.getPosition().x + 35, npc.getPosition().y + 5);
	std::cout << "Prompt visible?: True (1), False(0)"
		<< textPrompt.isVisible() << std::endl;
	
}

void NPC::togglePrompt()
{
	textPrompt.displayDialogue(!displayPrompt);
	std::cout << "Toggle Prompt visible?: True (1), False(0)" 
				<< textPrompt.isVisible() << std::endl;
}


//Dialogue box classes

void NPC::setBoxSize(float x, float y) 
{
	dialogueBox.setSize(x, y);
}
void NPC::setDialogue(const std::string& message, sf::Color textColor)
{
	dialogueBox = DialogueBox(message, textColor);

}
void NPC::setBoxPosition(float x, float y) {
	dialogueBox.setPosition(x, y);
}
void NPC::setDialogueFont(sf::Font& font)
{
	dialogueBox.setFont(font);
}
void NPC::drawDialogue(sf::RenderWindow& window)
{
	dialogueBox.draw(window);
}
void NPC::displayDialogue(bool isVisible)
{
	dialogueBox.displayDialogue(isVisible);
}
void NPC::changeDialogue(const std::string newMsg) 
{
	dialogueBox.changeDialogue(newMsg);
}
void NPC::pressEToContinue(sf::Keyboard::Key key, bool isPressed)
{
	dialogueBox.talkToEm(key, isPressed);
}