#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "NPC.h"
#include "DialogueBox.h"
#include "HelperFunctions.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480),
		"Dialogue Test.");
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::White);
	rectangle.setSize(sf::Vector2f(50, 50));

	Player testplayer(rectangle, 0.1f);

	NPC testnpc(rectangle);
	testnpc.setPosition(100, 200);
	std::string message1 = "You sense a terrifying presence...";
	std::string message2 = "The presence has disappeared.";
	std::string message3 = "Object found!";
	DialogueBox testDialogue(message1, sf::Color::White);
	sf::Font arial;
	/*
	* Gamers I don't know what I should put for the loadFromFile once I push this
	* I can't start from repo bc it won't find it (despite it being in the repo)
	*/
	if (!arial.loadFromFile("GameOff2024\\arial.ttf")) {
		std::cerr << "Can't find the font" << std::endl;
	}
	testDialogue.setFont(arial);
	testDialogue.setSize(window.getSize().x, window.getSize().y / 2);
	testDialogue.setPosition(0, window.getSize().y / 2);

	testnpc.setDialogue(message2, sf::Color::White);
	testnpc.setBoxSize(window.getSize().x, window.getSize().y / 2);
	testnpc.setBoxPosition(0, window.getSize().y / 2);
	testnpc.setDialogueFont(arial);
	testDialogue.changeDialogue(message2);
	std::cout << testDialogue.getInstances() << std::endl;
	testDialogue.changeDialogue(message3);
	std::cout << testDialogue.getInstances() << std::endl;
	testnpc.changeDialogue(message1);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed ||event.type == sf::Event::KeyReleased) 
			{
				testplayer.keyInput(event.key.code, event.type == sf::Event::KeyPressed);
				testDialogue.pressEToContinue(event.key.code, event.type == sf::Event::KeyPressed);
			}
		}
		testplayer.update();
		window.clear();
		testnpc.drawTo(window);
		testplayer.drawTo(window);
		testnpc.drawDialogue(window);
		testDialogue.draw(window);

		window.display();
	}
}