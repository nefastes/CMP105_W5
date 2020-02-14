#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float dt) override;
	void handleInput(float dt) override;

private:
	Animation walk;
	Animation spawn;
	Animation idle;

	bool isMoving;
	bool hasSpawned;
};

