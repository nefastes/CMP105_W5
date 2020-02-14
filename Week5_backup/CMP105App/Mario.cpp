#include "Mario.h"
Mario::Mario()
{
	//Setup of the walk anim
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	//Setup of the swim anim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	//Setup of the duck anim
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);

	//Others
	isMoving = false;
	isDucking = false;
	isSwimming = false;
}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	if (isMoving)
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (isDucking)
	{
		duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());
	}
	if (isSwimming)
	{
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}
}

void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Down) || input->isKeyDown(sf::Keyboard::S))
	{
		isMoving = false;
		isSwimming = false;
		isDucking = true;
	}
	else if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
	{
		isMoving = true;
		isSwimming = false;
		isDucking = false;
		move(velocity.x * dt, 0);
		walk.setFlipped(false);
	}
	else if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
	{
		isMoving = true;
		isSwimming = false;
		isDucking = false;
		move(-velocity.x * dt, 0);
		walk.setFlipped(true);
	}
	else
	{
		isMoving = false;
		isDucking = false;
		isSwimming = true;
	}
}