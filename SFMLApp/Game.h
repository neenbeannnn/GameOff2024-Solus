#pragma once
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "DialogueBox.h"
#include "Player.h"
#include "Movement.h"

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
    void initWindow();
    void initView();
    void initTileMap();
    void initPlayer();
    void initDialogueBox();

    sf::RenderWindow window;
    sf::View view;
    TileMap map;
    Player player;
    Movement movement;
    DialogueBox dialogueBox; // Use a member variable for the dialogue box
    bool showDialogue;
};

