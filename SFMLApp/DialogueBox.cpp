#include "DialogueBox.h"
#include "SFML\Graphics.hpp"
#include <iostream>


DialogueBox::DialogueBox() : visible(false)
{
}
DialogueBox::DialogueBox(const std::string& msg, sf::Color textColor) : visible(false)
{
	box.setSize(sf::Vector2f (300, 100));
	box.setFillColor(sf::Color(50, 50, 50, 200));
	box.setOutlineThickness(2);
	box.setOutlineColor(sf::Color::White);

	dialogueHolder.push_back(msg);
	text.setFillColor(textColor);
	text.setCharacterSize(20);
}
//Setters end
void DialogueBox::setFont(sf::Font& font) {
	text.setFont(font);
}

void DialogueBox::setPosition(float x, float y)
{
	box.setPosition(x, y);
	text.setPosition(x + 10, y + 10);
}
void DialogueBox::setSize(float x, float y) 
{
	box.setSize(sf::Vector2f(x, y));
}
void DialogueBox::setCharAndOutlineSize(int charSize, int outlineSize) 
{
	text.setCharacterSize(charSize);
	box.setOutlineThickness(outlineSize);
}
//Overloaded Dialogue Colors - goes from text color, to outlineColor, to
//the color of the box. option to make it transparent or not.
void DialogueBox::setDialogueColors(sf::Color& txtColor, 
	sf::Color& outLineColor, sf::Color& boxColor) 
{
	text.setFillColor(txtColor);
	box.setOutlineColor(outLineColor);
	box.setFillColor(boxColor);
}
void DialogueBox::setDialogue(const std::string& message) 
{
	text.setString(message);
}

//Setters end
//Getters begin
sf::Vector2f DialogueBox::getPosition() const
{
	return box.getPosition();
}
sf::Vector2f DialogueBox::getSize() const
{
	return box.getSize();
}
int DialogueBox::getCharSize() const
{
	return text.getCharacterSize();
}
int DialogueBox::getInstances() const
{
	return timesChanged;
}
//getters end

void DialogueBox::pressEToContinue(sf::Keyboard::Key key, bool isPressed) 
{

	if(key == sf::Keyboard::E && isPressed)
	{
		visible = !visible;
		if (timesChanged < dialogueHolder.size()) {
			if (visible) 
			{
				text.setString(dialogueHolder[timesChanged]);
				std::cout << dialogueHolder[timesChanged];
				timesChanged++;
			}
		}
	}
}
void DialogueBox::draw(sf::RenderWindow& window)
{
	if (visible) {
		window.draw(box);
		window.draw(text);
	}
}
void DialogueBox::displayDialogue(bool isVisible) 
{
	visible = isVisible;
}
void DialogueBox::changeDialogue(const std::string newMsg) 
{
	dialogueHolder.push_back(newMsg);
}