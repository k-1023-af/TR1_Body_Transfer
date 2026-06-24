#pragma once
#include "Entity.h"

using namespace KamataEngine;

class Player : public Entity
{
public:
	Player();
	~Player() override;
	void Initialize(Vector3 startPos = {100.0f, 100.0f, 0.0f}) override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

	void SetTransform(const Vector3& newPos);

private:
	float jumpHeight_;
	int playerHandle_;
};

