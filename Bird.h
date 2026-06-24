#pragma once
#include "Entity.h"
class Bird : public Entity{
public:
	Bird();
	~Bird() override;

	void Initialize(Vector3 startPos) override;
	void AIUpdate();
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

private:
	int birdHandles_[2] = { 0, 0 };
	int kTimer = 10;
};

