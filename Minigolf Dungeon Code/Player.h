#ifndef PLAYER_H
#define	PLAYER_H
#include "Entity.h"
#include "TextureHolder.h"
#include "HUD.h"
#include "Powerup.h"
#include "ParticleSystem.h"
#include "SoundManager.h"

//using namespace sf;

class Player : public Entity
{
public:
	Player(int iX, int iY, string sSprite);
	Player();
	void Spawn(Vector2f startPoint);

	void Destroy();
	void Update(Time dt, Window &window);
	void Speed(float x, float y);
	void CheckCollision(FloatRect tile, Time dt, Time GameTimeTotal, int type);
	void ObtainKey();
	void ObtainBomb();
	void ObtainShield();
	void KeyParticles(float dt);
	void PowerUpParticles(float dt);
	void UseKey();
	void UsePowerup();
	void UseShield() { bHasShield = false; }
	void HandleInput(float dt, Window& window);
	void ResetShotCounter() { iShotCounter = 0; }
	void ResetCollideTime(Time TotalTime) { m_LastCollide = TotalTime; }
	void LosePoints() { iScore -= 100; }
	void HandleCollision(Time GametimeTotal);
	void scoreBonus();

	Vector2f GetTop() { return fTop; }
	Vector2f GetBottom() { return fBottom; }
	Vector2f GetLeft() { return fLeft; }
	Vector2f GetRight() { return fRight; }

	int GetScore();
	int GetShotCounter() { return iShotCounter; }

	bool Collide(Time timeCollide);
	bool CheckCollisionTile(FloatRect tile, int size);
	void CheckCollision(Powerup* power);
	bool GetKey() { return bHasKey; }
	bool GetBomb() { return bHasBomb; }
	bool GetShield() { return bHasShield; }
	string getPowerUpName();

	Vector2f getCentre();
	sf::VertexArray direction;
	//Can move to engine. Just didn't know if someone was working in that script or not.
	
	
	Sprite GetSprite() { return m_Sprite; }
	Vector2f GetSpeed() { return fSpeed; }
	FloatRect GetPosition();
	RectangleShape getPowerBar() { return powerBar; }
	VertexArray powerBarOutline;

	//Particle Systems for key effect
	ParticleSystem m_KeyParticleSystem1;
	ParticleSystem m_KeyParticleSystem2;
	ParticleSystem m_KeyParticleSystem3;
	//Particle Systems for Powerup effect
	ParticleSystem m_PowerupParticleSystem1;
	ParticleSystem m_PowerupParticleSystem2;
	ParticleSystem m_PowerupParticleSystem3;
	SoundManager* m_SM = SoundManager::getInstance();


protected:
	//TODO: Initialize member variables in constructor.
	int iScore;
	int iRadius;
	int iShotCounter;
	int iCollideTypeCardinal;
	int iCollideTypeDiagonal;

	float fPower;
	float fBarFill;
	float fKeyParticleTimer1;
	float fKeyParticleTimer2;
	float fKeyParticleTimer3;
	float fPowerupParticleTimer1;
	float fPowerupParticleTimer2;
	float fPowerupParticleTimer3;
	float dtAsSeconds;
	

	bool bInvincible;
	bool bHasBomb;
	bool bHasShield;
	bool bHasKey;
	bool bShooting;
	bool bGoingUp;
	bool bAiming;
	bool bTopHitbox;
	bool bBottomHitbox;
	bool bLeftHitbox;
	bool bRightHitbox;
	bool bTopRightHitbox;
	bool bTopLeftHitbox;
	bool bBottomLeftHitbox;
	bool bBottomRightHitbox;

	Time m_LastCollide;
	Sprite m_Sprite;
	Texture m_Texture;

	//Red bar that displays player's shot power
	RectangleShape powerBar;
	//Starting/max width of the ball
	float powerBarStartWidth = 80;
	//Width and height while shooting.
	float powerBarWidth = 80;
	float powerBarHeight = 10;
	
	//Coordinates used for collision detection.
	Vector2f fTop;
	Vector2f fBottom;
	Vector2f fLeft;
	Vector2f fRight;
	Vector2f fTopLeft;
	Vector2f fTopRight;
	Vector2f fBottomRight;
	Vector2f fBottomLeft;
	Vector2f fSpeed;
	Vector2f m_Position;
	
	Time GetLastHitTime();
	float fRotation;
	float fDiagonal; // Distance between centre and diagonal corners = fRadius / 0.707.
	void RotateLeft(float dt);
	void RotateRight(float dt);
	void Move(float power);
	void Shooting(float dt, Window &window);
	void ResetHitboxFlags();
	void HitStickyWall();
	void HitWall();
	

	Player(int iX, int iY, string sSprite, int iScore, int iSpeed, bool bInvincible, bool bHasPowerup, bool bHasKey);

};

#endif

