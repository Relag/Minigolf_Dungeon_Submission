#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
using namespace sf;
using namespace std;


class LevelManager
{
private:
	Vector2i m_LevelSize;
	Vector2f m_StartPoint;
	const int NUM_LEVELS = 5;

public:
	LevelManager();
	int m_CurrentLevel = 0;
	const int TILE_SIZE = 40;
	const int VERTS_IN_QUAD = 4;

	Vector2f getStartPoint();

	void SetCurrentLevel(int l) { m_CurrentLevel = (l - 1); }
	int** nextLevel(VertexArray& rVaLevel);

	Vector2i getLevelSize();

	int getCurrentLevel();

}; 

#endif
