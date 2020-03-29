#include "NewBallManager.h"

NewBallManager::NewBallManager()
{
	spawnPoint = sf::Vector2f(0, -100);
	texture.loadFromFile("gfx/Mushroom.png");

	for(int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

NewBallManager::~NewBallManager()
{

}

void NewBallManager::update(float dt)
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

void NewBallManager::spawn()
{
	for(int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, 100);
			balls[i].setPosition(sf::Vector2f(rand() % 800, -100));
			return;
		}

	}
}

void NewBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].getPosition().y > 600)
		{
			balls[i].setAlive(false);
		}
	}
}

void NewBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}
