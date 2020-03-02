#pragma once
#include "TextureHolder.h"
#include "SoundManager.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <queue>


class Tutorial
{
private:
	Sprite currentImage;
	Sprite finalImage;
	queue<Texture> textureQueue;
	
	void AddSprite(string name);
	float TimeElapsed;
	SoundManager* m_SM = SoundManager::getInstance();
public:
	Tutorial(int x, int y);
	Sprite Update(float dt, RenderWindow& window);
	void Destroy();
	~Tutorial();
};

