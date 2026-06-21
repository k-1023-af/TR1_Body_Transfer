#pragma once
#include "KamataEngine.h"
#include "Novice.h"
#include "Player.h"

using namespace KamataEngine;

class Controller {
public:
	Controller();
	~Controller();
	void Initialize(KamataEngine::Camera* camera);
	void Update(char* keys, char* preKeys);
	void Draw(char* keys/*, char* preKeys*/);

	

private:
	KamataEngine::Camera* camera_ = nullptr;
	Player* player_ = nullptr;

	enum Control {
		PLAYER,
		ROCKET,
		BIRD
	};
	Control controlling = PLAYER;
};

