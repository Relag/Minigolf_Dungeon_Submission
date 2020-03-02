#include "Door.h"

Door::Door(int iXPos, int iYPos)
{
	// Set Door's Position
	fCentre.x = iXPos;
	fCentre.y = iYPos;

	// Set Door's Sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/door.png"));

	m_Sprite.setPosition(fCentre);
	
}

bool Door::Collide(Player& ball, Time totalTime, Time dt)
{
	//Check time ellapsed since last collision.
	if (ball.Collide(totalTime))
	{
		if (wallRect().contains(ball.GetTop()) || wallRect().contains(ball.GetBottom()))
		{
			//Check to see if the ball has the key.
			//If so, destroy the block, else reverse ball speed.
			if (ball.GetKey()) {
				m_SM->playOpenDoor();
				delete this;
				ball.UseKey();
				ball.ResetCollideTime(totalTime);
				return true;
			}
			else if (ball.Collide(totalTime))
			{
				ball.Speed(1, -1);
				m_SM->playWallKnock();
				ball.ResetCollideTime(totalTime);
				return false;
			}
		}

		if (wallRect().contains(ball.GetLeft()) || wallRect().contains(ball.GetRight()))
		{
			//Check to see if the ball has the key.
			//If so, destroy the block, else reverse ball speed.
			if (ball.GetKey()) {
				m_SM->playOpenDoor();
				delete this;
				ball.UseKey();
				ball.ResetCollideTime(totalTime);
				return true;
			}
			else if(ball.Collide(totalTime))
			{
				ball.Speed(-1, 1);
				m_SM->playWallKnock();
				ball.ResetCollideTime(totalTime);
				return false;
			}
		}
	}
}
