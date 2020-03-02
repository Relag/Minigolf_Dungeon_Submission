#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Particle
{
private:
	Vector2f m_Position;
	Vector2f m_Velocity;

public:
	Particle(Vector2f direction);

	void update(float dt, Vector2f speed);

	void setPosition(Vector2f position);

	Vector2f getPosition();
};
