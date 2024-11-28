#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "NPC.h"
#include "DialogueBox.h"
#include "HelperFunctions.h"
#include "Game.h"
#include "TileMap.h"
#include "Interactions.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480),
		"Dialogue Test.");
	sf::RectangleShape rectangle;
	TileMap map;
	const int level[] =
	{
		22, 23, 22, 23, 22, 23, 22, 23, 12, 13, 14, 15, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23,
		54, 55, 54, 55, 54, 55, 54, 55, 44, 45, 46, 47, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55,
		22, 23, 0, 1, 2, 1, 2, 3, 76, 77, 78, 79, 4, 1, 2, 3, 4, 1, 4, 5, 22, 23,
		54, 55, 32, 33, 33, 33, 33, 33, 108, 109, 110, 111, 33, 16, 17, 18, 19, 20, 21, 37, 54, 55,
		22, 23, 64, 33, 33, 33, 33, 33, 140, 141, 142, 143, 33, 48, 49, 50, 51, 52, 53, 69, 22, 23,
		54, 55, 96, 33, 33, 33, 33, 33, 172, 173, 174, 175, 33, 80, 81, 82, 83, 84, 85, 101, 54, 55,
		22, 23, 128, 33, 33, 33, 33, 33, 204, 205, 206, 207, 33, 112, 113, 114, 115, 116, 117, 133, 22, 23,
		54, 55, 32, 132, 132, 132, 132, 132, 132, 33, 33, 33, 33, 144, 145, 146, 147, 148, 149, 37, 54, 55,
		22, 23, 64, 6, 7, 8, 9, 10, 11, 33, 33, 33, 33, 176, 177, 178, 179, 180, 181, 69, 22, 23,
		54, 55, 96, 70, 71, 72, 73, 74, 43, 33, 33, 33, 33, 33, 33, 33, 33, 33, 36, 101, 54, 55,
		22, 23, 128, 102, 103, 104, 105, 106, 75, 33, 33, 33, 33, 33, 33, 33, 33, 33, 68, 133, 22, 23,
		54, 55, 32, 134, 135, 136, 137, 138, 107, 33, 33, 33, 33, 33, 33, 33, 33, 33, 100, 37, 54, 55,
		22, 23, 64, 166, 167, 168, 169, 170, 171, 33, 33, 33, 33, 33, 33, 33, 33, 33, 132, 69, 22, 23,
		54, 55, 160, 161, 162, 163, 164, 161, 162, 163, 164, 161, 162, 163, 164, 161, 162, 163, 164, 165, 54, 55,
		22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23, 22, 23,
		54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55, 54, 55
	};
	map.load("APT_TILEMAP.png", sf::Vector2u(32, 32), level, 22, 16);
	map.setScale(4.0f, 4.0f); // Scale up the tile map
	map.setDebugDrawing(false); // Enable debug drawing
	cout << "Creating interactables.." << endl;
	cout << "Finished." << endl;
	rectangle.setFillColor(sf::Color::White);
	rectangle.setSize(sf::Vector2f(32, 32));

	Player testplayer(rectangle, 0.1f);
	testplayer.setPosition(0.0f, 0.0f);

	NPC testnpc(rectangle);
	testnpc.setPosition(100, 200);
	std::string message1 = "You sense a terrifying presence...";
	std::string message2 = "The presence has disappeared.";
	std::string message3 = "Object found!";
	DialogueBox testDialogue(message1, sf::Color::White);
	Interactions interactable;
	interactable.createInteractable(testnpc);
	//sf::Font arial;
	/*
	* Gamers I don't know what I should put for the loadFromFile once I push this
	* I can't start from repo bc it won't find it (despite it being in the repo)
	*/
	/*if (!arial.loadFromFile("C:\\Users\\Ghoul\\source\\repos\\GameOff2024\\arial.ttf")) {
		std::cerr << "Can't find the font" << std::endl;
	}*/
	//testDialogue.setFont(arial);
	testDialogue.setSize(window.getSize().x, window.getSize().y / 2);
	testDialogue.setPosition(0, window.getSize().y / 2);

	testnpc.setDialogue(message2, sf::Color::White);

	testnpc.setBoxSize(window.getSize().x, window.getSize().y / 2);
	testnpc.setBoxPosition(0, window.getSize().y / 2);
	//testnpc.setDialogueFont(arial);

	NPC dummyNPC(rectangle);
	dummyNPC.setPosition(300, 300);
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
				testDialogue.talkToEm(event.key.code, event.type == sf::Event::KeyPressed);
				testplayer.getPosition();
				testnpc.getPosition();
				bool touching = interactable.checkProximity(testplayer);
				cout << "Interaction? " << touching << endl;
				
			}
		}

		testplayer.update();
		window.clear();
		testnpc.drawTo(window);
		dummyNPC.drawTo(window);
		testplayer.drawTo(window);
		testnpc.drawDialogue(window);
		testDialogue.draw(window);

		window.display();
	}
}