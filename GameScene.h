#pragma once
#include "KamataEngine.h"
#include "Player.h"
#include "Controller.h"
#include "Novice.h"

class GameScene {
public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update(char* keys, char* preKeys);
	void Draw(char* keys);

private:
	Player* player_ = nullptr;

	Controller* controller_;

	KamataEngine::Camera* camera_ = nullptr;

};

