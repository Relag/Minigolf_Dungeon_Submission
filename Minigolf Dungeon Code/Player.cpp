#include "Player.h"
#include <math.h>

Player::Player(int iX, int iY, string sSprite)
{
	
}

Player::Player()
{
	//Set the Player's Sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/ball_sprite.png"));

	//Set the Player's Position
	m_Position.x = 500;
	m_Position.y = 500;
	iRadius = m_Sprite.getLocalBounds().width / 2;
	fDiagonal = iRadius * 0.707;
	m_Sprite.setPosition(m_Position);

	//Particle Systems for the Player
	m_KeyParticleSystem1.init(20);
	m_KeyParticleSystem2.init(20);
	m_KeyParticleSystem3.init(20);

	m_PowerupParticleSystem1.init(20);
	m_PowerupParticleSystem2.init(20);
	m_PowerupParticleSystem3.init(20);

	//Set Player's Default State
	bHasKey = false;
	bHasBomb = false;
	bHasShield = false;
	bShooting = false;
	bGoingUp = true;
	bAiming = false;
	ResetHitboxFlags();

	m_LastCollide = Time::Zero;

	powerBar.setFillColor(Color::Red);
	
}

void Player::Speed(float x, float y) {

	// Change the Player's Speed
	fSpeed.y = fSpeed.y * y;
	fSpeed.x = fSpeed.x * x;

}

void Player::Spawn(Vector2f startPoint)
{
	//Set the Balls Spawn Position
	m_Position.x = startPoint.x;
	m_Position.y = startPoint.y;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

	iShotCounter = 0;

	//Set the Balls Boundries
	fTop.x = m_Position.x;
	fTop.y = m_Position.y - iRadius;

	fBottom.x = m_Position.x;
	fBottom.y = m_Position.y + iRadius;

	fRight.x = m_Position.x + iRadius;
	fRight.y = m_Position.y;

	fLeft.x = m_Position.x - iRadius;
	fLeft.y = m_Position.y;

	fTopLeft.x = m_Position.x - fDiagonal;
	fTopLeft.y = m_Position.y - fDiagonal;

	fTopRight.x = m_Position.x + fDiagonal;
	fTopRight.y = m_Position.y - fDiagonal;

	fBottomRight.x = m_Position.x + fDiagonal;
	fBottomRight.y = m_Position.y + fDiagonal;

	fBottomLeft.x = m_Position.x - fDiagonal;
	fBottomLeft.y = m_Position.y + fDiagonal;
}


void Player::Destroy()
{

}

int Player::GetScore()
{
	return iScore;
}

void Player::Move(float power)
{
	//power parameter currently does nothing. May need it if an outside force acts on the ball
	//Windmill, Gofer, etc.

	if (power > 20)
		iShotCounter++;
	//std::cout << fPower << ", " << fRotation << endl;
	//Convert radians to degrees, multiply by fPower for speed. cos(answer) for x, sin(answer) for y.
	fSpeed.x = cos(fRotation* 3.14159 / 180) * fPower;
	fSpeed.y = sin(fRotation* 3.14159 / 180) * fPower;
	//Reset varibles related to bShooting
	bGoingUp = true;
	bShooting = false;
	bAiming = false;
	fPower = 0;
	fBarFill = 0;
	/*Possibly where the shotcounter will be*/
	
}



void Player::RotateLeft(float dt) 
{
	fRotation -= 100 * dt;
	if (fRotation < 0)
		fRotation = fRotation + 360;
}

void Player::RotateRight(float dt) 
{
	fRotation += 100 * dt;
	if (fRotation > 360)
		fRotation = fRotation - 360;
}

Time Player::GetLastHitTime()
{
	return m_LastCollide;
}

bool Player::Collide(Time timeCollide)
{//Function always returns false. Debugger shows that the statement is true though.
	//Further testing needed.

	if (timeCollide.asMilliseconds() >= m_LastCollide.asMilliseconds() + 50) {
		
		return true;
	}
	else {
		return false;
	}
}

