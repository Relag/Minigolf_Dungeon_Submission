
#include "Engine.h"

void Engine::loadLevel()
{
	
		// Delete the previously allocated memory
		for (int i = 0; i < m_LM.getLevelSize().y; ++i)
		{
			delete[] m_ArrayLevel[i];


		}
		delete[] m_ArrayLevel;

		// Load the next 2d array with the map for the level
		// And repopulate the vertex array as well
		m_ArrayLevel = m_LM.nextLevel(m_VALevel);

		//Spawn Powerups for Level
		loadObjects();

		// Spawn Player  
		m_Ball.Spawn(m_LM.getStartPoint());
		pm_Ball = &m_Ball;


		// Make sure this code isn't run again
		m_nextLevelNeeded = false;
	
}

void Engine::loadObjects() {

	//Clears the powerup list
	powerupList.clear();
	wallList.clear();
	GopherList.clear();
	WindmillList.clear();
	
	//Create Pointers to create the objects
	Powerup* PUP;
	Wall* wall;
	BreakableWall* BWall;
	Gopher* pGopher;
	Windmill* Wmill;

	// Get the current level from Level Manager
	int iCurrentLevel = m_LM.getCurrentLevel();

	switch (iCurrentLevel)
	{
	case 1:
		
		PUP = new Powerup(410, 130, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(410, 170, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(370, 130, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(130, 250, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(130, 290, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(170, 290, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(270, 190, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(270, 230, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(270, 150, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(270, 270, "Powerup", Coin);
		powerupList.push_back(PUP);
		break;
	case 2: 
		PUP = new Powerup(270, 270, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(350, 270, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(310, 310, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(390, 310, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(430, 270, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(130, 125, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(170, 125, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(130, 165, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(450, 125, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(490, 125, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(450, 165, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(570, 205, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(570, 285, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(610, 245, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(650, 205, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(650, 285, "Powerup", Coin);
		powerupList.push_back(PUP);

		break;

	case 3: //3rd Level
		//powerup spawn
		PUP = new Powerup(530, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(610, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(570, 560, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(570, 640, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(570, 600, "Powerup", Key);
		powerupList.push_back(PUP);

		PUP = new Powerup(400, 190, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(380, 150, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(360, 190, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(440, 350, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(400, 350, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(360, 350, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(140, 310, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(140, 390, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(140, 350, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(600, 270, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(640, 310, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(600, 350, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(640, 390, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(600, 430, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(260, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(220, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(300, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(180, 600, "Powerup", Coin);
		powerupList.push_back(PUP);

		wall = new Door(160, 200);
		wallList.push_back(wall);
		break;
	case 4: // 2nd Level
		//powerups
		PUP = new Powerup(350, 155, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(300, 140, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(250, 155, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(150, 220, "Powerup", Key);
		powerupList.push_back(PUP);
		PUP = new Powerup(160, 400, "Powerup", Bomb);
		powerupList.push_back(PUP);

		PUP = new Powerup(480, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(520, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(560, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(500, 330, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(540, 330, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(520, 290, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(270, 270, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(230, 310, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(190, 350, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(680, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(720, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(760, 420, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(880, 160, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(720, 160, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(680, 160, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(640, 160, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(840, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(880, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(760, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(720, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(680, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(640, 120, "Powerup", Coin);
		powerupList.push_back(PUP);
		//walls
		wall = new Door(320, 440);
		wallList.push_back(wall);
		BWall = new BreakableWall(600, 280);
		wallList.push_back(BWall);
		break;

	case 5: //5th level
		wall = new Door(280, 400);
		wallList.push_back(wall);

		wall = new Door(1120, 320);
		wallList.push_back(wall);

		BWall = new BreakableWall(1120, 600);
		wallList.push_back(BWall);

		Wmill = new Windmill(130, 360);
		WindmillList.push_back(Wmill);

		Wmill = new Windmill(540, 600);
		WindmillList.push_back(Wmill);

		pGopher = new Gopher(880, 580, Updown, 30);
		GopherList.push_back(pGopher);

		pGopher = new Gopher(320, 280, LeftRight, 30);
		GopherList.push_back(pGopher);

		pGopher = new Gopher(1160, 320, Updown, 30);
		GopherList.push_back(pGopher);

		pGopher = new Gopher(1240, 375, Updown, 30);
		GopherList.push_back(pGopher);

		pGopher = new Gopher(1240, 200, Updown, 30);
		GopherList.push_back(pGopher);

		PUP = new Powerup(240,140, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(280, 140, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(320, 140, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(360, 140, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(170, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(170, 380, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(130, 400, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(210, 400, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(420,420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(460, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(500, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(560, 460, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(560, 500, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(560, 540, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(810, 420, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(750, 460, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(720, 500, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(720, 540, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(860, 460, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(890, 500, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(890, 540, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(1040, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1080, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1160, 600, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1200, 600, "Powerup", Coin);
		powerupList.push_back(PUP);

		Wmill = new Windmill(1420, 300);
		WindmillList.push_back(Wmill);

		PUP = new Powerup(1420, 250, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1420, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1380, 250, "Powerup", Coin);
		powerupList.push_back(PUP);	
		PUP = new Powerup(1380, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 250, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 370, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 410, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 450, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 490, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(890, 280, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(890, 320, "Powerup", Shield);
		powerupList.push_back(PUP);
		PUP = new Powerup(890, 360, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(850, 320, "Powerup", Coin);
		powerupList.push_back(PUP);
		PUP = new Powerup(930, 320, "Powerup", Coin);
		powerupList.push_back(PUP);

		PUP = new Powerup(300, 280, "Powerup", Key);
		powerupList.push_back(PUP);
		PUP = new Powerup(1460, 160, "Powerup", Key);
		powerupList.push_back(PUP);
		PUP = new Powerup(280, 540, "Powerup", Bomb);
		powerupList.push_back(PUP);

		break;
	default:
		break;
	}

}