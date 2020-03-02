#include "Engine.h"

void Engine::CheckAllCollisions() {

	//Ensure that wallList contains walls
	if (!wallList.empty())
	{
		//Iterate through each wall in the list, check their Collide function.
		for (list<Wall*>::iterator iter = wallList.begin(); iter != wallList.end(); iter++)
		{
			if ((*iter)->Collide(m_Ball, m_GameTimeTotal, dt))
			{
				wallList.erase(iter);
				iter = wallList.begin();
				if (wallList.empty())
					break;
			}
		}
	}

	if (!WindmillList.empty())
	{
		//Iterate through each wall in the list, check their Collide function.
		for (list<Windmill*>::iterator iter = WindmillList.begin(); iter != WindmillList.end(); iter++)
		{
			if ((*iter)->Collide(m_Ball, m_GameTimeTotal, dt))
			{
				if (!m_Ball.GetShield())
				{
					m_Ball.UseShield();
				}
				else
				{
					m_Ball.LosePoints();
				}
			}

		}
	}


	if (!powerupList.empty())
	{
		//Iterate through each powerup in the list, check their Collide function.
		for (list<Powerup*>::iterator iter = powerupList.begin(); iter != powerupList.end(); iter++)
		{
			m_Ball.CheckCollision((*iter));

		}
	}


	if (!GopherList.empty())
	{
		//Iterate through each wall in the list, check their Collide function.
		for (list<Gopher*>::iterator iter = GopherList.begin(); iter != GopherList.end(); iter++)
		{
			if ((*iter)->Collide(m_Ball, m_GameTimeTotal, dt)) {
				//Reduce points
			}

		}
	}

}



void Engine::CheckCollision(Player* Ball) {

	if (m_Playing == true)
	{

		//Check Collision Here

		FloatRect Detect = Ball->GetPosition();

		//Constant for the ball size and the Wall size
		const int BALL_SIZE = 40;
		const int WALL_SIZE = 40;


		// Set the wall Size in a Float rect
		FloatRect tile;
		tile.width = WALL_SIZE;
		tile.height = WALL_SIZE;

		//Creates a small zone around the ball to check for collisions
		float startX = (float)(Detect.left / BALL_SIZE) - 1;
		float startY = (float)(Detect.top / BALL_SIZE) - 1;
		float endX = (float)(Detect.left / BALL_SIZE) + 1;
		float endY = (float)(Detect.top / BALL_SIZE) + 1;


		//Cycle though collisions around the ball
		for (int x = startX; x < endX; x++)
		{
			for (int y = startY; y < endY; y++)
			{
				//Fill in the Tile Position for collision check
				tile.left = (x * WALL_SIZE) - (WALL_SIZE / 2) + 7;
				tile.top = (y * WALL_SIZE) - (WALL_SIZE / 2) + 7;

				//Ensure enough time has passed since last collision.
				if (Ball->Collide(m_GameTimeTotal))
					if (m_ArrayLevel[y][x] == 7 || m_ArrayLevel[y][x] == 3 || m_ArrayLevel[y][x] == 4 || m_ArrayLevel[y][x] == 9 || m_ArrayLevel[y][x] == 6) // If the tile is a [Wall]
					{
						//Ball's collision
						Ball->CheckCollision(tile, dt, m_GameTimeTotal, m_ArrayLevel[y][x]);
					}

				else if (m_ArrayLevel[y][x] == 2) { // If the tile is an [Out of Bounds Tile]

					if (Ball->CheckCollisionTile(tile, 40)) {

						m_Ball.Spawn(m_LM.getStartPoint());
						m_ArrayLevel[y][x] == 0;

					}

				}
				else if (m_ArrayLevel[y][x] == 5) { // If the tile is a [sand tile]

					if (Ball->CheckCollisionTile(tile, 40)) {

						m_Ball.Speed(0.9965, 0.9965);
						//m_SM->playPlayerDamage();
					}

				}

				else if (m_ArrayLevel[y][x] == 8) { // If the tile is a [hole]

					//tile.left = (x * WALL_SIZE) + 18;
					//tile.top = (y * WALL_SIZE) + 18;

					if (Ball->CheckCollisionTile(tile, 40)) {

						m_Ball.scoreBonus();
						m_Ball.Speed(0, 0);
						m_SM->playNextLevel();
						m_Ball.Spawn(m_LM.getStartPoint());

						m_nextLevelNeeded = true;
	
					}
				}

			}
		}
		//Check time, and Handle potential collisions for walls.
		if (Ball->Collide(m_GameTimeTotal))
			Ball->HandleCollision(m_GameTimeTotal);
	}

}

void Engine::CheckCollision(Gopher* Enemy) {

	if (m_Playing == true)
	{

		//Check Collision Here

		FloatRect Detect = Enemy->GetPosition();

		//Constant for the ball size and the Wall size
		const int GOPHER_SIZE = 40;
		const int WALL_SIZE = 40;


		// Set the wall Size in a Float rect
		FloatRect tile;
		tile.width = WALL_SIZE;
		tile.height = WALL_SIZE;

		//Creates a small zone around the ball to check for collisions
		float startX = (float)(Detect.left / GOPHER_SIZE) - 1;
		float startY = (float)(Detect.top / GOPHER_SIZE) - 1;
		float endX = (float)(Detect.left / GOPHER_SIZE) + 1;
		float endY = (float)(Detect.top / GOPHER_SIZE) + 1;


		//Cycle though collisions around the ball
		for (int x = startX; x < endX; x++)
		{
			for (int y = startY; y < endY; y++)
			{
				//Fill in the Walls Position for collision check
				tile.left = (x * WALL_SIZE) - (WALL_SIZE / 2) + 7;
				tile.top = (y * WALL_SIZE) - (WALL_SIZE / 2) + 7;


				if (m_ArrayLevel[y][x] == 7 || m_ArrayLevel[y][x] == 3 || m_ArrayLevel[y][x] == 4 || m_ArrayLevel[y][x] == 9 || m_ArrayLevel[y][x] == 6) // If the tile is a [Wall]
				{
					Enemy->CheckCollisionTile(tile, 40);
				}

			}
		}

	}

}
