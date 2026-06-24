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
	float acceleration_;
	float gravity_;
	float width_;
	float height_;
	//
	//float speed_ = 4.0f;
	////float flapStrength_ = 8.0f;
	//
	//int birdHandles_[2] = {
	//	birdHandles_[0],
	//	birdHandles_[1],
	//};

	int birdHandles_[2] = { 0, 0 };
};

