#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombieTex.loadFromFile("gfx/animZombie.png");
	//DO NOT FORGET THIS FOLLOWING LINE DAMNIT
	theMostAmazingAndIncredibleZombie.setInput(input);
	theMostAmazingAndIncredibleZombie.setTexture(&zombieTex);
	theMostAmazingAndIncredibleZombie.setSize(sf::Vector2f(55,108));
	theMostAmazingAndIncredibleZombie.setOrigin(sf::Vector2f(theMostAmazingAndIncredibleZombie.getSize().x / 2, theMostAmazingAndIncredibleZombie.getSize().y / 2));
	theMostAmazingAndIncredibleZombie.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	theMostAmazingAndIncredibleZombie.setVelocity(sf::Vector2f(100.f, 0));

	marioTex.loadFromFile("gfx/MarioSheetT.png");
	mario.setInput(input);
	mario.setTexture(&marioTex);
	mario.setSize(sf::Vector2f(128,168));
	mario.setOrigin(sf::Vector2f(mario.getSize().x / 2, mario.getSize().y / 2));
	mario.setPosition(111, 111);
	mario.setVelocity(sf::Vector2f(100.f, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))		window->close();
	
	theMostAmazingAndIncredibleZombie.handleInput(dt);
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	theMostAmazingAndIncredibleZombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(theMostAmazingAndIncredibleZombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}