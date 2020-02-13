#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Zombie.h"
#include "Mario.h"
#include "Player.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//Game Objects
	Zombie theMostAmazingAndIncredibleZombie;
	sf::Texture zombieTex;

	Mario mario;
	sf::Texture marioTex;

	Player player;
	sf::Texture playerTex;
};