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
	float gravity_;
	float acceleration_;
	float width_;
	float height_;
	Vector2 screenPos_;

	int rocketHandles_[2] = {
	rocketHandles_[0],
	rocketHandles_[1],
	};
};