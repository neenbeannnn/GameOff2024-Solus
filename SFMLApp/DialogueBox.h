#pragma once
#include "SFML\Graphics.hpp"
class DialogueBox {
public:
	//Constructors
	DialogueBox();
	DialogueBox(const std::string& msg, sf::Color textColor);
	//Displaying the box
	void draw(sf::RenderWindow& window);
	void displayDialogue(bool isVisible);
	void talkToEm(sf::Keyboard::Key key, bool isPressed);
	void changeDialogue	(const std::string& newMsg);
	//Setters for default constructor...
	void setPosition(float x, float y);
	void setTextPosition(float x, float y);
	void setFont(sf::Font& font);
	void setSize(float x, float y);
	void setCharAndOutlineSize(int charSize, int outlineSize);
	void setDialogueColors(sf::Color txtColor, sf::Color outLineColor,
		sf::Color boxColor);
	void setDialogue(const std::string& message);

	//And of course, getters
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	int getInstances() const;
	int getCharSize() const;
	bool isVisible() const;



private:
	sf::RectangleShape box;
	sf::Text text;
	sf::Font font;
	static sf::Font defaultFontTest;
	std::vector<std::string> dialogueHolder;
	bool visible;
	int timesChanged{ 0 }; //checking how many times dialogue has changed,
	//for vector usage
};