void Player::Update(Time dt, Window& window)
{	
	
		KeyParticles(dt.asSeconds());

		PowerUpParticles(dt.asSeconds());

	//Ensure the ball is stopped before handling inputs
	if (fSpeed.x == 0 && fSpeed.y == 0)
	{
		powerBar.setSize(Vector2f(powerBarWidth, powerBarHeight));
		//If currently shooting (powerbar is moving) then call that function.
		if (bShooting)
		{
			powerBarOutline[7] = Vector2f(getCentre().x - powerBarStartWidth / 2 + fBarFill / 3, getCentre().y + 30 + powerBarHeight);
			powerBarOutline[8] = Vector2f(getCentre().x - powerBarStartWidth / 2 + fBarFill / 3, getCentre().y + 30);
			Shooting(dt.asSeconds(), window);
		}
		else
		{
			//Otherwise handle inputs.
			powerBar.setPosition(getCentre().x - 40, getCentre().y + 30);
			powerBar.setSize(Vector2f(powerBarStartWidth, powerBarHeight));
			HandleInput(dt.asSeconds(), window);
		}
	}
	else
	{
		m_Position.x += fSpeed.x * dt.asSeconds();
		m_Position.y += fSpeed.y * dt.asSeconds();

		//When the ball drops below a certain speed it stops
		if ((fSpeed.x < 15 && fSpeed.y < 15) && (fSpeed.x > -15 && fSpeed.y > -15))
		{
			fSpeed.x = 0;
			fSpeed.y = 0;
		}
		
		//Clear any key presses made at illegal times.
		//Prevents Shooting() from repeating constantly.
		Event event;
		while (window.pollEvent(event));
		
		dtAsSeconds += dt.asMilliseconds();
		//Get the absolute value of speed, the slower the ball is the more it slows down.
		if (dtAsSeconds > 100) {
			if (fabs(fSpeed.x) + fabs(fSpeed.y) > 50)
			{
				fSpeed.y = fSpeed.y * 0.97;
				fSpeed.x = fSpeed.x * 0.97;
			}
			else {
				fSpeed.y = fSpeed.y * 0.92;
				fSpeed.x = fSpeed.x * 0.92;
			}
			dtAsSeconds = 0;
		}

		//Update the eight outer points for collision testing.
		fTop.x = m_Position.x;
		fTop.y = m_Position.y - iRadius;

		fBottom.x = m_Position.x;
		fBottom.y = m_Position.y + iRadius;

		fRight.x = m_Position.x + iRadius;
		fRight.y = m_Position.y;

		fLeft.x = m_Position.x - iRadius;
		fLeft.y = m_Position.y;

		fTopLeft.x = m_Position.x - fDiagonal;
		fTopLeft.y = m_Position.y - fDiagonal;

		fTopRight.x = m_Position.x + fDiagonal;
		fTopRight.y = m_Position.y - fDiagonal;

		fBottomRight.x = m_Position.x + fDiagonal;
		fBottomRight.y = m_Position.y + fDiagonal;

		fBottomLeft.x = m_Position.x - fDiagonal;
		fBottomLeft.y = m_Position.y + fDiagonal;

		m_Sprite.setPosition(m_Position);

	}
}

