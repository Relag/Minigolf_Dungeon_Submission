#ifndef ENTITY_H
#define	ENTITY_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{
public:

	Entity(int iX, int iY, string sSprite);
	Entity();
	void Spawn(int iX, int iY, string sSprite); // create an Entity
	void Destroy();

protected:
	int iX;
	int iY;
	string sSprite;



};

#endif