#include "TileMap.h"
#include "Game.h"
#include "DialogueBox.h"
#include "Collisions.h"
#include "Map.h"
#include "MapManager.h"
#include "Animations.h"
#include <iostream>

int main()
{
    Game game;
    sf::Texture texture;
    sf::View view;
    sf::Event event;

    view.setSize(sf::Vector2f(1000, 800));
    
    const std::vector<int> apartmentFirstFloor =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 6, 7, 60, 60, 60, 60, 60, 60, 60,
        60, 0, 1, 1, 1, 1, 26, 27, 1, 1, 1, 1, 1, 2, 60,
        60, 20, 21, 21, 21, 21, 8, 9, 21, 21, 61, 62, 63, 22, 60,
        60, 40, 41, 41, 41, 41, 8, 9, 41, 41, 41, 41, 41, 42, 60,
        60, 23, 24, 24, 24, 24, 28, 29, 24, 31, 31, 31, 31, 32, 60,
        60, 23, 24, 24, 24, 24, 24, 24, 24, 31, 31, 31, 31, 32, 60,
        60, 23, 24, 24, 24, 24, 24, 13, 44, 16, 31, 31, 31, 32, 60,
        60, 43, 44, 65, 44, 44, 44, 45, 60, 50, 51, 51, 51, 52, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60

    };

    const std::vector<int> apartmentFirstFloorCollisions = 
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    const std::vector<int> apartmentSecondFloor =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  60,
        60, 20, 21, 21, 6,  7,  21, 21, 21, 6,  7,  21, 21, 22, 60,
        60, 40, 41, 41, 26, 27, 41, 41, 41, 26, 17, 41, 41, 42, 60,
        60, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 60,
        60, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 60,
        60, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 60,
        60, 43, 44, 44, 44, 44, 65, 65, 44, 44, 44, 44, 44, 45, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
    };

    const std::vector<int> apartmentSecondFloorCollisions =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    const std::vector<int> apartmentBathroom =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 0,  1,  1,  1,  1,  1,  1,  1,  2,  60, 60, 60, 60, 60,
        60, 20, 64, 21, 21, 21, 21, 21, 21, 22, 60, 60, 60, 60, 60,
        60, 40, 41, 41, 41, 41, 41, 41, 41, 42, 60, 60, 60, 60, 60,
        60, 30, 31, 31, 31, 31, 31, 24, 24, 25, 60, 60, 60, 60, 60,
        60, 30, 31, 31, 31, 31, 31, 24, 24, 25, 60, 60, 60, 60, 60,
        60, 50, 51, 51, 16, 31, 31, 24, 24, 25, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 30, 31, 31, 24, 24, 67, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 50, 51, 51, 44, 44, 45, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
    };

    const std::vector<int> apartmentBathroomCollisions =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    const std::vector<int> apartmentLeftRoom =
    {
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60,  0, 18, 19,  1,  1,  1,  1,  1,  2, 60, 60, 60, 60, 60,
        60, 20, 38, 39, 21, 21, 21, 21, 21, 22, 60, 60, 60, 60, 60,
        60, 40, 58, 59, 41, 41, 41, 41, 41, 42, 60, 60, 60, 60, 60,
        60,  3,  4,  4,  4,  4,  4,  4,  4,  5, 60, 60, 60, 60, 60,
        60, 23, 24, 24, 24, 24, 24, 24, 24, 25, 60, 60, 60, 60, 60,
        60, 66, 24, 24, 24, 24, 24, 24, 24, 25, 60, 60, 60, 60, 60,
        60, 43, 44, 44, 65, 65, 44, 44, 44, 45, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
        60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60
    };

    const std::vector<int> apartmentLeftRoomCollisions =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    const std::vector<int> doorCollisions;
    const std::vector<int> interactableCollisions;

    //Create map manager
    MapManager* mapManager = new MapManager();

    //Create all Map objects
    std::string aptTilsetPath = "tilemaps/APT_TILEMAP.png";
    auto apartmentFirstFloorMap = std::make_shared<Map>(make_pair(370.0f, 1000.0f), aptTilsetPath, 32, 15, 10, apartmentFirstFloor, apartmentFirstFloorCollisions);
    auto apartmentSecondFloorMap = std::make_shared<Map>(make_pair(800.0f, 1000.0f), aptTilsetPath, 32, 15, 10, apartmentSecondFloor, apartmentSecondFloorCollisions);
    auto apartmentBathroomMap = std::make_shared<Map>(make_pair(1130.0f, 900.0f), aptTilsetPath, 32, 15, 10, apartmentBathroom, apartmentBathroomCollisions);
    auto apartmentLeftRoomMap = std::make_shared<Map>(make_pair(600.0f, 870.0f), aptTilsetPath, 32, 15, 10, apartmentLeftRoom, apartmentLeftRoomCollisions);
    
    //Insert all Map objects in MapManager
    std::string apartmentFirstFloorName = "APARTMENT_FIRST_FLOOR";
    std::string apartmentSecondFloorName = "APARTMENT_SECOND_FLOOR";
    std::string apartmentBathroomName = "APARTMENT_BATHROOM";
    std::string apartmentLeftRoomName = "APARTMENT_LEFT_ROOM";
    std::string apartmentRightRoomName = "APARTMENT_RIGHT_ROOM";
    mapManager->addMap(MapName::APARTMENT_FIRST_FLOOR, apartmentFirstFloorMap);
    mapManager->addMap(MapName::APARTMENT_LEFT_ROOM, apartmentLeftRoomMap);
    mapManager->addMap(MapName::APARTMENT_SECOND_FLOOR, apartmentSecondFloorMap);
    mapManager->addMap(MapName::APARTMENT_BATHROOM, apartmentBathroomMap);
    

    //mapManager->switchToMap(MapName::APARTMENT_SECOND_FLOOR);

    mapManager->getCurrentMap()->load();
    
    /*if (!texture.loadFromFile("sprites/CatSprite.png")) {
        std::cerr << "Failed to load texture!" << std::endl;
        return -1;
    }

    Animations animation(texture, sf::Vector2u(4, 4), 0.1f);*/

    texture.loadFromFile("gato.png", sf::IntRect(0, 0, 32, 32));
    sf::Sprite sprite(texture);
    sprite.setScale(4.0f, 4.0f);
    sprite.setPosition(mapManager->getCurrentMap()->getSpawnPoints());

    // Create a rectangle shape to represent the sprite's collision box
    /*sf::RectangleShape collisionBox;
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setOutlineThickness(1.0f);
    collisionBox.setOutlineColor(sf::Color::Green);*/

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

    const float movementSpeed = 0.3f; // Movement speed

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

            sf::Vector2f newPosition = sprite.getPosition() + movement;

            if (mapManager->getCurrentMap()->handleCollision(newPosition, movement)) {
                sprite.move(movement);
            }

            sf::RectangleShape debugCollisionBox(sf::Vector2f(32, 32));
            debugCollisionBox.setPosition(newPosition.x, newPosition.y);
            debugCollisionBox.setFillColor(sf::Color(255, 0, 0, 100)); // Semi-transparent red
            window.draw(debugCollisionBox);
        }

        

        // Update the collision box to match the sprite's global bounds
        /*collisionBox.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
        collisionBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));*/

        view.setCenter(sprite.getPosition());
        window.setView(view);

        // Position the dialogue box at the bottom of the screen
        sf::Vector2f viewCenter = window.getView().getCenter();
        sf::Vector2f viewSize = window.getView().getSize();
        dialogueBox.setPosition(sf::Vector2f(viewCenter.x - dialogueBox.getSize().x / 2, viewCenter.y + viewSize.y / 2 - dialogueBox.getSize().y - 10));

        window.clear();
        /*window.draw(collisionBox);*/ // Draw the collision box

        if (showDialogue) {
            dialogueBox.draw(window); // Draw the dialogue box
        }
        mapManager->getCurrentMap()->draw(window);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
