#include "NPC.h"
NPC::NPC()
{

}
//will add sprite parameter later
NPC::NPC(sf::RectangleShape& npcSquare) : npc(npcSquare)
{
	npc.setFillColor(sf::Color::Green);
	position = sf::Vector2f(0, 0);
	npc.setPosition(position);
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
}
sf::Vector2f NPC::getPosition() const 
{
	return position;
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
	dialogueBox.pressEToContinue(key, isPressed);
}