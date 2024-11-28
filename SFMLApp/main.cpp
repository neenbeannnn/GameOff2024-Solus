#include "TileMap.h"
#include "Game.h"
#include "DialogueBox.h"
#include "Collisions.h"
#include "Map.h"
#include "MapManager.h"
#include "Animations.h"
#include "CatSprite.h"
#include <iostream>

int main()
{
    Game game;
    sf::Texture catTexture, catTextureLeft, catTextureRight, catTextureForward, catTextureBackward;
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
    mapManager->addMap(MapName::APARTMENT_FIRST_FLOOR, apartmentFirstFloorMap);
    mapManager->addMap(MapName::APARTMENT_LEFT_ROOM, apartmentLeftRoomMap);
    mapManager->addMap(MapName::APARTMENT_SECOND_FLOOR, apartmentSecondFloorMap);
    mapManager->addMap(MapName::APARTMENT_BATHROOM, apartmentBathroomMap);
    
    mapManager->getCurrentMap()->load();
    
    //Create Cat Sprite
    CatSprite* catSprite = new CatSprite();
    catTexture.loadFromFile("sprites/CatSprite_Sitting.png");
    auto animation = std::make_shared<Animations>(catTexture, sf::Vector2u(4, 4), 0.4f);
    
    catTextureLeft.loadFromFile("sprites/CatSprite_Left.png");
    auto animationLeft = std::make_shared<Animations>(catTextureLeft, sf::Vector2u(7, 7), 0.4f);

    catTextureRight.loadFromFile("sprites/CatSprite_Right.png");
    auto animationRight = std::make_shared<Animations>(catTextureRight, sf::Vector2u(7, 7), 0.4f);

    catTextureForward.loadFromFile("sprites/CatSprite_Forward.png");
    auto animationForward = std::make_shared<Animations>(catTextureForward, sf::Vector2u(6, 6), 0.4f);

    catTextureBackward.loadFromFile("sprites/CatSprite_Backward.png");
    auto animationBackward = std::make_shared<Animations>(catTextureBackward, sf::Vector2u(5, 5), 0.4f);

    //Add animations into Cat Sprite
    catSprite->addAnimation(CatAnimation::CAT_SITTING, animation);
    catSprite->addAnimation(CatAnimation::CAT_LEFT, animationLeft);
    catSprite->addAnimation(CatAnimation::CAT_RIGHT, animationRight);
    catSprite->addAnimation(CatAnimation::CAT_FORWARD, animationForward);
    catSprite->addAnimation(CatAnimation::CAT_BACKWARD, animationBackward);

    /*texture.loadFromFile("gato.png", sf::IntRect(0, 0, 32, 32));*/
    sf::Sprite sprite(catTexture);
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

    const float movementSpeed = 0.1f; // Movement speed

    sf::Clock clock; //For the Animations
    sf::Clock idleClock; //Clock to track time idel
    sf::Time idleThreshold = sf::seconds(0.5); //2 second threshold
    bool isIdle = false;

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                catSprite->switchToAnimation(CatAnimation::CAT_LEFT);
                movement.x -= movementSpeed;
                sprite.setTexture(catTextureLeft);
                isIdle = false;
                idleClock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                catSprite->switchToAnimation(CatAnimation::CAT_RIGHT);
                movement.x += movementSpeed;
                sprite.setTexture(catTextureRight);
                isIdle = false;
                idleClock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                catSprite->switchToAnimation(CatAnimation::CAT_BACKWARD);
                movement.y -= movementSpeed;
                sprite.setTexture(catTextureBackward);
                isIdle = false;
                idleClock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                catSprite->switchToAnimation(CatAnimation::CAT_FORWARD);
                movement.y += movementSpeed;
                sprite.setTexture(catTextureForward);
                isIdle = false;
                idleClock.restart();
            }
            else {
                //If no movement keys are pressed, go back to idle position
                if (idleClock.getElapsedTime() > idleThreshold && !isIdle) {
                    catSprite->switchToAnimation(CatAnimation::CAT_SITTING);
                    sprite.setTexture(catTexture);
                    isIdle = true;
                }
            }

            sf::Vector2f newPosition = sprite.getPosition() + movement;

            if (mapManager->getCurrentMap()->handleCollision(newPosition, movement)) {
                sprite.move(movement);
            }

            sf::RectangleShape debugCollisionBox(sf::Vector2f(32, 32));
            debugCollisionBox.setPosition(newPosition.x, newPosition.y);
            debugCollisionBox.setFillColor(sf::Color(255, 0, 0, 100)); // Semi-transparent red
            //window.draw(debugCollisionBox);
        }

        float deltaTime = clock.restart().asSeconds();

        animation->update(0, deltaTime);
        sprite.setTextureRect(animation->getUVRect());
        sprite.setScale(4.0f, 4.0f);

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

        mapManager->getCurrentMap()->draw(window);

        if (showDialogue) {
            dialogueBox.draw(window); // Draw the dialogue box
        }
        
        window.draw(sprite);
        window.display();
    }

    return 0;
}
