#include "Engine.h"

Engine::Engine()
{
	//Create the window
	resolution.x = VideoMode::getDesktopMode().width/2;
	resolution.y = VideoMode::getDesktopMode().height/2;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Minigolf Dungeon");

	m_MainView.setSize(resolution);
	
		/*The zoom function -
		  Using the zoom command, this will help give the effect that player will
		  only see a certain section of the map at any given time
		*/
		
	m_MainView.zoom(0.70f); // Main Zoom
	//m_MainView.zoom(2.0f); Developper Mode Zoom
	
	

	
	// Start with the menu state
	State = state::MENU;
	
	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture(
		"graphics/tile_sprite_sheet.png");

         
	
}

void Engine::run()
{
	 
	while (m_Window.isOpen())
	{
	
		//m_Window.draw(menu_splash);
		dt = clock.restart();

		// Update the total game time
		m_GameTimeTotal += dt;

		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Determine if game is Playing
		if (State == state::PLAYING)
			update(dt);
		
		//Draws all objects to the screen
		draw();

		//Detects the collision of all objects
		CheckAllCollisions();

	}
}


bool Player::CheckCollisionTile(FloatRect tile , int size)
{
	//Detects if a given wall intersects with the ball
	//Adjusts the x and y speeds accordingly.
	//Make sure you use ObtainKey and ObtainPowerup
	//This ensures that the particle system is created.
	tile.height = size;
	tile.width = size;

	bool bTopCol = tile.contains(fTop) || tile.contains(fBottom);
	bool bSideCol = tile.contains(fRight) || tile.contains(fLeft);

	if (bTopCol && bSideCol) {

		return true;

	}
	else
	{
		if (bTopCol)
		{
			return true;
		}

		if (bSideCol)
		{
			return true;
		}
	}

	return false;
}

void Player::CheckCollision(Powerup* power) {


	int type = -1;

	//Check the Collision between the Player and the Poweup
	if (power->PowerupRect().contains(fTop) ||
		power->PowerupRect().contains(fBottom))
	{
		//Returns the Powerup type
		type = power->ActivatePowerup();
	}
	if (power->PowerupRect().contains(fRight)
		|| power->PowerupRect().contains(fLeft))
	{
		//Returns the Powerup type
		type = power->ActivatePowerup();
		
	}

	/*  - 0 Shield
		- 1 Wall Breaker
		- 2 Points
		- 3 Key		*/

	switch (type)
	{
	case 0:
		// Give the Playe the Shield Powerup
		ObtainShield();
		break;
	case 1:
		// Give the Player the Wall Breaker Powerup
		ObtainBomb();
		break;
	case 2:
		// Increase the Player's score
		iScore += 50;
		break;
	case 3:
		// Gives the Player The Key Powerup
		ObtainKey();
		break;
	default:
		
		break;
	}


}

void Player::scoreBonus()
{
	// Determins how much score the player recieves 
	if(iShotCounter > 0 && iShotCounter <= 15)
	{
		iScore += 1000; // Between 0 & 15 Shots
	}
	else if (iShotCounter > 15 && iShotCounter <= 25)
	{
		iScore += 350; // Between 15 & 25 Shots
	}
	else if (iShotCounter > 25)
	{
		iScore += 200; // 25+ shots
	}
}

