#pragma once
#include "Player.h"
#include "NPC.h"

class HelperFunctions
{
public:
	static bool isInteractingWithNPC(const Player& player, const NPC& npc);
};

