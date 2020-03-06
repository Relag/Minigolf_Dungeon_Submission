#include "Engine.h"
#include <time.h>

void Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
			m_Window.close();
	}
}

void Engine::MenuInput()
{
	while (m_Window.pollEvent(event))
	{


		if (event.key.code == Keyboard::Num1) // if option 1 is chosen, display the game from the current starting point
		{
			m_Window.clear();
			State = state::PLAYING;

		}
		else if (event.key.code == Keyboard::Num3) //if option 3 is chosen, display the leaderboard of the game data stored on the database
		{
			m_Window.clear();
			State = state::LEADERBOARD;

		}
		else if (event.key.code == Keyboard::Num2) // if option 2 is chosen, display the next view of the instuctions for the game. Gives the user info.
		{

			m_Window.clear();
			State = state::INSTRUCTIONS;

		}
		else if (event.key.code == Keyboard::Num4) // if option 4 is chosen, close the application by command of the user
		{
			m_Window.close();
		}
		else if (event.key.code == Keyboard::Num0) // if option 0 is chosen, display the level select screen to the user.
		{
			m_Window.clear();
			m_nextLevelNeeded = true;
			State = state::LEVEL_SELECT;
		}
	}
}

void Engine::LevelSelectInput()
{
	while (m_Window.pollEvent(event))
	{

		if (State != state::END_SCREEN) 
		{

			if (event.key.code == Keyboard::Num1) // if option 1 is chosen, display the game from the current starting point
			{
				//set level to level 1
				m_LM.m_CurrentLevel = 0;
				m_Window.clear();
				State = state::PLAYING;

			}
			else if (event.key.code == Keyboard::Num2) //if option 3 is chosen, display the leaderboard of the game data stored on the database
			{
				//set level to level 2
				m_LM.m_CurrentLevel = 1;
				m_Window.clear();
				State = state::PLAYING;

			}
			else if (event.key.code == Keyboard::Num3) // if option 2 is chosen, display the next view of the instuctions for the game. Gives the user info.
			{
				//set level to level 3
				m_LM.m_CurrentLevel = 2;
				m_Window.clear();
				State = state::PLAYING;

			}
			else if (event.key.code == Keyboard::Num4) // if option 4 is chosen, close the application by command of the user
			{
				//set level to level 4
				m_LM.m_CurrentLevel = 3;
				m_Window.clear();
				State = state::PLAYING;
			}
		}
		else 
		{
			State = state::MENU;
		}
	}
}

void Engine::RevertBack() // Reverting back from the leaderboards / instructions without the closing of the application
{
	if (Keyboard::isKeyPressed(Keyboard::BackSpace) || Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.clear();
		State = state::MENU;
		sleep(sf::milliseconds(100));
	}
}

void Engine::Next()
{
	// not in use
}

void Engine::Previous()
{
	// not in use
}

void Engine::inGameExit() // Exiting the game without the application closing and reverting to the main menu
{
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		m_Window.clear();
		m_Playing = false;
	    dt = clock.restart();
		State = state::MENU;
	}
}

void Engine::Pause()
{ // Start of the Pause function 

	if (Keyboard::isKeyPressed(Keyboard::Enter) && State == state::PLAYING)
	{
		
		State = state::PAUSED;
		sleep(sf::milliseconds(100));
	}

	else if (Keyboard::isKeyPressed(Keyboard::Enter) && State == state::PAUSED)
	{
		m_Window.clear();
		State = state::PLAYING;
		sleep(sf::milliseconds(100));
	}

} // End of the Pause function
