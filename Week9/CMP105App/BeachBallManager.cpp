#include "BeachBallManager.h"

BeachBallManager::BeachBallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	ballCount = 0;
	int maxBalls = 5;
	for(int i = 0; i < maxBalls; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BeachBallManager::~BeachBallManager()
{

}

void BeachBallManager::update(float dt)
{
	//call update on all ALIVE balls
	for(int i = 0; i < balls.size(); i++)
	{
		if(balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void BeachBallManager::spawn()
{
	for(int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
			ballCount++;
		}
		if (ballCount >= maxBalls)
		{
		
		}
	}
}

void BeachBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].getPosition().x < -100)
		{
			balls[i].setAlive(false);
			ballCount--;
		}

		if (balls[i].getPosition().x > 800)
		{
			balls[i].setAlive(false);
			ballCount--;
		}

		if (balls[i].getPosition().y < -100)
		{
			balls[i].setAlive(false);
			ballCount--;
		}

		if (balls[i].getPosition().y > 600)
		{
			balls[i].setAlive(false);
			ballCount--;
		}
	}	
}

void BeachBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}