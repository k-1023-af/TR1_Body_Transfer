#pragma once
#include "Entity.h"

using namespace KamataEngine;

class Rocket : public Entity
{
public:
	Rocket();
	~Rocket() override;
	void Initialize(Vector3 startPos) override;
	void Update(char* keys) override;
	void Draw(char* keys) override;

private:
	float gravity_;
	float acceleration_;
};