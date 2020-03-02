#include "Engine.h"
#include "Tutorial.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::draw()
{
	//Create all of the Textures and Splash
	menu_tex = TextureHolder::GetTexture("graphics/main_menu_tex.png");
	menu_splash.setTexture(menu_tex);
	menu_splash.setPosition(20, 100);

	levelSelect_tex = TextureHolder::GetTexture("graphics/splash_bg.png");
	levelSelect_splash.setTexture(levelSelect_tex);
	levelSelect_splash.setPosition(20, 100);

	end_tex = TextureHolder::GetTexture("graphics/end_screen_tex.png");
	end_splash.setTexture(end_tex);
	end_splash.setPosition(20, 100);


	lead_text = TextureHolder::GetTexture("graphics/splash_bg.png");
	leaderboard.setTexture(lead_text);
	leaderboard.setPosition(20, 100);

	instruct_text = TextureHolder::GetTexture("graphics/InstructionBackground.png");
	Instructions.setTexture(instruct_text);
	Instructions.setPosition(20, 100);


	detail_text = TextureHolder::GetTexture("graphics/splash_bg.png");
	detailscreen.setTexture(detail_text);
	detailscreen.setPosition(20,100);

	// Draw the Menue Screen
	if (State == state::MENU)
	{
		m_Window.clear();
		m_Window.setView(m_MenuView);
		m_Window.draw(menu_splash);

		// font type for menu
		Font font;
		font.loadFromFile("fonts/Enchanted Land.otf");

		// Text options for the user to choose an option

		Text titleText;
		titleText.setFont(font);
		titleText.setCharacterSize(80); ///enlarge title
		titleText.setFillColor(Color::Black);
		titleText.setPosition(460, 280); //keep this for game title on large tile
		stringstream titleStream;
		titleStream << "Mini-Golf Dungeon" << endl;

		Text menuText;
		menuText.setFont(font);
		menuText.setCharacterSize(30); ///enlarge title
		menuText.setFillColor(Color::Black);
		menuText.setPosition(580, 460); //keep this for game title on large tile
		stringstream menuStream;
		menuStream <<
			"\n" <<
			"1 -PLAY GAME" <<

			"\t\n 2 -INSTRUCTIONS" <<

			"\t\n 3 -LEADERBOARDS" <<

			"\t\n 4 -QUIT GAME" <<

			"\t \n 0 -LEVELS";

		menuText.setString(menuStream.str());
		titleText.setString(titleStream.str());
		m_Window.draw(titleText);
		m_Window.draw(menuText);
		input();
		MenuInput();
	}

	// Draw the Leaderboard
	if (State == state::LEADERBOARD)
	{

		m_Window.clear();
		m_Window.setView(m_LeaderView);
		m_Window.draw(leaderboard);
		// more to be done here...
		RevertBack();

	}

	// Draw the Instuctions Screen
	if (State == state::INSTRUCTIONS)
	{
		
		//Create a tutorial object that contains all tutorial slides.
		Tutorial tutorial(m_Window.getSize().x, m_Window.getSize().y);
		Clock clock;
		//Iterate through each slide on the tutorial and draw it to screen.
		while (State == state::INSTRUCTIONS)
		{
			m_Window.clear();
			dt = clock.restart();
			//tutorial->Update(dt.asSeconds(), m_Window);
			m_Window.draw(tutorial.Update(dt.asSeconds(), m_Window));

			m_Window.display();
			RevertBack();
		}
		while (m_Window.pollEvent(event))
		{
			//Do nothing, just get rid of events.
		}
	}
	
	// Draw the Game Sceen
	if (State == state::PLAYING)
	{
		m_Playing = true;
		m_Window.clear();
		m_Window.setView(m_MainView);
		//.update(dtAsSeconds);

		 // Draw the Level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw the Walls
		for (list<Wall*>::iterator iter = wallList.begin(); iter != wallList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				m_Window.draw((*iter)->GetSprite());
			}
		}

		//Draw the Windmills
		for (list<Windmill*>::iterator iter = WindmillList.begin(); iter != WindmillList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				m_Window.draw((*iter)->Animate());
			}
		}

		//Draw the Powerups
		for (list<Powerup*>::iterator iter = powerupList.begin(); iter != powerupList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				m_Window.draw((*iter)->GetSprite());
			}
		}

		//Draw the Gophers
		for (list<Gopher*>::iterator iter = GopherList.begin(); iter != GopherList.end(); iter++)
		{
			if (*iter != nullptr)
			{
				m_Window.draw((*iter)->GetSprite());
			}
		}

		m_Window.draw(m_Ball.GetSprite());
		//Only draw the aim line if the ball is stopped.
		if (m_Ball.GetSpeed().x + m_Ball.GetSpeed().y == 0)
		{
			m_Window.draw(m_Ball.direction);
			m_Window.draw(m_Ball.getPowerBar());
			m_Window.draw(m_Ball.powerBarOutline);
		}

		if (m_Ball.m_KeyParticleSystem1.running())
		{
			m_Window.draw(m_Ball.m_KeyParticleSystem1);
		}

		if (m_Ball.m_KeyParticleSystem2.running())
		{
			m_Window.draw(m_Ball.m_KeyParticleSystem2);
		}

		if (m_Ball.m_KeyParticleSystem3.running())
		{
			m_Window.draw(m_Ball.m_KeyParticleSystem3);
		}

		if (m_Ball.m_PowerupParticleSystem1.running())
		{
			m_Window.draw(m_Ball.m_PowerupParticleSystem1);
		}

		if (m_Ball.m_PowerupParticleSystem2.running())
		{
			m_Window.draw(m_Ball.m_PowerupParticleSystem2);
		}

		if (m_Ball.m_PowerupParticleSystem3.running())
		{
			m_Window.draw(m_Ball.m_PowerupParticleSystem3);
		}

		// Draw the HUD
		// Switch to m_HudView

		m_Window.setView(m_HudView);
		m_Window.draw(m_Hud.getExit());
		m_Window.draw(m_Hud.getPaused());
		m_Window.draw(m_Hud.getLevel());
		m_Window.draw(m_Hud.getScore());
		m_Window.draw(m_Hud.getShotCount());
		m_Window.draw(m_Hud.getPowerup());

		// Paused
		Pause();

		//In - Game Exiting option
		inGameExit();
	}

	//Draw the Level Select Screen
	if (State == state::LEVEL_SELECT) 
	{

		
		m_Window.clear();
		m_Window.setView(m_MenuView);
		m_Window.draw(levelSelect_splash);

		Font font;
		font.loadFromFile("fonts/Enchanted Land.otf");

		Text menuText;
		menuText.setFont(font);
		menuText.setCharacterSize(100); //Determin size of text displayed
		menuText.setFillColor(Color::Black);
		menuText.setPosition(580, 130); // Position of the text
		stringstream menuStream;
		menuStream <<
			"\n" <<
			"1 - [Level 1]" <<

			"\t\n2 - [Level 2]" <<

			"\t\n3 - [Level 3]" <<

			"\t\n4 - [Level 4]";

		menuText.setString(menuStream.str());

		m_Window.draw(menuText);

		LevelSelectInput();
	}

	// Draw the Victory Screen
	if (State == state::END_SCREEN) 
	{

		m_Window.clear();
		m_Window.setView(m_MenuView);
		m_Window.draw(end_splash);

		Font font;
		font.loadFromFile("fonts/Enchanted Land.otf");

		Text menuText;
		menuText.setFont(font);
		menuText.setCharacterSize(75); ///enlarge title
		menuText.setFillColor(Color::Black);
		menuText.setPosition(110, 430); //keep this for game title on large tile
		stringstream menuStream;
		menuStream << "Congratulations, You beat the dungeon! \n"
				   << "\t\t\t\t\tYour Score is : " << m_Ball.GetScore();
			

		menuText.setString(menuStream.str());

		m_Window.draw(menuText);

		LevelSelectInput();

	}

	// Draw the Details screen
	if (State == state::DETAILS)
	{
		m_Window.setView(m_DetailsView);
		m_Window.draw(detailscreen);
	}

	// Draw the Pause
	if (State == state::PAUSED)
	{

		//m_Window.setView(m_HudView);
		m_Window.draw(m_Hud.getMessage());
		Pause();
	}


	m_Window.display();
	// Show everything we have just drawn
}
