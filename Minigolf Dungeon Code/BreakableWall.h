#pragma once
#include "Wall.h"

class BreakableWall :
	public Wall
{
public:
	BreakableWall(int iXPos, int iYPos);
	bool Collide(Player& ball, Time totalTime, Time dt) ;
	SoundManager* m_SM = SoundManager::getInstance();
};

