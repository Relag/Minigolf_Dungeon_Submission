#include "Powerup.h"
#include "TextureHolder.h"

Powerup::Powerup(int iXPos,int iYPos ,string sPickupType,ePickupType eTypeP)
{
	//Constructor for the Wall
	fCentre.x = iXPos;
	fCentre.y = iYPos;

	sSprite = sPickupType;
	eType = eTypeP;

	//Grabs Right Texture for the Specified Wall
	switch (eTypeP)
	{
	case Shield:
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/shield.png"));
		break;
	case Bomb:
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bomb.png"));
		break;
	case Coin:
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/small_coin.png"));
		break;
	case Key:
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/key_sprite.png"));
		break;
	default:
		break;
	}

	m_Sprite.setPosition(fCentre);

}

Powerup::Powerup()
{
	//Delete later?
}

int Powerup::ActivatePowerup()
{
	// Delete the Powerup (Waiting for Check)
	fCentre.x = -1000;
	fCentre.y = -1000;
	m_Sprite.setPosition(fCentre);
	m_SM->playPickupChime();

	switch (eType)
	{
	case Shield:
		return 0;
		break;
	case Bomb:
		return 1;
		break;
	case Coin:
		return 2;
		break;
	case Key:
		return 3;
		break;
	default:
		return 0;
		break;
	}
}

string Powerup::getName()
{
	return sSprite;
}

FloatRect Powerup::PowerupRect()
{
	FloatRect Powerup;
	Powerup.height = 40;
	Powerup.width = 40;
	Powerup.top = fCentre.y - 20;
	Powerup.left = fCentre.x - 20;
	return Powerup;
}