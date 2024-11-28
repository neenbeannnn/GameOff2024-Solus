#pragma once
#include "Player.h"
#include "NPC.h"
#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class Interactions
{
	enum Interactable
	{
		KEY_TILE, DOOR_TILE, NPC_TILE
		/*
		 insert more items here i guess
		 I also want to know the nums
		 of the tiles so I can
		 assign them to these enums
		*/
	};
public:

	void createInteractable(NPC& npc);
	void turnIntoInteractable(const Interactable& tile, sf::Vector2f pos);
	//void turnIntoInteractableOL(const NPC& npc, sf::Vector2f pos);
	bool checkProximity(const Player& player);


private:
	std::vector<NPC*> interactableNPCS;
	sf::Vector2u defaultTiles = { 32, 32 }; 
};