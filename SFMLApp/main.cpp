#include "TileMap.h"
#include "Game.h"
#include "DialogueBox.h"
#include <iostream>

// Function to check if the sprite can move to the new position
bool canMoveTo(const sf::Sprite& sprite, const TileMap& map, const sf::Vector2f& movement) {
    sf::Vector2u tileSize = map.getTileSize();
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::FloatRect futureBounds = spriteBounds;
    futureBounds.left += movement.x;
    futureBounds.top += movement.y;

    // Calculate the tile indices that the sprite is overlapping
    int startX = std::floor(futureBounds.left / (tileSize.x * map.getScaleX()));
    int startY = std::floor(futureBounds.top / (tileSize.y * map.getScaleY()));
    int endX = std::floor((futureBounds.left + futureBounds.width) / (tileSize.x * map.getScaleX()));
    int endY = std::floor((futureBounds.top + futureBounds.height) / (tileSize.y * map.getScaleY()));

    for (int y = startY; y <= endY; ++y) {
        for (int x = startX; x <= endX; ++x) {
            if (map.isSolidTile(x, y)) {
                return false; // Cannot move to a solid tile
            }
        }
    }

    return true; // Can move to non-solid tiles
}

int main()
{
    Game game;
    sf::Texture texture;
    TileMap map;
    sf::View view;

    view.setSize(sf::Vector2f(1000, 800));

    // Tile Map
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
    map.setScale(4.0f, 4.0f); // Scale up the tile map
    map.setDebugDrawing(false); // Enable debug drawing

    sf::RectangleShape block(sf::Vector2f(100.0f, 100.0f));
    block.setOutlineColor(sf::Color::Red);
    block.setFillColor(sf::Color::Black);
    block.setPosition(sf::Vector2f(100.0f, 100.0f));

    texture.loadFromFile("gato.png", sf::IntRect(0, 0, 32, 32));
    sf::Sprite sprite(texture);
    sprite.setScale(4.0f, 4.0f);
    sprite.setPosition(sf::Vector2f(500.0f, 330.0f));

    // Create a rectangle shape to represent the sprite's collision box
    sf::RectangleShape collisionBox;
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setOutlineThickness(1.0f);
    collisionBox.setOutlineColor(sf::Color::Green);

    // Load a font for the dialogue text
    sf::Font font;
    if (!font.loadFromFile("PixelatedEleganceRegular-ovyAA.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    // Create a dialogue box
    DialogueBox dialogueBox(font, "Look mom, I'm a cat!", sf::Vector2f(600.0f, 100.0f), sf::Vector2f(200.0f, 450.0f));

    bool showDialogue = false; // Flag to toggle dialogue box visibility

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    view.setCenter(sprite.getPosition());
    window.setView(view);

    const float movementSpeed = 0.1f; // Movement speed

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
                showDialogue = !showDialogue; // Toggle dialogue box visibility
        }

        sf::Vector2f movement(0.0f, 0.0f);

        if (!showDialogue) { // Only process movement if the dialogue box is not visible
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                movement.x -= movementSpeed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                movement.x += movementSpeed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                movement.y -= movementSpeed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                movement.y += movementSpeed;

            if (canMoveTo(sprite, map, movement)) {
                sprite.move(movement);
            }
        }

        // Update the collision box to match the sprite's global bounds
        collisionBox.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
        collisionBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));

        view.setCenter(sprite.getPosition());
        window.setView(view);

        // Position the dialogue box at the bottom of the screen
        sf::Vector2f viewCenter = window.getView().getCenter();
        sf::Vector2f viewSize = window.getView().getSize();
        dialogueBox.setPosition(sf::Vector2f(viewCenter.x - dialogueBox.getSize().x / 2, viewCenter.y + viewSize.y / 2 - dialogueBox.getSize().y - 10));

        window.clear();
        window.draw(map);
        window.draw(block);
        window.draw(sprite);
        window.draw(collisionBox); // Draw the collision box

        if (showDialogue) {
            dialogueBox.draw(window); // Draw the dialogue box
        }

        window.display();
    }

    return 0;
}
