#include "HelperFunctions.h"
//ignore this idk if it works
bool HelperFunctions::isInteractingWithNPC(const Player& player, const NPC& npc) 
{
	return player.getPosition().x < npc.getPosition().x + 1 &&
		player.getPosition().x + 1 > npc.getPosition().x &&
		player.getPosition().y < npc.getPosition().y + 1 &&
		player.getPosition().y + 1 > npc.getPosition().y;
}
