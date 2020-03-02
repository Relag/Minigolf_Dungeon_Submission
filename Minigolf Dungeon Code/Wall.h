#ifndef WALL_H
#define WALL_H
#include "Entity.h"
#include "Player.h"
#include "TextureHolder.h"
#include <list>

using namespace sf;

class Wall : public Entity
{
public:
	Wall();
	Wall(int iXPos, int iYPos, string sSpriteName);
	~Wall();
	//void OpenDoor(bool bHasKey);
	Sprite GetSprite() { return m_Sprite; }
	FloatRect wallRect();
	Time lastCollideTime;
	void Update();
	virtual bool Collide(Player& ball, Time totalTime, Time dt) = 0;
	
protected:

	Sprite m_Sprite;
	Vector2f fCentre;

private:
	//void Destroy();
};

#endif