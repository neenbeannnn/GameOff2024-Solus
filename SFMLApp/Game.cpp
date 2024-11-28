#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "SFML Game"), dt(sf::seconds(1.f / 60.f))
{
}

Game::~Game()
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > dt)
        {
            timeSinceLastUpdate -= dt;
            processEvents();
            update(dt);
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
    }
}

void Game::update(sf::Time deltaTime)
{
    // Update game logic here
}

void Game::render()
{
    window.clear();
    // Draw game objects here
    window.display();
}