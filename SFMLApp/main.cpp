#include "TileMap.h"
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
    sf::Texture texture;
    TileMap map;
    sf::View view;

    view.setSize(sf::Vector2f(800, 600));

    // Tile Map
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8);
    map.setScale(4.0f, 4.0f); // Scale up the tile map
    map.setDebugDrawing(true); // Enable debug drawing

    sf::RectangleShape block(sf::Vector2f(100.0f, 100.0f));
    block.setOutlineColor(sf::Color::Red);
    block.setFillColor(sf::Color::Black);
    block.setPosition(sf::Vector2f(100.0f, 100.0f));

    texture.loadFromFile("gato.png", sf::IntRect(0, 0, 32, 32));
    sf::Sprite sprite(texture);
    sprite.setScale(4.0f, 4.0f);
    sprite.setPosition(sf::Vector2f(500.0f, 230.0f));

    // Create a rectangle shape to represent the sprite's collision box
    sf::RectangleShape collisionBox;
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setOutlineThickness(1.0f);
    collisionBox.setOutlineColor(sf::Color::Green);

    // Create a rectangle shape for the dialogue box
    sf::RectangleShape dialogueBox(sf::Vector2f(400.0f, 100.0f));
    dialogueBox.setFillColor(sf::Color::White);
    dialogueBox.setOutlineThickness(1.0f);
    dialogueBox.setOutlineColor(sf::Color::Black);

    // Load a font for the dialogue text
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    // Create a text object for the dialogue text
    sf::Text dialogueText("Sample text", font, 20);
    dialogueText.setFillColor(sf::Color::Black);

    bool showDialogue = false; // Flag to toggle dialogue box visibility

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    view.setCenter(sprite.getPosition());
    window.setView(view);

    const float movementSpeed = 0.2f; // Movement speed

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

        // Update the collision box to match the sprite's global bounds
        collisionBox.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
        collisionBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));

        view.setCenter(sprite.getPosition());
        window.setView(view);

        // Position the dialogue box and text at the bottom of the screen
        sf::Vector2f viewCenter = window.getView().getCenter();
        sf::Vector2f viewSize = window.getView().getSize();
        dialogueBox.setPosition(viewCenter.x - dialogueBox.getSize().x / 2, viewCenter.y + viewSize.y / 2 - dialogueBox.getSize().y - 10);
        dialogueText.setPosition(dialogueBox.getPosition().x + 20, dialogueBox.getPosition().y + 20);

        window.clear();
        window.draw(map);
        window.draw(block);
        window.draw(sprite);
        window.draw(collisionBox); // Draw the collision box

        if (showDialogue) {
            window.draw(dialogueBox); // Draw the dialogue box
            window.draw(dialogueText); // Draw the dialogue text
        }

        window.display();
    }

    return 0;
}



