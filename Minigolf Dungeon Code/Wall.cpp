#include "Wall.h"
#include "TextureHolder.h"

Wall::Wall() {}

Wall::Wall(int iXPos, int iYPos, string sSpriteName)
{ 
	// Constructor for the Wall
	sSprite = sSpriteName;
	fCentre.x = iXPos;
	fCentre.y = iYPos;

	m_Sprite.setPosition(fCentre);
}

Wall::~Wall(){}


void Wall::Update() {


}


FloatRect Wall::wallRect()
{
	FloatRect Wall;
	Wall.height = 40;
	Wall.width = 40;
	Wall.top = fCentre.y-5;
	Wall.left = fCentre.x-5;
	return Wall;
}


