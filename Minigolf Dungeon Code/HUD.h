#ifndef HUD_H
#define HUD_H
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Hud
{
protected:
	Font m_Font;
	Text m_StartText;
	Text m_exitText;
	Text m_pausedText;
	Text m_LevelText;
	Text m_ScoreText;
	Text m_ShotCountText;
	Text m_PowerupText;


public:
	Hud();

	Text getMessage();
	Text getExit();
	Text getPaused();
	Text getLevel();
	Text getScore();
	Text getShotCount();
	Text getPowerup();

	void setLevel(string text);
	void setScore(string text);
	void setShotCount(string text);
	void setPowerUp(string text);
	void setExit(string text);
	void setPaused(string text);
};
#endif