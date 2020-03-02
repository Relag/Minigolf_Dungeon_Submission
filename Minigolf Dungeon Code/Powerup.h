#ifndef POWERUP_H
#define POWERUP_H
#include "Entity.h"
#include "SoundManager.h"
enum ePickupType
{
	Shield, Bomb, Coin, Key
};

class Powerup : public Entity
{
public:
	Powerup();
	Powerup(int iXPos, int iYPox, string sPickupType, ePickupType eTypeP);
	int ActivatePowerup();
	Sprite GetSprite() { return m_Sprite; }
	string getName();
	FloatRect PowerupRect();
	SoundManager* m_SM = SoundManager::getInstance();

protected:
	string sPickupType;
	Vector2f fCentre;
	ePickupType eType;
	Sprite m_Sprite;
};

#endif