#pragma once
#include "Entity.h"

using namespace KamataEngine;

class Rocket : public Entity
{
public:
	Rocket();
	~Rocket() override;
	void Initialize(Vector3 startPos) override;
	void AIUpdate();
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

private:
	int rocketHandles_[2] = {
	rocketHandles_[0],
	rocketHandles_[1],
	};
};