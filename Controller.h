#pragma once
#include "Entity.h"
#include "Player.h"
#include "Rocket.h"
#include "Bird.h"
#include <vector>

using namespace KamataEngine;

class Controller {
public:
	Controller();
	~Controller();
	void Initialize(KamataEngine::Camera* camera);
	void Update(char* keys, char* preKeys);
	void Draw(char* keys);

private:
	KamataEngine::Camera* camera_ = nullptr;
	Player* player_ = nullptr;
	Rocket* rocket_ = nullptr;

	std::vector<Bird*> birds_;
	int currentBirdIndex_ = 0;

	void SpawnBird(Vector3 startPos);

	enum Control {
		PLAYER,
		BIRD,
		ROCKET
	};
	Control controlling = PLAYER;

	Vector3 cameraOffset_ = { 0.0f, 50.0f, 0.0f };


};

