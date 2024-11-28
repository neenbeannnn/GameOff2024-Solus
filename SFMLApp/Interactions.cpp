#pragma once
#include "Interactions.h";
#include "Player.h"
#include "NPC.h"
void Interactions::createInteractable(NPC& npc)
{
	/*
	 Get the tilemap, and iterate through it
	 if a tile is the same number as the 
	 tile that should be interactable
	 use turnIntoInteractable

	 get height of map
	 get width of map
	 double for loop to iterate through each tile
	 if tile matches number in enum, use turnIntoInteractable
	 for now... im going to just go through the window.
	*/
	interactableNPCS.emplace_back(&npc);
}
void Interactions::turnIntoInteractable(const Interactable& tile, sf::Vector2f position)
{
	//tile at pos will be placed in a vector
	//called "interactableTiles"
	//using emplace_back since it creates the object and
	//inserts it into vector at the same time
	//this vector will be used later to see what
	//objects at what positions
	
}

bool Interactions::checkProximity(const Player& player) 
{
	/*
	 get position/bounds of player character
	 get bounds of the tile/position of tile
	 check if the bounds of the player character
	 and the tile are touching, maybe with
	 .intersects, return true if so
	*/
	sf::FloatRect playerBounds = player.getBoundBox();
	sf::FloatRect expandedBounds = playerBounds;
	expandedBounds.width += 1.5 * defaultTiles.x;
	expandedBounds.height += 1.5 * defaultTiles.y;
	expandedBounds.left -= defaultTiles.x;
	expandedBounds.top -= defaultTiles.y;
	/*cout << "Player Bounds: " << playerBounds.left << ", " << playerBounds.top
		<< ", " << playerBounds.width << ", " << playerBounds.height << endl;
	cout << "Expanded Bounds: " << expandedBounds.left << ", " << expandedBounds.top
		<< ", " << expandedBounds.width << ", " << expandedBounds.height << endl;*/

	for (const auto& interNPC : interactableNPCS) 
	{
		sf::FloatRect npcBounds = interNPC->getBoundBox();
		/*cout << "NPC Bounds: " << npcBounds.left << ", " << npcBounds.top
			<< ", " << npcBounds.width << ", " << npcBounds.height << endl;*/
		if (expandedBounds.intersects(npcBounds))
		{
			interNPC->interactPrompt();
			return true;
		}
		else 
		{
			interNPC->togglePrompt();
		}
	}
	return false;
}
