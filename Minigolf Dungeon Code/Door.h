#pragma once
#include "Wall.h"
class Door :
	public Wall
{
public:

	Door(int iXPos, int iYPos);
	bool Collide(Player& ball, Time totalTime, Time dt);
	SoundManager* m_SM = SoundManager::getInstance();
};

