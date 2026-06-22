#pragma once
#include "Entity.h"
class Bird : public Entity{
public:
	Bird();
	~Bird() override;

	void Initialize(Vector3 startPos) override;
	void Update(char* keys) override;
	void Draw(char* keys) override;

private:
	float speed_ = 3.5f;
};

