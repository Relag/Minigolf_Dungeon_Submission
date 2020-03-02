#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager* SoundManager::instance = 0;

SoundManager* SoundManager::getInstance() 
{

	if (instance == 0) {

		instance = new SoundManager();

	}

	return instance;

}

SoundManager::SoundManager()
{
	//loading in sound files to buffers
	playerDamageBuffer.loadFromFile("audio/damage.wav");
	wallKnockBuffer.loadFromFile("audio/ball_knock.wav");
	levelBuffer.loadFromFile("audio/next_level.wav");
	pickupBuffer.loadFromFile("audio/pickup_chime.wav");
	stickyBuffer.loadFromFile("audio/sticky.wav");
	breakBuffer.loadFromFile("audio/wall_break.wav");
	doorBuffer.loadFromFile("audio/door_creak.wav");
	tutorialMusic.openFromFile("audio/Music/tutorial_music.wav");
	gopherHitBuffer.loadFromFile("audio/gopher_squeak.wav");

	//assign sounds to buffers
	damageSound.setBuffer(playerDamageBuffer);
	wallKnockSound.setBuffer(wallKnockBuffer);
	nextLevelSound.setBuffer(levelBuffer);
	pickupSound.setBuffer(pickupBuffer);
	stickyColSound.setBuffer(stickyBuffer);
	wallBreakSound.setBuffer(breakBuffer);
	doorOpenSound.setBuffer(doorBuffer);
	gopherHitSound.setBuffer(gopherHitBuffer);
}

void SoundManager::playWallKnock()
{
	wallKnockSound.setRelativeToListener(true);
	
	wallKnockSound.setPitch((rand() % 2) + 1);
	wallKnockSound.play();
}
void SoundManager::playPlayerDamage()
{
	damageSound.setRelativeToListener(true);
	damageSound.play();
}

void SoundManager::playPickupChime()
{
	pickupSound.setRelativeToListener(true);
	wallKnockSound.setPitch((rand() % 3) + 1);
	pickupSound.play();
}

void SoundManager::playNextLevel()
{
	nextLevelSound.setRelativeToListener(true);
	nextLevelSound.play();
}

void SoundManager::playStickyWall()
{
	stickyColSound.setRelativeToListener(true);
	stickyColSound.play();
}

void SoundManager::playBreakWall()
{
	wallBreakSound.setRelativeToListener(true);
	wallBreakSound.play();
}

void SoundManager::playOpenDoor()
{
	doorOpenSound.setRelativeToListener(true);
	doorOpenSound.play();
}

void SoundManager::playTutorialMusic()
{
	tutorialMusic.play();
}

void SoundManager::stopTutorialMusic()
{
	tutorialMusic.stop();
}

void SoundManager::playGopherHit()
{
	gopherHitSound.setRelativeToListener(true);
	wallKnockSound.setPitch((rand() % 2) + 1);
	gopherHitSound.play();
}