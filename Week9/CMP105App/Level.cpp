#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		manager.spawn();
		input->setKeyUp(sf::Keyboard::Space);
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		manager2.spawn();
		input->setKeyUp(sf::Keyboard::W);
	}
}

// Update game objects
void Level::update(float dt)
{
	manager.update(dt);
	manager2.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	manager.render(window);
	manager2.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}