void Player::Shooting(float dt, Window &window)
{
	Event event;
	//Going up determines whether the power bar is moving up or down.
	//If the power reaches its max (250) the bar travels down.
	if (bGoingUp)
	{
		if (fBarFill < 240)
			fBarFill += (200 * dt);
		else
			bGoingUp = false;
	}
	else
	{
		if (fBarFill > -1)
			fBarFill -= (200 * dt);
		else
		{
			//If the bar goes back to 0, the ball travels with a poor force,
			//penalizing the player.
			//Shot accuracy is set to -25.
			fBarFill = 0;
			fRotation += -21;
			Move(fPower);
		}
	}
	//Power bar fill ration is tied to fPower
	//Only fill bar when not aiming.
	if (!bAiming)
		powerBarWidth = fBarFill / 3;
	

	while (window.pollEvent(event));											
	{
		if (event.type == Event::KeyReleased)
		{
			//If space is pressed a second time the ball shoots
			//bAiming is set to true
			if (event.key.code == Keyboard::Space && !bAiming)
			{
				fPower = fBarFill;
				bAiming = true;
			}
			//if in Aiming mode register the spacebar click for accuracy.
			else if (event.key.code == Keyboard::Space && bAiming)
			{
				//Maximum inaccuracy is 25 degrees.
				if (fBarFill > 48)
					fRotation += 24;
				else// if (fBarFill < )
					fRotation += fBarFill - 24;
				Move(fPower);
			}
		}
	}
	dtAsSeconds = 0;
}

string Player::getPowerUpName()
{
	string powerups;

	if (bHasBomb)
	{
		powerups += "[WallBreaker]";
	}

	if (bHasKey)
	{
		powerups += "[Key]";
	}

	if (bHasShield)
	{
		powerups += "[Shield]";
	}

	return powerups;
}

Vector2f Player::getCentre()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}

void Player::HandleInput(float dt, Window &window)
{
	Event event;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		RotateLeft(dt);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		RotateRight(dt);
	}
	
	while (window.pollEvent(event));
	{
		if (event.type == Event::KeyReleased)
		{
			if (event.key.code == Keyboard::Space)
			{
				if (!bShooting)
				{
     					bShooting = true;
						//cout << "Shooting";
					                       
				}
			}
		}
	}

	//The direction the player is aiming while in handleInput
	//Draws a red line between the player, and their direction.
	direction.setPrimitiveType(LinesStrip);
	direction.resize(2);
	direction[0] = Vector2f(getCentre());
	direction[1] = Vector2f(getCentre().x + cos(fRotation* 3.14159 / 180) * 100,
		getCentre().y + sin(fRotation * 3.14159 / 180) * 100);
	
	direction[0].color = Color::Red;
	direction[1].color = Color::Red;
	
	powerBarOutline.setPrimitiveType(LineStrip);
	powerBarOutline.resize(9);

	//The outline of the power bar. Shows the maximum fill amount and desired fill for aiming. 
	powerBarOutline[0] = Vector2f(getCentre().x - powerBarStartWidth / 2, getCentre().y + 30);
	powerBarOutline[1] = Vector2f(getCentre().x + powerBarStartWidth / 2, getCentre().y + 30);
	powerBarOutline[2] = Vector2f(getCentre().x + powerBarStartWidth / 2, getCentre().y + 30 + powerBarHeight);
	powerBarOutline[3] = Vector2f(getCentre().x - powerBarStartWidth / 2, getCentre().y + 30 + powerBarHeight);
	powerBarOutline[4] = Vector2f(getCentre().x - powerBarStartWidth / 2, getCentre().y + 30);
	powerBarOutline[5] = Vector2f(getCentre().x - powerBarStartWidth / 2 + 8, getCentre().y + 30);
	powerBarOutline[6] = Vector2f(getCentre().x - powerBarStartWidth / 2 + 8, getCentre().y + 30 + powerBarHeight);
	powerBarOutline[7] = Vector2f(getCentre().x - powerBarStartWidth / 2, getCentre().y + 30 + powerBarHeight);
	powerBarOutline[8] = Vector2f(getCentre().x - powerBarStartWidth / 2, getCentre().y + 30);

	powerBarOutline[0].color = Color::Black;
	powerBarOutline[1].color = Color::Black;
	powerBarOutline[2].color = Color::Black;
	powerBarOutline[3].color = Color::Black;
	powerBarOutline[4].color = Color::Black;
}

FloatRect Player::GetPosition() {

	FloatRect Position;
	Position.left = m_Sprite.getGlobalBounds().left;
	Position.top = m_Sprite.getGlobalBounds().top;

	return Position;
}
