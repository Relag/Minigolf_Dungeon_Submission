#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
private:

	static SoundManager* instance;
	SoundManager();

	//buffers
	SoundBuffer wallKnockBuffer;
	SoundBuffer playerDamageBuffer;
	SoundBuffer pickupBuffer;
	SoundBuffer levelBuffer;
	SoundBuffer stickyBuffer;
	SoundBuffer breakBuffer;
	SoundBuffer doorBuffer;
	SoundBuffer gopherHitBuffer;
	//sounds
	Sound damageSound;
	Sound wallKnockSound;
	Sound nextLevelSound;
	Sound pickupSound;
	Sound stickyColSound;
	Sound wallBreakSound;
	Sound doorOpenSound;
	Music tutorialMusic;
	Sound gopherHitSound;

	int next_sound = 1;

public:
	//Create universal instance of Soundmanager.
	static SoundManager* getInstance();
	
	void playWallKnock();
	void playNextLevel();
	void playPickupChime();
	void playPlayerDamage();
	void playStickyWall();
	void playBreakWall();
	void playOpenDoor();
	void playTutorialMusic();
	void stopTutorialMusic();
	void playGopherHit();
};

#endif