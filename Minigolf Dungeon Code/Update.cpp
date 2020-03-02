#include "Engine.h"


void Engine::update(Time dt)
{
	// Count the Frames
	/*m_frameCounter++;
	m_framesPerSecond += dt.asMilliseconds();

	if (m_framesPerSecond >= 1000) {
		std::cout << m_frameCounter << endl;
		m_frameCounter = 0;
		m_framesPerSecond = 0;
	}*/
	
	if (m_LM.m_CurrentLevel == 4 && m_nextLevelNeeded)
	{
		State = state::END_SCREEN;
	}
	else
	{
		if (m_nextLevelNeeded)
		{
			// Load a level
			loadLevel();
		}

		// Update the player 
		m_Ball.Update(dt, m_Window);

		// Update all the gophers
		for (list<Gopher*>::iterator iter = GopherList.begin(); iter != GopherList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				(*iter)->Move(m_Ball, dt, m_Window);
			}
		}

		// Check the Balls Colision
		if (pm_Ball != NULL)
		{
			CheckCollision(pm_Ball);
		}

		// Check the Gopher's Colision
		for (list<Gopher*>::iterator iter = GopherList.begin(); iter != GopherList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				CheckCollision((*iter));
			}
		}


		// Update the camera to center on the player
		m_MainView.setCenter(m_Ball.getCentre());



		// Updating the HUD
		m_hudframeUpdate++; // incrementing since the last update

		// Update the hud since when targeted hud frame is execeeded
		if (m_hudframeUpdate > m_hudframeUpdatedTarget)
		{
			stringstream level;
			stringstream score;
			stringstream shot;
			stringstream powerup;

			// Update the level txt
			level << "Level: " << m_LM.getCurrentLevel();
			m_Hud.setLevel(level.str());

			// Update the score txt
			score << "Score: " << (int)m_Ball.GetScore();
			m_Hud.setScore(score.str());


			// Update the score txt
			shot << "Shot Counter: " << (int)m_Ball.GetShotCounter();
			m_Hud.setShotCount(shot.str());


			// Update the powerup type txt
			powerup << "Power Up Type: " << m_Ball.getPowerUpName();
			m_Hud.setPowerUp(powerup.str());

		}
	}

}