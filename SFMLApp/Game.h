#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    sf::Time dt;
};