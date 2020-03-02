#ifndef GOPHER_H
#define GOPHER_H
#include "Entity.h"
#include "SoundManager.h"
#include "Player.h"

enum MovementType
{
	Stationary, Updown, LeftRight
};

class Gopher : public Entity
{
public:

	Gopher(int iXPos, int iYPox, MovementType eTypeP, int speed);
	void Move(Player Ball, Time dt, Window& window);
	Sprite GetSprite() { return m_Sprite; }
	FloatRect GopherRect();
	bool Collide(Player& ball, Time totalTime, Time dt);
	void CheckCollisionTile(FloatRect tile, int size);
	void Hit();
	FloatRect GetPosition();

protected:

	SoundManager* m_SM = SoundManager::getInstance();

	Vector2f fCentre;
	MovementType eMove;
	Sprite m_Sprite;

	Vector2f fTop;
	Vector2f fBottom;
	Vector2f fLeft;
	Vector2f fRight;

	int HitTimer = 0;

	int iSpeedX = 0;
	int iSpeedY = 0;


};

#endif

