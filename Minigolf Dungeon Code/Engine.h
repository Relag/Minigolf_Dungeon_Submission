#ifndef ENGINE_H
#define ENGINE_H
#include "Player.h"
#include "Powerup.h"
#include "Windmill.h"
#include "Wall.h"
#include "SoundManager.h"
#include "LevelManager.h"
#include "TextureHolder.h"
#include "Hud.h"
#include "Door.h"
#include "BreakableWall.h"
#include "Gopher.h"

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML/Network.hpp>
#include <SFML\System.hpp>
#include <sstream>

#include <string>
#include <list>
#include <iostream>
using namespace sf;
using namespace std;


class Engine
{
private:
	TextureHolder textureHolder;
	RenderWindow m_Window;
	Vector2f resolution;


	Player m_Ball;
	Player* pm_Ball;

	// Test Items
	Wall* TestWall; // Test Wall
	Powerup* TestPowerup; // Test Powerup
	BreakableWall* TestBreakableWall;
	Gopher* EnemyGopher;
	SoundManager* m_SM = SoundManager::getInstance();
	Hud m_Hud;
	Powerup m_Pup;

	View m_minimapView;
	View m_HudView;
	View m_MenuView;
	View m_LeaderView;
	View m_InstructView;
	View m_MainView;
	View m_WinView;
	View m_DetailsView;

	Sprite menu_splash;
	Texture menu_tex;
	Sprite levelSelect_splash;
	Texture levelSelect_tex;
	Sprite end_splash;
	Texture end_tex;
	
	// Player Details
	Sprite detailscreen;
	Texture detail_text;

	// Leaderboards
	Sprite leaderboard;
	Texture lead_text;

	// Instructions
	Sprite Instructions;
	Texture instruct_text;

	list<Wall*> wallList;
	list<Powerup*> powerupList;
	list<Windmill*> WindmillList;
	list<Gopher*> GopherList;


	Sprite m_bg;
	Texture m_bgTex;

	bool m_Playing = false;

	bool m_nextLevelNeeded = true;

	//Score and Shot
	int m_iScore = 0;
	int m_iShot = 0;

	// A class to manage all the levels
    LevelManager m_LM;

	
	// The vertex array for the level design
	VertexArray m_VALevel;

	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	// Texture for the background and the level tiles
	Texture m_TextureTiles;

	Time m_GameTimeTotal;
	Clock clock;
	Time dt;

	Event event;


	// HUD Updates

	int m_hudframeUpdate = 0;
	int m_hudframeUpdatedTarget = 5;
	int m_framesPerSecond = 0;
	int m_frameCounter = 0;
	void input();
	void MenuInput(); // for menu use, choices
	void LevelSelectInput();
	void RevertBack(); // Reverts back to main menu
	void Next(); // next page
	void Previous(); // previous page
	void inGameExit(); // Exit from the levels
	void Pause(); // pause button for the game
	void draw();
	void update(Time dt);
	void loadLevel();
	void CheckCollision(Player* Ball);
	void CheckCollision(Gopher* Enemy);
	void loadObjects();
	void CheckAllCollisions();

public:
	Engine();
	enum class state { MENU, PLAYING, LEADERBOARD, PAUSED, INSTRUCTIONS, LEVEL_SELECT, END_SCREEN, DETAILS };

	// Initial state for the state enummerations 
	 state State;
	void run();

};

#endif