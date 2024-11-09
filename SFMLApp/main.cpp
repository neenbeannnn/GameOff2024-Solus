#include"SFML/Graphics.hpp"

int main()
{
    sf::Texture texture;

    if (!texture.loadFromFile("gato.png", sf::IntRect(0, 0, 32, 32)))
    {
        //
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(100.0f, 100.0f));
    sprite.setScale(sf::Vector2f(4.0f, 4.0f));

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}