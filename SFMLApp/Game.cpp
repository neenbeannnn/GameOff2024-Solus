#include "Game.h"
#include <iostream>
#include<vector>

Game::Game()
    : window(sf::VideoMode(800, 600), "SFML works!"),
    view(sf::Vector2f(400, 300), sf::Vector2f(800, 600)),
    movement(6.0f), // Set the movement speed here
    showDialogue(false) //Dialogue box showing
{
    initWindow();
    initView();
    initTileMap();
    initPlayer();
    initDialogueBox();
}

//Destructor
Game::~Game()
{
}

void Game::initWindow()
{
    window.setFramerateLimit(60);
}

void Game::initView()
{
    view.setSize(sf::Vector2f(960, 720));
    view.setCenter(player.getPosition());
    window.setView(view);
}

void Game::initTileMap()
{
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

    map.load("NEW_TILEMAP.png", sf::Vector2u(32, 32), level, 22, 16);
    map.setScale(4.0f, 4.0f);

    //Debug drawing shows a red outline on each tile
    map.setDebugDrawing(true);
}

void Game::initPlayer()
{
    player.init("gato.png", sf::Vector2f(500.0f, 330.0f), sf::Vector2f(4.0f, 4.0f));
}

void Game::initDialogueBox()
{
	
    dialogueBox.init("PixelatedEleganceRegular-ovyAA.ttf", "Look mom, I'm a cat!", sf::Vector2f(600.0f, 100.0f), sf::Vector2f(200.0f, 450.0f));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    

    while (window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
			showDialogue = dialogueBox.iterThruText();
    }
}

void Game::update(sf::Time deltaTime)
{
    if (!showDialogue) { // Only process movement if the dialogue box is not visible
        player.update(map, movement);
    }

    view.setCenter(player.getPosition());
    window.setView(view);

    // Position the dialogue box at the bottom of the screen
    sf::Vector2f viewCenter = window.getView().getCenter();
    sf::Vector2f viewSize = window.getView().getSize();
    dialogueBox.setPosition(sf::Vector2f(viewCenter.x - dialogueBox.getSize().x / 2, viewCenter.y + viewSize.y / 2 - dialogueBox.getSize().y - 10));
	
}

void Game::render()
{
    window.clear();
    window.draw(map);
    player.render(window);

    if (showDialogue) {
        dialogueBox.draw(window); // Draw the dialogue box
    }

    window.display();
}
