
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

using namespace sf;
using namespace std;

void ParticleSystem::init(int numParticles)
{
	m_Vertices.setPrimitiveType(Points);
	m_Vertices.resize(numParticles);

	// Create the particles

	for (int i = 0; i < numParticles; i++)
	{
		
			//Randomize the angle and movement of the particles
			srand(time(0) + i);
			float angle = (rand() % 360) * 3.14f / -180.f;
			float speed = 1.0 ;
			

			Vector2f direction;
			
				direction = Vector2f(cos(angle) * speed,
					sin(angle) * speed);

					m_Particles.push_back(Particle(direction));
			

	}

}

void ParticleSystem::update(float dt, Vector2f speed)
{
	m_Duration -= dt;
	vector<Particle>::iterator i;
	int currentVertex = 0;

	for (i = m_Particles.begin(); i != m_Particles.end(); i++)
	{
		// Move the particle
		(*i).update(dt, speed);

		// Update the vertex array
		m_Vertices[currentVertex].position = (*i).getPosition();

		// Move to the next vertex
		currentVertex++;
	}

	if (m_Duration < 0)
	{
		m_IsRunning = false;
	}

}

void ParticleSystem::emitParticles(Vector2f startPosition, Vector2f speed, Color color)
{
	
	m_IsRunning = true;
	m_Duration = 3;

	vector<Particle>::iterator i;
	int currentVertex = 0;

	for (i = m_Particles.begin(); i != m_Particles.end(); i++)
	{
		m_Vertices[currentVertex].color = color;
		Vector2f tempStartPosition;
		tempStartPosition.x = startPosition.x + rand() % 12 - 6 - (speed.x / 50);
		tempStartPosition.y = startPosition.y + rand() % 12 - 6 - (speed.y / 50);
		(*i).setPosition(tempStartPosition);

		currentVertex++;
	}

}

void ParticleSystem::draw(RenderTarget& target, RenderStates states) const
{
	
	target.draw(m_Vertices, states);
}

bool ParticleSystem::running()
{
	return m_IsRunning;
}