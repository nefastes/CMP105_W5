#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt) override;

private:
	Animation walk;
	Animation duck;
	Animation swim;

	bool isMoving;
	bool isDucking;
	bool isSwimming;
};

