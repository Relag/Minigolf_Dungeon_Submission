#include "Player.h"

//Important! Ensure that you call the below functions when the ball collides with the object.
//These functions will automatically set the bool to true, and activate the particle effects.

void Player::ObtainKey()
{
	bHasKey = true;
	m_KeyParticleSystem1.emitParticles(getCentre(), fSpeed, Color::Red);
	m_KeyParticleSystem2.emitParticles(getCentre(), fSpeed, Color::Red);
	m_KeyParticleSystem3.emitParticles(getCentre(), fSpeed, Color::Red);
	fKeyParticleTimer1 = 0;
	fKeyParticleTimer2 = 0;
	fKeyParticleTimer3 = 0;
}

void Player::UseKey()
{
	bHasKey = false;
}

void Player::UsePowerup()
{
	bHasBomb = false;
}

void Player::ObtainBomb()
{
	bHasBomb = true;
	m_PowerupParticleSystem1.emitParticles(getCentre(), fSpeed, Color::Blue);
	m_PowerupParticleSystem2.emitParticles(getCentre(), fSpeed, Color::Blue);
	m_PowerupParticleSystem3.emitParticles(getCentre(), fSpeed, Color::Blue);
	fPowerupParticleTimer1 = 0;
	fPowerupParticleTimer2 = 0;
	fPowerupParticleTimer3 = 0;
}

void Player::ObtainShield()
{
	bHasShield = true;
}

void Player::KeyParticles(float dt)
{
	
	if (m_KeyParticleSystem1.running())
	{
		m_KeyParticleSystem1.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fKeyParticleTimer1 += dt;
		if (fKeyParticleTimer1 > 0.5)
		{
			if (bHasKey)
				m_KeyParticleSystem1.emitParticles(getCentre(), fSpeed, Color::Red);
			fKeyParticleTimer1 = 0;
		}
	}

	if (m_KeyParticleSystem2.running())
	{
		m_KeyParticleSystem2.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fKeyParticleTimer2 += dt;
		if (fKeyParticleTimer2 > 0.7)
		{
			if (bHasKey)
				m_KeyParticleSystem2.emitParticles(getCentre(), fSpeed, Color::Red);
			fKeyParticleTimer2 = 0;
		}
	}

	if (m_KeyParticleSystem3.running())
	{
		m_KeyParticleSystem3.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fKeyParticleTimer2 += dt;
		if (fKeyParticleTimer3 > 2.6)
		{
			if (bHasKey)
				m_KeyParticleSystem3.emitParticles(getCentre(), fSpeed, Color::Red);
			fKeyParticleTimer3 = 0;
		}
	}
}


void Player::PowerUpParticles(float dt)
{
	if (m_PowerupParticleSystem1.running())
	{
		m_PowerupParticleSystem1.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fPowerupParticleTimer1 += dt;
		if (fPowerupParticleTimer1 > 2.5)
		{
			if (bHasBomb)
				m_PowerupParticleSystem1.emitParticles(getCentre(), fSpeed, Color::Blue);
			fPowerupParticleTimer1 = 0;
		}
	}

	if (m_PowerupParticleSystem2.running())
	{
		m_PowerupParticleSystem2.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fPowerupParticleTimer2 += dt;
		if (fPowerupParticleTimer2 > 2.7)
		{
			if (bHasBomb)
				m_PowerupParticleSystem2.emitParticles(getCentre(), fSpeed, Color::Blue);
			fPowerupParticleTimer2 = 0;
		}
	}

	if (m_PowerupParticleSystem3.running())
	{
		m_PowerupParticleSystem3.update(dt, Vector2f(fSpeed.x * .95, fSpeed.y * .95));
		fPowerupParticleTimer3 += dt;
		if (fPowerupParticleTimer3 > 0.6)
		{
			if (bHasBomb)
				m_PowerupParticleSystem3.emitParticles(getCentre(), fSpeed, Color::Blue);
			fPowerupParticleTimer3 = 0;
		}
	}
}