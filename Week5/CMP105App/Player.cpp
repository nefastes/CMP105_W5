#include "Player.h"
Player::Player()
{
	//Walk
	walk.addFrame(sf::IntRect(0, 0, 64, 64));
	walk.addFrame(sf::IntRect(64, 0, 64, 64));
	walk.setFrameSpeed(1.f / 10.f);

	//Idle
	idle.addFrame(sf::IntRect(0, 0, 64, 64));
	idle.addFrame(sf::IntRect(128, 0, 64, 64));
	idle.setFrameSpeed(1.f / 10.f);

	//Spawn
	spawn.addFrame(sf::IntRect(0, 0, 64, 64));
	spawn.addFrame(sf::IntRect(0, 64, 64, 64));
	spawn.addFrame(sf::IntRect(64, 64, 64, 64));
	spawn.addFrame(sf::IntRect(0, 64, 64, 64));
	spawn.addFrame(sf::IntRect(0, 0, 64, 64));
	spawn.addFrame(sf::IntRect(128, 64, 64, 64));
	spawn.addFrame(sf::IntRect(0, 128, 64, 64));
	spawn.addFrame(sf::IntRect(64, 128, 64, 64));
	for (unsigned i = 0; i < 5; ++i)
	{
		spawn.addFrame(sf::IntRect(128, 128, 64, 64));
		spawn.addFrame(sf::IntRect(0, 192, 64, 64));
	}
	spawn.addFrame(sf::IntRect(64, 128, 64, 64));
	spawn.addFrame(sf::IntRect(0, 128, 64, 64));
	spawn.addFrame(sf::IntRect(128, 64, 64, 64));
	spawn.addFrame(sf::IntRect(0, 0, 64, 64));
	spawn.setFrameSpeed(1.f / 10.f);
	spawn.setLooping(false);
	spawn.setPlaying(false);

	//Others
	isMoving = false;
	hasSpawned = false;
}

Player::~Player()
{

}

void Player::update(float dt)
{
	if (!hasSpawned)
	{
		if (spawn.getPlaying())
		{
			spawn.animate(dt);
			setTextureRect(spawn.getCurrentFrame());
			if (spawn.getState()) hasSpawned = true;
		}
		else
		{
			setTextureRect(sf::IntRect(128, 192, 64, 64));
		}
	}
	else
	{
		if (isMoving)
		{
			walk.animate(dt);
			setTextureRect(walk.getCurrentFrame());
		}
		else
		{
			idle.animate(dt);
			setTextureRect(idle.getCurrentFrame());
		}
	}
}

void Player::handleInput(float dt)
{
	if (!hasSpawned)
	{
		if (input->isKeyDown(sf::Keyboard::F))
		{
			//spawn anim
			spawn.play();
		}
	}
	else
	{
		if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
		{
			//walk
			isMoving = true;
			move(velocity.x * dt, 0);
			walk.setFlipped(true);
			idle.setFlipped(true);
		}
		else if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
		{
			//walk but reversed
			isMoving = true;
			move(-velocity.x * dt, 0);
			walk.setFlipped(false);
			idle.setFlipped(false);
		}
		else
		{
			//idle
			isMoving = false;
		}
	}
}