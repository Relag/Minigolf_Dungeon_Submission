#include "Gopher.h"
#include "TextureHolder.h"

Gopher::Gopher(int iXPos, int iYPos, MovementType eTypeP, int speed) {

	//Set the Gopher's Position on the Map
	fCentre.x = iXPos;
	fCentre.y = iYPos;

	//Set the Gopher's Collision Box (for Wall Detection)
	fTop.x = fCentre.x;
	fTop.y = fCentre.y - 20;
	fBottom.x = fCentre.x;
	fBottom.y = fCentre.y + 20;
	fRight.x = fCentre.x + 20;
	fRight.y = fCentre.y;
	fLeft.x = fCentre.x - 20;
	fLeft.y = fCentre.y;
	
	//Set the Gopher's Sprite
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/gopher_sprite.png"));

	m_Sprite.setPosition(fCentre);

	//Set the Gopher's Speed and Orientation
	iSpeedX = 0;
	iSpeedY = 0;

	switch (eTypeP)
	{
	case Updown:
		iSpeedY = speed;
		break;
	case LeftRight:
		iSpeedX = speed;
		break;
	default:
		break;
	}




}

void Gopher::Move(Player Ball ,Time dt, Window& window) {

	
	if (HitTimer <= 0) {

		//Set the Gopher's Sprite to the Default while Moving
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/gopher_sprite.png"));

		//Move the Gopher
		fCentre.x += iSpeedX * dt.asSeconds();
		fCentre.y += iSpeedY * dt.asSeconds();

		//Reset it's Position for Collision
		fTop.x = fCentre.x;
		fTop.y = fCentre.y - 5;
		fBottom.x = fCentre.x;
		fBottom.y = fCentre.y + 20;
		fRight.x = fCentre.x - 5;
		fRight.y = fCentre.y;
		fLeft.x = fCentre.x + 20;
		fLeft.y = fCentre.y;
	}

	//Get if the Ball is Moving or Not
	bool B = Ball.GetSpeed().x == 0 && Ball.GetSpeed().y == 0;

	// Start Gopher Ball is Moving
	if (HitTimer > 0)
	{
		//Set Gopher's sprite to be in the hole.
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/gopher_hole.png"));

		if (!B)
		{
			HitTimer -= 1 * dt.asSeconds();
		}

	}

	m_Sprite.setPosition(fCentre);
}

void Gopher::Hit()
{
	// Flip the Gophers Movement
	iSpeedX = -iSpeedX;
	iSpeedY = -iSpeedY;
}

FloatRect Gopher::GetPosition()
{
	//Return the Floatrect of the Gopher
	FloatRect Position;
	Position.left = m_Sprite.getGlobalBounds().left;
	Position.top = m_Sprite.getGlobalBounds().top;

	return Position;
}

FloatRect Gopher::GopherRect() {

	FloatRect Powerup;
	Powerup.height = 20;
	Powerup.width = 20;
	Powerup.top = fCentre.y - 10;
	Powerup.left = fCentre.x - 10;
	return Powerup;

}

bool Gopher::Collide(Player& ball, Time totalTime, Time dt)
{

	int getballspeed = ball.GetSpeed().x;
	int getballspeed2 = ball.GetSpeed().y;


	if (!(HitTimer > 0)) {

		//Checks if the ball has the Shield Powerup
		if (!ball.GetShield()) {

			//If Gopher Collides with the ball from the top
			if (GopherRect().contains(ball.GetTop()) || GopherRect().contains(ball.GetBottom()))
			{
				ball.LosePoints();
				HitTimer = 1000;
				m_SM->playGopherHit();

			}

			//If Gopher Collides with the ball from the top
			if (GopherRect().contains(ball.GetLeft()) || GopherRect().contains(ball.GetRight()))
			{
				ball.LosePoints();
				HitTimer = 1000;
				m_SM->playGopherHit();
			}
		}
		else 
		{
			//Gopher hit with Shield
			HitTimer = 1000;
			ball.UseShield();
		}
	}


	return false;
}

void Gopher::CheckCollisionTile(FloatRect tile, int size)
{
	//Detects if a given wall intersects with the Gopher
	//Adjusts the x and y speeds accordingly.
	//Make sure you use ObtainKey and ObtainPowerup
	//This ensures that the particle system is created.
	tile.height = size;
	tile.width = size;

	//Check the Gopher's Collision with the Wall
	bool bTopCol = tile.contains(fTop) || tile.contains(fBottom);
	bool bSideCol = tile.contains(fRight) || tile.contains(fLeft);

	if (bTopCol)
	{
		iSpeedY = -iSpeedY;
	}

	if (bSideCol)
	{
		iSpeedX = -iSpeedX;
	}

}
