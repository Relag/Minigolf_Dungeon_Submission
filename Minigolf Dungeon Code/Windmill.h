#ifndef WINDMILL_H
#define WINDMILL_H
#include "Entity.h"
#include "SoundManager.h"
#include "Player.h"
#include "Wall.h"

using namespace sf;

class Windmill : public Wall
{
public:
	Windmill();
	Windmill(int iPosX, int iPosY);

	Sprite Animate();
	int time = 0;
	bool Collide(Player& ball, Time totalTime, Time dt);
	IntRect rectSourceSprite;

	SoundManager* m_SM = SoundManager::getInstance();


	void Delete();

protected:

	bool SpriteUp;
	Sprite m_Sprite1;
	Sprite m_Sprite2;
	Texture tWindmill;
	FloatRect WindmillRect;
	int iPosX;
	int iPosY;

};

#endif
