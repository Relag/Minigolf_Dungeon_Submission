#include "Windmill.h"
#include "TextureHolder.h"

Windmill::Windmill(int iPosX, int iPosY)
{

	//Constructor for the Wall
	fCentre.x = iPosX;
	fCentre.y = iPosY;

	// Set both states of the windmill
	m_Sprite1 = Sprite(TextureHolder::GetTexture(
		"graphics/WM_1.png"));
	m_Sprite2 = Sprite(TextureHolder::GetTexture(
		"graphics/WM_2.png"));

	m_Sprite1.setPosition(fCentre);
	m_Sprite2.setPosition(fCentre);

}

Windmill::Windmill()
{/*Empty*/}

Sprite Windmill::Animate()
{
	time++;

	if (time > 180) {
		SpriteUp = !SpriteUp;
		time = 0;
	}

	if (SpriteUp)
	{
		return m_Sprite1;
	}
	else 
	{
		return m_Sprite2;
	}
}


bool Windmill::Collide(Player& ball, Time totalTime, Time dt)
{

		//If windmill Collides with the ball from the top
		if (wallRect().contains(ball.GetTop()) || wallRect().contains(ball.GetBottom()))
		{
			//Knock back and speed up the ball
			ball.Speed(1.0, -1.0);
			m_SM->playWallKnock();
			ball.ResetCollideTime(totalTime);
			return true;

		}

		//If windmill Collides with the ball from the top
		if (wallRect().contains(ball.GetLeft()) || wallRect().contains(ball.GetRight()))
		{
			//Knock back and speed up the ball
			ball.Speed(-1.0, 1.0);
			m_SM->playWallKnock();
			ball.ResetCollideTime(totalTime);
			return true;

		}

		return false;
	
}

