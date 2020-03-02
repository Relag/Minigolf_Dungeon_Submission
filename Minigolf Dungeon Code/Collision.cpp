#include "Player.h"
//.cpp for all Player collision functions.

//Checks if any collision occured. Flags collision point for use in HandleCollisions()
void Player::CheckCollision(FloatRect tile, Time dt, Time GametimeTotal, int type)
{
	//Detects if a given wall intersects with the ball
	//Adjusts the x and y speeds accordingly.
  	tile.height = 40;
	tile.width = 40;
	
	//Check the Top and Bottom of the Wall
	if (tile.contains(fTop) && fSpeed.y < 0)
	{
		bTopHitbox = true;
		iCollideTypeCardinal = type;
	}
	
	if (tile.contains(fBottom) && fSpeed.y > 0)
	{
		bBottomHitbox = true;
		iCollideTypeCardinal = type;
	}

	//Check the Right and the Left of the Wall
	if (tile.contains(fRight) && fSpeed.x > 0)
	{
		bRightHitbox = true;
		iCollideTypeCardinal = type;
	}

	if (tile.contains(fLeft) && fSpeed.x < 0)
	{
		bLeftHitbox = true;
		iCollideTypeCardinal = type;
	}

	//Check the Top Left and Bottom Right of the Ball
	if (tile.contains(fTopLeft))
	{
		bTopLeftHitbox = true;
		iCollideTypeDiagonal = type;
	}

	if (tile.contains(fBottomRight))
	{
		bBottomRightHitbox = true;
		iCollideTypeDiagonal = type;
	}
	//Checks the Top Right and Bottom Left of the Ball
	if (tile.contains(fTopRight))
	{
		bTopRightHitbox = true;
		iCollideTypeDiagonal = type;
	}
	if (tile.contains(fBottomLeft) && !tile.contains(fBottom) && !tile.contains(fLeft))
	{
		bBottomLeftHitbox = true;
		iCollideTypeDiagonal = type;
	}
}

//Checks collision flags to see if a collision has occurred
//Then calls the function to hit wall or stickywall based on collide type.
void Player::HandleCollision(Time GametimeTotal)
{
	if (iCollideTypeCardinal == 9 || iCollideTypeDiagonal == 9)
	{
		HitStickyWall();
		ResetCollideTime(GametimeTotal);
		iCollideTypeCardinal = 0;
		iCollideTypeDiagonal = 0;
	}
	else if (iCollideTypeDiagonal != 0 || iCollideTypeCardinal != 0)
	{
		HitWall();
		ResetCollideTime(GametimeTotal);
		iCollideTypeCardinal = 0;
		iCollideTypeDiagonal = 0;
	}
 	
	ResetHitboxFlags();
}

void Player::ResetHitboxFlags()
{
	bTopHitbox = false;
	bTopLeftHitbox = false;
	bTopRightHitbox = false;
	bLeftHitbox = false;
	bRightHitbox = false;
	bBottomLeftHitbox = false;
	bBottomRightHitbox = false;
	bBottomHitbox = false;
}

void Player::HitWall()
{
	if (iCollideTypeCardinal != 0)
	{
		if (bTopHitbox || bBottomHitbox)
			fSpeed.y = -fSpeed.y / 1.1;
		if (bLeftHitbox || bRightHitbox)
			fSpeed.x = -fSpeed.x / 1.1;
	}
	//Only process diagonals if cardinal directions have no collisions
	else
	{
		if (bTopLeftHitbox || bBottomRightHitbox)
		{
			float fTemp = -fSpeed.x;
			fSpeed.x = -fSpeed.y;
			fSpeed.y = fTemp;
		}
		else if (bTopRightHitbox || bBottomLeftHitbox)
		{
			float fTemp = fSpeed.x;
			fSpeed.x = fSpeed.y;
			fSpeed.y = fTemp;
		}
	}
	m_SM->playWallKnock();
}

void Player::HitStickyWall()
{
	if (!bHasShield) 
	{
		if (fSpeed.y != 0 && fSpeed.x != 0)
		{
			fSpeed.y = -fSpeed.y / fSpeed.y;
			fSpeed.x = -fSpeed.x / fSpeed.x;
			m_SM->playStickyWall();
		}
	}
	else 
	{
		HitWall();
		bHasShield = false;
	}
}

