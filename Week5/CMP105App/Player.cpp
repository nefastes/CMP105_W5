#include "Player.h"
Player::Player()
{

}

Player::~Player()
{

}

void Player::update(float dt)
{

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right) || input->isKeyDown(sf::Keyboard::D))
	{
		//walk

	}
	else if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::A))
	{
		//walk but reversed

	}
	else
	{
		//idle

	}
}