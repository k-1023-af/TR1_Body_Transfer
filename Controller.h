#pragma once
#include "Entity.h"
#include "Player.h"
#include "Rocket.h"
#include "Bird.h"
#include <vector>

class Controller {
public:
	Controller();
	~Controller();
	void Initialize(KamataEngine::Camera* camera);
	void Update(char* keys, char* preKeys);
	void Draw();

	//Vector3 GetCameraPosition() const;
	//Vector2 GetCurrentVelocity() const;

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
};

