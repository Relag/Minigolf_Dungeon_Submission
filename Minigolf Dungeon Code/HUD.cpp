#include "Hud.h"
#include "LevelManager.h"

Hud::Hud()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Load the font
	m_Font.loadFromFile("fonts/Enchanted Land.otf");

	// Paused
	m_StartText.setFont(m_Font);
	m_StartText.setCharacterSize(100);                 
	m_StartText.setFillColor(Color::White);      // doesnt work
	m_StartText.setString(" \t Game Paused\n"
		"Press Enter when ready!");

	// Position the text - start
	FloatRect textRect = m_StartText.getLocalBounds();

	m_StartText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);

	m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);


	// Exit text
	m_exitText.setFont(m_Font);
	m_exitText.setCharacterSize(55);
	m_exitText.setFillColor(Color::Red);
	m_exitText.setPosition(25, 0);
	m_exitText.setString("Press Q key to exit");


	// paused text
	m_pausedText.setFont(m_Font);
	m_pausedText.setCharacterSize(55);
	m_pausedText.setFillColor(Color::Red);
	m_pausedText.setPosition(695,0);
	m_pausedText.setString("Press Enter to pause");


	// Level text
	m_LevelText.setFont(m_Font);
	m_LevelText.setCharacterSize(55);
	m_LevelText.setFillColor(Color::White);
	m_LevelText.setPosition(25,90);
	m_LevelText.setString("1");

	//Score text
	m_ScoreText.setFont(m_Font);
	m_ScoreText.setCharacterSize(55);
	m_ScoreText.setFillColor(Color::White);
	m_ScoreText.setPosition(25,150);
	m_ScoreText.setString("0");


	//shot count text
	m_ShotCountText.setFont(m_Font);
	m_ShotCountText.setCharacterSize(55);
	m_ShotCountText.setFillColor(Color::White);
	m_ShotCountText.setPosition(25, 220);
	m_ShotCountText.setString("0");

	//Power Up text
	m_PowerupText.setFont(m_Font);
	m_PowerupText.setCharacterSize(55);
	m_PowerupText.setFillColor(Color::White);
	m_PowerupText.setPosition(25, 280);
	m_PowerupText.setString("none");


}

Text Hud::getMessage()
{
	return m_StartText;
}

Text Hud::getExit()
{
	return m_exitText;
}

Text Hud::getPaused()
{
	return m_pausedText;
}

Text Hud::getLevel()
{
	return m_LevelText;
}

Text Hud::getScore()
{
	return m_ScoreText;
}

Text Hud::getShotCount()
{
	return m_ShotCountText;
}

Text Hud::getPowerup()
{
	return m_PowerupText;
}



void Hud::setLevel(string text)
{
	m_LevelText.setString(text);
}

void Hud::setScore(string text)
{
	m_ScoreText.setString(text);
}

void Hud::setShotCount(string text)
{
	m_ShotCountText.setString(text);
}

void Hud::setPowerUp(string text)
{
	m_PowerupText.setString(text);
}

void Hud::setExit(string text)
{
	m_exitText.setString(text);
}

void Hud::setPaused(string text)
{
	m_pausedText.setString(text);
}