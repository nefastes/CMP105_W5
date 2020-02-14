#include "Zombie.h"
Zombie::Zombie()
{
	//Setting up the walking animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	//Others
	isMoving = false;
}

Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{
	if(isMoving) walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
	{
		walk.setFlipped(false);
		move(velocity.x * dt, 0);
		isMoving = true;
	}
	else if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
	{
		walk.setFlipped(true);
		move(-velocity.x * dt, 0);
		isMoving = true;
	}
	else isMoving = false;
}