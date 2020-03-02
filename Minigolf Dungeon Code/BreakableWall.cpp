#include "BreakableWall.h"

BreakableWall::BreakableWall(int iXPos, int iYPos)
{
	// Set Walls Position
	fCentre.x = iXPos;
	fCentre.y = iYPos;

	// Set the Walls Spirte
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/weak_wall.png"));
	lastCollideTime = Time::Zero;
	m_Sprite.setPosition(fCentre);
}

bool BreakableWall::Collide(Player &ball, Time totalTime, Time dt)
{
	
	//Check time ellapsed since last collision.
	if (ball.Collide(totalTime))
	{
		if (wallRect().contains(ball.GetTop()) || wallRect().contains(ball.GetBottom()))
		{
			//Check to see if the ball has the powerup.
			//If so, destroy the block, else reverse ball speed.
			if (ball.GetBomb()) {
				m_SM->playBreakWall();
				delete this;
				ball.UsePowerup();
				ball.ResetCollideTime(totalTime);
				return true;
			}
			else if(ball.Collide(totalTime))
			{
				ball.Speed(1, -1);
				m_SM->playWallKnock();
				ball.ResetCollideTime(totalTime);
				return false;
			}
		}

		if (wallRect().contains(ball.GetLeft()) || wallRect().contains(ball.GetRight()))
		{
			//Check to see if the ball has the powerup.
			//If so, destroy the block, else reverse ball speed.
			if (ball.GetBomb()) {
				m_SM->playBreakWall();
				delete this;
				ball.UsePowerup();
				ball.ResetCollideTime(totalTime);
				return true;
			}
			else if (ball.Collide(totalTime))
			{
				ball.Speed(-1, 1);
				m_SM->playWallKnock();
				ball.ResetCollideTime(totalTime);
				return false;
			}
		}
	}
}
